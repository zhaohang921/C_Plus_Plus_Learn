#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QImage>
#include <QDebug>


using namespace cv;

//图像处理类，包含了图像处理的方法
class ImageProcessor
{
public:
    ImageProcessor();
    //测试用，读取一张图片并显示
    void test();

    //canny边缘检测
    void canny(Mat &input, Mat &output);
    //Mat转成QImage
    QImage cvMat2QImage(const cv::Mat& mat);
    //QImage转成Mat
    cv::Mat QImage2cvMat(QImage image);
    //消除图片中的斑点
    Mat spotDelete(Mat &input, Mat &output);




private:

};

#endif // IMAGEPROCESSOR_H
