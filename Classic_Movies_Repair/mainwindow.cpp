#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QImage defaultImg;
    defaultImg.load("./data/original_image/dolphin.jpeg");//把这张图片作为默认图片
    ui->origin_imagelabel->setPixmap(QPixmap::fromImage(defaultImg.scaled(ui->origin_imagelabel->size())));
    ImageProcessor imageprocessor;
    original_image=imageprocessor.QImage2cvMat(defaultImg).clone();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::action_Open_Image_Slot()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),
                                                    ".",tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));
    QImage img;
    if(fileName.isEmpty())
        return;
    else
    {
        if(!(img.load(fileName))) //加载图像
        {
            QMessageBox::information(this, tr("打开图像失败"),tr("打开图像失败!"));
            return;
        }      
        ui->origin_imagelabel->setPixmap(QPixmap::fromImage(img.scaled(ui->origin_imagelabel->size())));

//        ui->origin_imagelabel->resize(image.cols,image.rows);
//        ui->origin_imagelabel->setPixmap(QPixmap::fromImage(img));

    }
    ImageProcessor imageprocessor;
    image=imageprocessor.QImage2cvMat(img);
    //imshow("image",image);
    original_image=image.clone();
    //imshow("image2",original_image);

    //
}

String MainWindow::test_open()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),
                                                    ".",tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));
    return fileName.toStdString();
}

void MainWindow::action_Open_Film_Slot()
{
    QString path = QFileDialog::getOpenFileName(this, tr("选择视频"), ".", tr("Image Files(*.avi)"));//得到视频路径
    Video_Open_Path=path.toStdString();
    //shake(Video_Open_Path);


}

void MainWindow::action_Save_Image_Slot()
{
    QString fileName = QFileDialog::getSaveFileName(
                this, "保存图片",
                ".",
                "图片 (*.jpg *.bmp *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;所有文件(*.*)");
    if(!fileName.isEmpty())
    {
        saveFile(fileName);
    }
    else
    {
        return;
    }
}

bool MainWindow::saveFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this,tr("保存文件"),tr("无法保存文件 %1:\n%2").arg(filename).arg(file.errorString()));
        return false;
    }
    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);

    resultImage=ui->processd_imagelabel->pixmap()->toImage();
    //resultImage=cvMat2QImage(resultMat);
    resultImage.save(&buffer, "JPG");

    file.write(ba);
    QMessageBox::information(this,tr("保存文件"),tr("文件已保存至：\n%1").arg(filename));
    return true;
}

void MainWindow::action_Save_Film_Slot()
{


}

void MainWindow::action_Recover_Image_Slot()
{

}



void MainWindow::action_Add_Salt_Noise_Slot()
{
    //imshow("image1",image);
    //imshow("original_image",original_image);
    Mat currentimage=original_image.clone();


    //imshow("currentimage",currentimage);
    //cout<<currentimage.channels();
    Dialog dialog;
    dialog.exec();
    int n=dialog.getinput().toInt();
    //cout<<n<<endl;
    NoiseProcessor noiseprocessor;
    resultMat=noiseprocessor.addSaltNoise(currentimage,n);

    //imshow("resultMat",resultMat);
    show_resultImage();
    //imshow("Add_Salt_Noise_Result",resultMat);
}

void MainWindow::action_Delete_Salt_Noise_Slot()
{
    //中值滤波消除椒盐噪声，平滑图像，直接在结果图片上处理
    NoiseProcessor noiseprocessor;
    resultMat=noiseprocessor.deleteSaltNoise(resultMat);

    //medianBlur(resultMat,resultMat,5);
    show_resultImage();
}

void MainWindow::show_resultImage()
{
    ImageProcessor imageprocessor;
    resultImage=imageprocessor.cvMat2QImage(resultMat);
    //resultImage=cvMat2QImage(resultMat);
    ui->processd_imagelabel->setPixmap(QPixmap::fromImage(resultImage.scaled(ui->processd_imagelabel->size())));
}

































