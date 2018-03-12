#ifndef NOISEPROCESSOR_H
#define NOISEPROCESSOR_H

#include<string>
#include<vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include<random>

using namespace cv;
using namespace std;

class NoiseProcessor
{
public:
    NoiseProcessor();
    // 添加椒盐噪声
    Mat addSaltNoise(const Mat srcImage, int n);
    //中值滤波消除椒盐噪声，平滑图像，
    Mat deleteSaltNoise(Mat &input);



private:




};

#endif // NOISEPROCESSOR_H
