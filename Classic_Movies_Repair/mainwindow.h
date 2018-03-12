#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/photo.hpp>
#include<qfile.h>
#include<qdebug.h>
#include<qfiledialog.h>
#include<qstring.h>
#include<qmessagebox.h>
#include<qscreen.h>
#include<qlabel.h>
#include<qbuffer.h>
#include<QtMultimedia/qmediaplayer.h>
#include<QtMultimediaWidgets/qvideowidget.h>
#include<string>

using namespace cv;
using namespace std;

#include"videoprocessor.h"
#include"noiseprocessor.h"
//#include"shake.h"
#include"dialog.h"
#include"imageprocessor.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void action_Open_Image_Slot();
    void action_Open_Film_Slot();
    void action_Save_Image_Slot();
    void action_Save_Film_Slot();
    void action_Recover_Image_Slot();
    void action_Add_Salt_Noise_Slot();
    void action_Delete_Salt_Noise_Slot();


public:

    String test_open();


    bool saveFile(const QString &filename);
    void show_resultImage();


private:
    Mat original_image;//作为原始的图片
    Mat image;  //当前Mat图片
    Mat resultMat;//处理之后的Mat图片
    QImage resultImage;//转换成QImage的结果图片,右边要显示的图片


public:
    String Video_Open_Path;//当前视频打开路径
    String Video_Save_Path;//处理完的结果视频保存路径




























};
#endif // MAINWINDOW_H
