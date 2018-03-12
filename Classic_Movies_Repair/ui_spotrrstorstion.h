/********************************************************************************
** Form generated from reading UI file 'spotrrstorstion.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPOTRRSTORSTION_H
#define UI_SPOTRRSTORSTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpotRrstorstion
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *SpotRrstorstion)
    {
        if (SpotRrstorstion->objectName().isEmpty())
            SpotRrstorstion->setObjectName(QStringLiteral("SpotRrstorstion"));
        SpotRrstorstion->resize(400, 300);
        pushButton = new QPushButton(SpotRrstorstion);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 60, 99, 27));
        pushButton_2 = new QPushButton(SpotRrstorstion);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 110, 99, 27));
        pushButton_3 = new QPushButton(SpotRrstorstion);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(140, 160, 99, 27));

        retranslateUi(SpotRrstorstion);
        QObject::connect(pushButton, SIGNAL(clicked()), SpotRrstorstion, SLOT(open()));

        QMetaObject::connectSlotsByName(SpotRrstorstion);
    } // setupUi

    void retranslateUi(QWidget *SpotRrstorstion)
    {
        SpotRrstorstion->setWindowTitle(QApplication::translate("SpotRrstorstion", "Form", 0));
        pushButton->setText(QApplication::translate("SpotRrstorstion", "open", 0));
        pushButton_2->setText(QApplication::translate("SpotRrstorstion", "next", 0));
        pushButton_3->setText(QApplication::translate("SpotRrstorstion", "save", 0));
    } // retranslateUi

};

namespace Ui {
    class SpotRrstorstion: public Ui_SpotRrstorstion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPOTRRSTORSTION_H
