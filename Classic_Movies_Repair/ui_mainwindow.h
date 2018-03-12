/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Recover_Image;
    QAction *action_Quit;
    QAction *action_Open_Image;
    QAction *action_Open_Film;
    QAction *action_Save_Image;
    QAction *action_Save_Film;
    QAction *action_Add_Salt_Noise;
    QAction *action_Delete_Salt_Noise;
    QAction *actionTest;
    QAction *action_Add_Spot;
    QAction *action_Delete_Spot;
    QAction *actionTest_open;
    QWidget *centralWidget;
    QLabel *origin_imagelabel;
    QLabel *processd_imagelabel;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menuProcess;
    QMenu *menuNoise;
    QMenu *menuTest;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(817, 394);
        action_Recover_Image = new QAction(MainWindow);
        action_Recover_Image->setObjectName(QStringLiteral("action_Recover_Image"));
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        action_Open_Image = new QAction(MainWindow);
        action_Open_Image->setObjectName(QStringLiteral("action_Open_Image"));
        action_Open_Film = new QAction(MainWindow);
        action_Open_Film->setObjectName(QStringLiteral("action_Open_Film"));
        action_Save_Image = new QAction(MainWindow);
        action_Save_Image->setObjectName(QStringLiteral("action_Save_Image"));
        action_Save_Film = new QAction(MainWindow);
        action_Save_Film->setObjectName(QStringLiteral("action_Save_Film"));
        action_Add_Salt_Noise = new QAction(MainWindow);
        action_Add_Salt_Noise->setObjectName(QStringLiteral("action_Add_Salt_Noise"));
        action_Delete_Salt_Noise = new QAction(MainWindow);
        action_Delete_Salt_Noise->setObjectName(QStringLiteral("action_Delete_Salt_Noise"));
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        action_Add_Spot = new QAction(MainWindow);
        action_Add_Spot->setObjectName(QStringLiteral("action_Add_Spot"));
        action_Delete_Spot = new QAction(MainWindow);
        action_Delete_Spot->setObjectName(QStringLiteral("action_Delete_Spot"));
        actionTest_open = new QAction(MainWindow);
        actionTest_open->setObjectName(QStringLiteral("actionTest_open"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        origin_imagelabel = new QLabel(centralWidget);
        origin_imagelabel->setObjectName(QStringLiteral("origin_imagelabel"));
        origin_imagelabel->setGeometry(QRect(20, 0, 371, 331));
        processd_imagelabel = new QLabel(centralWidget);
        processd_imagelabel->setObjectName(QStringLiteral("processd_imagelabel"));
        processd_imagelabel->setGeometry(QRect(430, 0, 371, 331));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 817, 25));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        menu = new QMenu(menuOpen);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuOpen);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menuProcess = new QMenu(menuBar);
        menuProcess->setObjectName(QStringLiteral("menuProcess"));
        menuNoise = new QMenu(menuProcess);
        menuNoise->setObjectName(QStringLiteral("menuNoise"));
        menuTest = new QMenu(menuBar);
        menuTest->setObjectName(QStringLiteral("menuTest"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOpen->menuAction());
        menuBar->addAction(menuProcess->menuAction());
        menuBar->addAction(menuTest->menuAction());
        menuOpen->addAction(menu->menuAction());
        menuOpen->addAction(menu_2->menuAction());
        menuOpen->addAction(action_Recover_Image);
        menuOpen->addAction(action_Quit);
        menu->addAction(action_Open_Image);
        menu->addAction(action_Open_Film);
        menu_2->addAction(action_Save_Image);
        menu_2->addAction(action_Save_Film);
        menuProcess->addAction(menuNoise->menuAction());
        menuNoise->addAction(action_Add_Salt_Noise);
        menuNoise->addAction(action_Delete_Salt_Noise);
        menuTest->addAction(actionTest_open);

        retranslateUi(MainWindow);
        QObject::connect(action_Open_Image, SIGNAL(triggered()), MainWindow, SLOT(action_Open_Image_Slot()));
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(action_Open_Film, SIGNAL(triggered()), MainWindow, SLOT(action_Open_Film_Slot()));
        QObject::connect(action_Save_Image, SIGNAL(triggered()), MainWindow, SLOT(action_Save_Image_Slot()));
        QObject::connect(action_Save_Film, SIGNAL(triggered()), MainWindow, SLOT(action_Save_Film_Slot()));
        QObject::connect(action_Recover_Image, SIGNAL(triggered()), MainWindow, SLOT(action_Recover_Image_Slot()));
        QObject::connect(action_Add_Salt_Noise, SIGNAL(triggered()), MainWindow, SLOT(action_Add_Salt_Noise_Slot()));
        QObject::connect(action_Delete_Salt_Noise, SIGNAL(triggered()), MainWindow, SLOT(action_Delete_Salt_Noise_Slot()));
        QObject::connect(actionTest, SIGNAL(triggered()), MainWindow, SLOT(test_open()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\200\201\347\224\265\345\275\261\344\277\256\345\244\215", 0));
        action_Recover_Image->setText(QApplication::translate("MainWindow", "\345\244\215\345\216\237", 0));
        action_Recover_Image->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0));
        action_Quit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        action_Quit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        action_Open_Image->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207", 0));
        action_Open_Film->setText(QApplication::translate("MainWindow", "\347\224\265\345\275\261", 0));
        action_Save_Image->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207", 0));
        action_Save_Film->setText(QApplication::translate("MainWindow", "\347\224\265\345\275\261", 0));
        action_Add_Salt_Noise->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\244\222\347\233\220\345\231\252\345\243\260", 0));
        action_Delete_Salt_Noise->setText(QApplication::translate("MainWindow", "\346\266\210\351\231\244\346\244\222\347\233\220\345\231\252\345\243\260", 0));
        actionTest->setText(QApplication::translate("MainWindow", "test", 0));
        action_Add_Spot->setText(QApplication::translate("MainWindow", "Add_Spot", 0));
        action_Delete_Spot->setText(QApplication::translate("MainWindow", "Delete_Spot", 0));
        actionTest_open->setText(QApplication::translate("MainWindow", "test_open", 0));
        origin_imagelabel->setText(QString());
        processd_imagelabel->setText(QString());
        menuOpen->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\344\277\235\345\255\230", 0));
        menuProcess->setTitle(QApplication::translate("MainWindow", "\345\244\204\347\220\206", 0));
        menuNoise->setTitle(QApplication::translate("MainWindow", "\345\231\252\345\243\260\345\244\204\347\220\206", 0));
        menuTest->setTitle(QApplication::translate("MainWindow", "test", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
