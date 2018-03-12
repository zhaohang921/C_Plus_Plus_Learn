#pragma once

#ifndef VIDEOPROCESSOR_H
#define VIDEOPROCESSOR_H

#include"frameprocessor.h"

#include<string>
#include<vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<iomanip>
#include<sstream>

using namespace cv;
using namespace std;

class VideoProcessor
{


public:
    //VideoProcessor():callIt(true), delay(0), fnumber(0), stop(false), frameToStop(-1){}
    VideoProcessor();

    //设置回调函数
    void setFrameProcessor(void(*frameProcessingCallback)(Mat&, Mat&));
    //设置视频文件的名称
    bool setInput(String );
    //创建输入窗口
    void displayInput(String );
    //创建输出窗口
    void displayOutput(String wn);
    //不再显示处理后的帧
    void dontDisplay();
    //获取并处理序列帧
    void run();
    //停止运行
    void stopIt();
    //是否已停止
    bool isStopped();
    //是否开始了捕获设备
    bool isOpened();
    //设置帧间的延迟 0意味着在每帧都等待用户按键 负数意味着没有延迟
    void setDelay(int d);
    //得到下一帧 可能是视频文件或摄像头
    bool readNextFrame(Mat &frame);
    //需要调用回调函数
    void callProcess();
    //不需要调用回调函数
    void dontCallProcess();

    void stopAtFrameNo(long frame);
    //返回下一帧的帧数
    long getFrameNumber();
    int getFrameRate();
    //获得编码类型
    int getCodec(char codec[4]);
    //获得帧大小
    Size getFrameSize();

    //设置输出视频文件,默认使用输入视频相同的参数
    bool setOutput(const String &filename, int codec = 0, double framerate = 0.0, bool isColor = true);
    //输出帧 可能是视频文件或图像文件
    void writeNextFrame(Mat &frame);
    //设置输出为独立的图像文件 扩展名必须是".jpg" ".bmp"
    bool setOutput(const String &filename,//前缀
                   const String &ext,//后缀
                   int numberofDigits = 3,//数字位数
                   int startIndex = 0);


    void canny(Mat &input, Mat &output)
    {
        if (input.channels() == 3)//将彩色图像转为灰度图像
        {
            cvtColor(input, output, CV_BGR2GRAY);
        }
        Canny(output, output, 100, 200);//计算Canny边缘
        threshold(output, output, 128, 255, THRESH_BINARY_INV);//反转图像
    }
private:
    //视频捕捉对象
    VideoCapture capture;
    //每帧调用的回调函数
    void(*process)(Mat&, Mat&);
    //确定是否调用回调函数的bool变量
    bool callIt;
    //输入窗口的名称
    String windowNameInput;
    String windowNameOutput;
    //延迟
    int delay;
    //已处理的帧数
    long fnumber;
    //在该帧数停止
    long frameToStop;
    //是否停止处理
    bool stop;
    //opencv的写视频对象
    VideoWriter writer;
    //输出文件名称
    String outputFile;
    //输出图像的当前索引
    int currentIndex;
    //输出图像名称中的数字位数
    int digits;
    //输出图像的扩展名
    String extension;
    FrameProcessor *frameprocessor;
    //图像序列作为输入视频流
    vector<String> images;
};

#endif // VIDEOPROCESSOR_H
