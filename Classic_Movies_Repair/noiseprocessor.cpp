#include "noiseprocessor.h"

NoiseProcessor::NoiseProcessor()
{
}

Mat NoiseProcessor::addSaltNoise(const Mat srcImage, int n)
{
    Mat dstImage = srcImage.clone();
    for (int k = 0; k < n; k++)
    {
        //随机取值行列
        int i = rand() % dstImage.rows;
        int j = rand() % dstImage.cols;
        //图像通道判定
        if (dstImage.channels() == 1)
        {
            dstImage.at<uchar>(i, j) = 255;       //盐噪声是白的，255是白的
        }
        else
        {
            //三通道
            //            dstImage.at<Vec3b>(i, j)[0] = 255;
            //            dstImage.at<Vec3b>(i, j)[1] = 255;
            //            dstImage.at<Vec3b>(i, j)[2] = 255;

            //四通道
            dstImage.at<Vec4b>(i, j)[0] = 255;
            dstImage.at<Vec4b>(i, j)[1] = 255;
            dstImage.at<Vec4b>(i, j)[2] = 255;
            dstImage.at<Vec4b>(i, j)[3] = 255;
        }
    }
    for (int k = 0; k < n; k++)
    {
        //随机取值行列
        int i = rand() % dstImage.rows;
        int j = rand() % dstImage.cols;
        //图像通道判定
        if (dstImage.channels() == 1)
        {
            dstImage.at<uchar>(i, j) = 0;     //椒噪声是黑的，0是黑的
        }
        else
        {
           // 三通道
//                        dstImage.at<Vec3b>(i, j)[0] = 0;
//                        dstImage.at<Vec3b>(i, j)[1] = 0;
//                        dstImage.at<Vec3b>(i, j)[2] = 0;

            //四通道
            dstImage.at<Vec4b>(i, j)[0] = 0;
            dstImage.at<Vec4b>(i, j)[1] = 0;
            dstImage.at<Vec4b>(i, j)[2] = 0;
            //第四通道是透明通道,变为0之后只有白点，没有黑点
//            dstImage.at<Vec4b>(i, j)[3] = 0;
        }
    }
    return dstImage;
}

//中值滤波消除椒盐噪声，平滑图像，
Mat NoiseProcessor::deleteSaltNoise(Mat &input)
{
    Mat result;
    medianBlur(input,result,5);//滤波模板的尺寸大小，必须是大于1的奇数，如3、5、7
    return result;
}

