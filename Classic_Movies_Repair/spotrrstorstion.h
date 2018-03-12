#ifndef SPOTRRSTORSTION_H
#define SPOTRRSTORSTION_H
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

#include <QWidget>

using namespace cv;
namespace Ui {
class SpotRrstorstion;
}

class SpotRrstorstion : public QWidget
{
    Q_OBJECT

public:
    explicit SpotRrstorstion(QWidget *parent = 0);
    ~SpotRrstorstion();

private:
    Ui::SpotRrstorstion *ui;

public slots:
     void open();
//    void next();
//    void save();

public:
    Mat ori_image;

};

#endif // SPOTRRSTORSTION_H
