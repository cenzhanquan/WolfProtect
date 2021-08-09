/********************************************************************************
** Form generated from reading UI file 'gameruledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMERULEDIALOG_H
#define UI_GAMERULEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GameRuleDialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;

    void setupUi(QDialog *GameRuleDialog)
    {
        if (GameRuleDialog->objectName().isEmpty())
            GameRuleDialog->setObjectName(QStringLiteral("GameRuleDialog"));
        GameRuleDialog->resize(900, 612);
        GameRuleDialog->setMinimumSize(QSize(900, 612));
        GameRuleDialog->setMaximumSize(QSize(900, 612));
        pushButton = new QPushButton(GameRuleDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(860, 0, 40, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(13);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(GameRuleDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 10, 341, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(20);
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 0);\n"
"color: rgb(255, 85, 0);"));
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(GameRuleDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 60, 850, 51));
        QFont font2;
        font2.setPointSize(12);
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 127);\n"
"color: rgb(255, 255, 0);"));
        pushButton_3->setFlat(true);
        pushButton_4 = new QPushButton(GameRuleDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 120, 850, 51));
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 127);\n"
"color: rgb(255, 255, 0);"));
        pushButton_4->setFlat(true);
        pushButton_5 = new QPushButton(GameRuleDialog);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 180, 850, 51));
        pushButton_5->setFont(font2);
        pushButton_5->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 127);\n"
"color: rgb(255, 255, 0);"));
        pushButton_5->setFlat(true);
        pushButton_6 = new QPushButton(GameRuleDialog);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 240, 850, 51));
        pushButton_6->setFont(font2);
        pushButton_6->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 127);\n"
"color: rgb(255, 255, 0);"));
        pushButton_6->setFlat(true);
        pushButton_7 = new QPushButton(GameRuleDialog);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(20, 300, 850, 51));
        pushButton_7->setFont(font2);
        pushButton_7->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 127);\n"
"color: rgb(255, 255, 0);"));
        pushButton_7->setFlat(true);
        pushButton_9 = new QPushButton(GameRuleDialog);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(20, 490, 850, 51));
        pushButton_9->setFont(font2);
        pushButton_9->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 127);\n"
"color: rgb(255, 255, 0);"));
        pushButton_9->setFlat(true);
        pushButton_10 = new QPushButton(GameRuleDialog);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(20, 430, 850, 51));
        pushButton_10->setFont(font2);
        pushButton_10->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 127);\n"
"color: rgb(255, 255, 0);"));
        pushButton_10->setFlat(true);
        pushButton_11 = new QPushButton(GameRuleDialog);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(20, 370, 850, 51));
        pushButton_11->setFont(font2);
        pushButton_11->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 127);\n"
"color: rgb(255, 255, 0); "));
        pushButton_11->setFlat(true);

        retranslateUi(GameRuleDialog);

        QMetaObject::connectSlotsByName(GameRuleDialog);
    } // setupUi

    void retranslateUi(QDialog *GameRuleDialog)
    {
        GameRuleDialog->setWindowTitle(QApplication::translate("GameRuleDialog", "Dialog", 0));
        pushButton->setText(QApplication::translate("GameRuleDialog", "\303\227", 0));
        pushButton_2->setText(QApplication::translate("GameRuleDialog", "\346\270\270\346\210\217\350\247\204\345\210\231", 0));
        pushButton_3->setText(QApplication::translate("GameRuleDialog", "\346\270\270\346\210\217\351\205\215\347\275\256\344\270\2728\344\272\272\345\261\200\346\270\270\346\210\217\351\205\215\347\275\256:\346\234\254\345\261\200\346\270\270\346\210\217\347\224\261\344\270\211\347\213\274,\344\270\244\345\271\263\346\260\221,\344\270\200\344\270\252\351\242\204\350\250\200\345\256\266,\344\270\200\344\270\252\347\214\216\344\272\272,\344\270\200\344\270\252\345\245\263\345\267\253\347\273\204\346\210\220\347\232\204\351\205\215\347\275\256", 0));
        pushButton_4->setText(QApplication::translate("GameRuleDialog", "\345\245\263\345\267\253\346\234\211\344\270\200\347\223\266\346\257\222\350\215\257\345\222\214\344\270\200\347\223\266\350\247\243\350\215\257,\345\275\223\345\245\263\345\267\253\350\242\253\345\210\200\347\232\204\346\227\266\345\200\231,\346\211\213\351\207\214\346\234\211\350\247\243\350\215\257\345\260\261\345\217\257\344\273\245\350\207\252\346\225\221,\344\270\224\350\203\275\346\225\221\345\210\253\344\272\272,\346\257\222\350\215\257,\350\247\243\350\215\257", 0));
        pushButton_5->setText(QApplication::translate("GameRuleDialog", "\345\220\204\344\270\200\347\223\266,\350\242\253\346\257\222\346\255\273\347\232\204\344\272\272\344\270\215\350\203\275\345\217\221\350\250\200.                                                      ", 0));
        pushButton_6->setText(QApplication::translate("GameRuleDialog", "\351\242\204\350\250\200\345\256\266\346\257\217\345\261\200\351\203\275\345\217\257\344\273\245\346\237\245\347\234\213\344\270\200\344\270\252\344\272\272\347\232\204\350\272\253\344\273\275                                                 ", 0));
        pushButton_7->setText(QApplication::translate("GameRuleDialog", "\347\214\216\344\272\272\346\211\213\351\207\214\346\234\211\344\270\200\346\212\212\346\236\252,\346\236\252\351\207\214\345\260\261\345\217\252\346\234\211\344\270\200\351\242\227\345\255\220\345\274\271,\347\224\250\345\256\214\345\217\212\346\255\242,\346\257\217\344\270\252\346\231\232\344\270\212\351\203\275\345\217\257\344\273\245\351\200\211\346\213\251\345\270\246\350\265\260\344\270\200\344\270\252\344\272\272,\344\270\224\350\242\253\345\245\263\345\267\253\346\257\222", 0));
        pushButton_9->setText(QApplication::translate("GameRuleDialog", "\350\203\234\345\210\251\350\247\204\345\210\231:\345\275\223\347\213\274\344\272\272\346\212\212\346\260\221\345\205\250\351\203\250\346\235\200\345\205\211,\346\210\226\350\200\205\346\212\212\347\245\236\345\205\250\351\203\250\346\235\200\345\205\211\345\215\263\347\213\274\344\272\272\350\216\267\350\203\234,\345\275\223\345\245\275\344\272\272\346\212\212\347\213\274\345\205\250\351\203\250\346\255\273\344\272\241\345\215\263\345\245\275\344\272\272\350\216\267\350\203\234   ", 0));
        pushButton_10->setText(QApplication::translate("GameRuleDialog", "\345\257\271\344\272\216\346\212\225\347\245\250,\346\257\217\344\270\252\344\272\272\346\257\217\345\244\251\345\217\252\350\203\275\346\212\225\344\270\200\346\254\241,\347\245\250\346\225\260\346\234\200\345\244\232\350\200\205\345\260\261\345\207\272\345\261\200                                     ", 0));
        pushButton_11->setText(QApplication::translate("GameRuleDialog", "\346\255\273\344\270\215\350\203\275\345\274\200\346\236\252.                                                                     ", 0));
    } // retranslateUi

};

namespace Ui {
    class GameRuleDialog: public Ui_GameRuleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMERULEDIALOG_H
