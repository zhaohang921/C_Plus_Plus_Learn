#-------------------------------------------------
#
# Project created by QtCreator 2018-01-17T09:21:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Classic_Movies_Repair
TEMPLATE = app


INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so \
        /usr/local/lib/libopencv_imgcodecs.so.3.4 \
        /usr/local/lib/libopencv_videoio.so \
        /usr/local/lib/libopencv_video.so \
        /usr/local/lib/libopencv_photo.so \
        /usr/local/lib/libopencv_photo.so.3.4 \
        /usr/local/lib/libopencv_photo.so.3.4.0 \





SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    imageprocessor.cpp \
    videoprocessor.cpp \
    noiseprocessor.cpp \
    spot.cpp \
    spotrrstorstion.cpp

HEADERS  += mainwindow.h \
    shake.h \
    dialog.h \
    imageprocessor.h \
    frameprocessor.h \
    noiseprocessor.h \
    videoprocessor.h \
    spot.h \
    spot_test.h \
    spot_test1.h \
    opencv_header.h \
    spotrrstorstion.h

FORMS    += mainwindow.ui \
    dialog.ui \
    spotrrstorstion.ui
