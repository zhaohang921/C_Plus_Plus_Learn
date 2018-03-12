#include "mainwindow.h"
#include <QApplication>
#include"spotrrstorstion.h"

//#include"spot.h"
#include"spot_test.h"
#include"spot_test1.h"
#include"shake.h"

void test2_VideoProcessor()
{
//    VideoProcessor processor;
//    processor.setInput("./data/Street_Angel/低质量_avi/2719_2725.avi");
//    processor.displayInput("当前帧");
//    processor.displayOutput("输出帧");
//    processor.setDelay(25);//设置延迟
//    processor.setFrameProcessor(canny);//设置处理回调函数
//    processor.run();//开始处理
}

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

    //测试斑点消除，spot_test
//    spot_test();

//测试抖动shake
   // String Video_Open_Path="./data/test/test.mp4";
    String Video_Open_Path="./data/Street_Angel/中质量_avi/2719_2725.avi";

    shake(Video_Open_Path);



//    QApplication a(argc, argv);
//    SpotRrstorstion s;
//    Mat image=s.ori_image;
//    s.show();
//    //spot_test(image);
//    return a.exec();
//    spot_test(image);




}
