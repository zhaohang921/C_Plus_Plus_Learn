#include "videoprocessor.h"

VideoProcessor::VideoProcessor():callIt(true), delay(0), fnumber(0), stop(false), frameToStop(-1)
{

}

//设置回调函数
void VideoProcessor::setFrameProcessor(
    void(*frameProcessingCallback)(Mat&, Mat&)){
    process = frameProcessingCallback;
}

//设置视频文件的名称
bool VideoProcessor::setInput(String filename){
    fnumber = 0;
    //释放之前打开过的资源
    capture.release();
    //打开视频文件
    return capture.open(filename);
}

//创建输入窗口
void VideoProcessor::displayInput(String wn){
    windowNameInput = wn;
    namedWindow(windowNameInput);
}

//创建输出窗口
void VideoProcessor::displayOutput(String wn){
    windowNameOutput = wn;
    namedWindow(windowNameOutput);
}

//不再显示处理后的帧
void VideoProcessor::dontDisplay(){
    destroyWindow(windowNameInput);
    destroyWindow(windowNameOutput);
    windowNameInput.clear();
    windowNameOutput.clear();
}

//获取并处理序列帧
void VideoProcessor::run(){
    //当前帧
    Mat frame;
    //输出帧
    Mat output;
    //打开失败时
    if (!isOpened())return;
    stop = false;
    while (!isStopped())
    {
        //读取下一帧
        if (!readNextFrame(frame))break;
        //显示输出帧
        if (windowNameInput.length() != 0)
            imshow(windowNameInput, frame);
        //调用处理函数
        if (callIt){
            //处理当前帧
            if (process)
                process(frame, output);
            else if (frameprocessor)
                frameprocessor->process(frame, output);
            //增加帧数
            fnumber++;
        }
        else
        {
            output = frame;
        }
        //输出图像序列
        if (outputFile.length() != 0)
            writeNextFrame(output);
        //显示输出帧
        if (windowNameOutput.length() != 0)
            imshow(windowNameOutput, output);
        //引入延迟
        if (delay >= 0 && waitKey(delay) >= 0)
            stopIt();
        //检查是否需要停止运行
        if (frameToStop >= 0 && getFrameNumber() == frameToStop)
            stopIt();
    }
}

//停止运行
void VideoProcessor::stopIt(){
    stop = true;
}

//是否已停止
bool VideoProcessor::isStopped(){
    return stop;
}

//是否开始了捕获设备
bool VideoProcessor::isOpened(){
    return capture.isOpened();
}

//设置帧间的延迟 0意味着在每帧都等待用户按键 负数意味着没有延迟
void VideoProcessor::setDelay(int d){
    delay = d;
}

//得到下一帧 可能是视频文件或摄像头
bool VideoProcessor::readNextFrame(Mat &frame){
    return capture.read(frame);
}

//需要调用回调函数
void VideoProcessor::callProcess(){
    callIt = true;
}

//不需要调用回调函数
void VideoProcessor::dontCallProcess(){
    callIt = false;
}

void VideoProcessor::stopAtFrameNo(long frame){
    frameToStop = frame;
}

//返回下一帧的帧数
long VideoProcessor::getFrameNumber(){
    //得到捕获设备的信息
    long fnumber = static_cast<long>(capture.get(CV_CAP_PROP_POS_FRAMES));
    return fnumber;
}

int VideoProcessor::getFrameRate(){
    return capture.get(CV_CAP_PROP_FPS);
}

//获得编码类型
int VideoProcessor::getCodec(char codec[4]) {
    if (images.size() != 0)
        return -1;
    union { // 数据结构4-char
        int value;
        char code[4];
    } returned;
    //获得编码值
    returned.value = static_cast<int>(
        capture.get(CV_CAP_PROP_FOURCC));
    // get the 4 characters
    codec[0] = returned.code[0];
    codec[1] = returned.code[1];
    codec[2] = returned.code[2];
    codec[3] = returned.code[3];
    return returned.value;
}

//获得帧大小
Size VideoProcessor::getFrameSize() {
    if (images.size() == 0) {
        // 从视频流获得帧大小
        int w = static_cast<int>(capture.get(CV_CAP_PROP_FRAME_WIDTH));
        int h = static_cast<int>(capture.get(CV_CAP_PROP_FRAME_HEIGHT));
        return Size(w, h);
    }
    else {
        //从图像获得帧大小
        cv::Mat tmp = cv::imread(images[0]);
        return (tmp.data) ? (tmp.size()) : (Size(0, 0));
    }
}

//设置输出视频文件,默认使用输入视频相同的参数
bool VideoProcessor::setOutput(const String &filename, int codec, double framerate, bool isColor){
    outputFile = filename;
    extension.clear();
    if (framerate == 0.0)
        framerate = getFrameRate();//与输入相同
    char c[4];
    //使用相同的编码格式
    if (codec==0)
    {
        codec = getCodec(c);
    }
    //打开输出视频
    return writer.open(outputFile,  //文件名
        codec,  //将使用的编码格式
        framerate,  //帧率
        getFrameSize(), //尺寸
        isColor);   //是否是彩色视频？
}

//输出帧 可能是视频文件或图像文件
void VideoProcessor::writeNextFrame(Mat &frame){
    if (extension.length())//我们输出到图像文件
    {
        stringstream ss;
        //组成输出文件名称
        ss << outputFile << setfill('0')
            << setw(digits)
            << currentIndex++ << extension;
        imwrite(ss.str(), frame);
    }
    else
    {//我们输出到视频文件
        writer.write(frame);
    }
}

//设置输出为独立的图像文件 扩展名必须是".jpg" ".bmp"
bool VideoProcessor::setOutput(const String &filename,//前缀
    const String&ext,//后缀
    int numberofDigits ,//数字位数
    int startIndex ){ //开始索引
    //数字位数必须是正的
    if (numberofDigits < 0)return false;
    //文件名及其后缀
    outputFile = filename;
    extension = ext;
    //文件名中的数字位数
    digits = numberofDigits;
    //开始索引
    currentIndex = startIndex;
    return true;
}
