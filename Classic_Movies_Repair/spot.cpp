//#include "spot.h"

//Spot::Spot()
//{
//}

//void Spot::onMouse(int event, int x, int y, int flag, void *param)
//{
////    Mat &img = *(cv::Mat*)param;
//    switch (event)
//    {
//    //移动鼠标的时候
//    case CV_EVENT_MOUSEMOVE:
//    {
//        g_OrgPoint = g_CurrPoint;
//        g_CurrPoint = Point(x, y);
//        if (g_bDrawing == 1)
//        {
//            //通过一个Scalar对象定义线条的颜色，g_nThick定义的宽度
//            line(srcImage, g_CurrPoint, g_OrgPoint, Scalar(g_nBlue, g_nGreen, g_nRed), g_nThick);
//            imshow("【鼠标事件窗口】", srcImage);
//            //在掩膜图上进行显示线条
//            line(maskImage, g_CurrPoint, g_OrgPoint, Scalar(g_nBlue, g_nGreen, g_nRed), g_nThick);
//            imshow("【掩膜图像】", maskImage);
//        }
//    }
//        break;
//        //点击鼠标左键时
//    case CV_EVENT_LBUTTONDOWN:
//    {
//        g_bDrawing = true;
//        g_OrgPoint = Point(x, y);
//        g_CurrPoint = g_OrgPoint;
//    }
//        break;
//        //松开鼠标左键时
//    case CV_EVENT_LBUTTONUP:
//    {
//        g_bDrawing = false;
//    }
//        break;
//    }
//}

////void chuandi()
////{
////    Spot::onMouse();
////}

//int Spot::spotDelete()
//{
////    Mat tempImage;
////    RNG &rng = theRNG();

//    //srcImage = imread("./dolphin.jpeg");
//    //srcImage = imread("./picture033.png");
//    srcImage = imread("./2711Picture000.png");
//    //用一个变量来存储原图像
//    Mat g_srcImage;
//    srcImage.copyTo(g_srcImage);

//    //Mat originalImage=sourceImage.clone();

//    //为掩模图 分配空间, 掩模图片，是单通道图(灰度图)
//    maskImage.create(srcImage.size(), CV_8UC1);
//    //Scalar是将图像设置成单一灰度和颜色,将掩模图初始化为全黑色
//    maskImage = Scalar::all(0);

//    //设置窗口名字
//    namedWindow("【鼠标事件窗口】");
//    //鼠标响应,调用函数onMouse
//    setMouseCallback("【鼠标事件窗口】", onMouse, 0);

//    //设置窗口名字
//    namedWindow("【滚动条窗口】", 0);

//    //createTrackbar创建一个可以调节输入变量值的滑动条,并将改控件依附于指定的窗口上。
//    createTrackbar("thick", "【滚动条窗口】", &g_nThick, 100, 0);
//    createTrackbar("Blue", "【滚动条窗口】", &g_nBlue, 255, 0);
//    createTrackbar("Green", "【滚动条窗口】", &g_nGreen, 255, 0);
//    createTrackbar("Red", "【滚动条窗口】", &g_nRed, 255, 0);

////    char key;
//    while (1)
//    {
//        imshow("【鼠标事件窗口】", srcImage);
//        char key = waitKey();
//        //Esc对应的key值是27
//        if (key == 27)
//            break;
//        //如果检测到键值是1 则恢复原图
//        if (key == '1')
//        {
//            g_srcImage.copyTo(srcImage);
//            //将掩模图设置成为全黑色
//            maskImage = Scalar::all(0);
//            imshow("【掩膜图像】",maskImage);
//            imshow("【鼠标事件窗口】", srcImage);
//        }
//        //imwrite("result1.png",srcImage);
//        //如果检测到空格 则开始执行图像修复
//        Mat dstImage;
//        dstImage.create(srcImage.size(), srcImage.type());
//        if (key == ' ')
//        {
//            inpaint(srcImage, maskImage, dstImage, 3, INPAINT_TELEA);
//            imshow("【修补后的图像】", dstImage);
//        }
//    }
//    return 0;
//}


