//opencv的库文件
#include"highgui.hpp"
#include"core.hpp"
#include"imgproc.hpp"

using namespace cv;

int main()
{
    Mat testimage=imread("D:/data/test/test067.png");
    imshow("test result",testimage);
    waitKey(0);

	return 0;
}

