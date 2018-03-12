#ifndef SPOT_H
#define SPOT_H
#include"opencv_header.h"

using namespace cv;

//using namespace std;

class Spot
{
//    friend void chuandi();

public:
    Spot();
    void onMouse(int event, int x, int y, int flag, void *param);
    //cv::Mat spotDelete(Mat &input, Mat &output);
    int spotDelete();


public:
    bool g_bDrawing = false;
    Point g_CurrPoint, g_OrgPoint;
    int g_nThick = 5, g_nBlue = 255, g_nGreen = 255, g_nRed = 255;
    int g_nImageOneValue = 49;
    Mat srcImage;
    Mat grayImage;
    Mat maskImage;


};

#endif // SPOT_H
