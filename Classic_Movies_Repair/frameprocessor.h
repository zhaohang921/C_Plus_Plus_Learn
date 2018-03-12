#ifndef FRAMEPROCESSOR_H
#define FRAMEPROCESSOR_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

class FrameProcessor{
public:
    virtual void process(Mat &input, Mat &ouput);
};







#endif // FRAMEPROCESSOR_H
