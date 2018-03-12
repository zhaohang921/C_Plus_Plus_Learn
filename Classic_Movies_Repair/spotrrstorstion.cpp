#include "spotrrstorstion.h"
#include "ui_spotrrstorstion.h"

SpotRrstorstion::SpotRrstorstion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpotRrstorstion)
{
    ui->setupUi(this);
}

SpotRrstorstion::~SpotRrstorstion()
{
    delete ui;
}

void SpotRrstorstion::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),
                                                    ".",tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));
    Mat origin_image=imread(fileName.toStdString());
   // namedWindow("original");
    //imshow("original",origin_image);
    //return origin_image;
    ori_image=origin_image.clone();
}

void next();
void save();
