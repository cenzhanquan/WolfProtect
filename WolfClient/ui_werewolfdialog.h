/********************************************************************************
** Form generated from reading UI file 'werewolfdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEREWOLFDIALOG_H
#define UI_WEREWOLFDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WerewolfDialog
{
public:
    QWidget *wdg_wolfd;
    QTextBrowser *tb_annunciate;
    QTextEdit *te_write;
    QPushButton *pb_send;
    QPushButton *pb_audio;
    QPushButton *pb_player5;
    QTextBrowser *tb_chat;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QPushButton *pb_identity;
    QPushButton *pb_roomid;
    QPushButton *pb_player6;
    QPushButton *pb_player7;
    QPushButton *pb_player8;
    QPushButton *pb_player3;
    QPushButton *pb_player1;
    QPushButton *pb_player4;
    QPushButton *pb_player2;
    QPushButton *pb_firstID;
    QPushButton *pb_secondID;
    QPushButton *pb_threeID;
    QPushButton *pb_fourID;
    QPushButton *pb_eightID;
    QPushButton *pu_fiveID;
    QPushButton *pb_sevenID;
    QPushButton *pb_sixID;
    QPushButton *pb_days;
    QPushButton *pushButton_37;
    QPushButton *pb_myselfprrpare;
    QPushButton *pb_prepare1;
    QPushButton *pb_prepare2;
    QPushButton *pb_prepare3;
    QPushButton *pb_prepare4;
    QPushButton *pb_prepare8;
    QPushButton *pb_prepare5;
    QPushButton *pb_prepare6;
    QPushButton *pb_prepare7;
    QPushButton *pb_invitefriends;
    QPushButton *pb_landlord;
    QPushButton *pushButton;
    QLabel *lb_time;

    void setupUi(QDialog *WerewolfDialog)
    {
        if (WerewolfDialog->objectName().isEmpty())
            WerewolfDialog->setObjectName(QStringLiteral("WerewolfDialog"));
        WerewolfDialog->resize(1000, 800);
        WerewolfDialog->setMinimumSize(QSize(1000, 800));
        WerewolfDialog->setMaximumSize(QSize(1000, 800));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        WerewolfDialog->setFont(font);
        wdg_wolfd = new QWidget(WerewolfDialog);
        wdg_wolfd->setObjectName(QStringLiteral("wdg_wolfd"));
        wdg_wolfd->setGeometry(QRect(-10, -10, 1011, 900));
        QFont font1;
        font1.setPointSize(9);
        wdg_wolfd->setFont(font1);
        wdg_wolfd->setLayoutDirection(Qt::RightToLeft);
        tb_annunciate = new QTextBrowser(wdg_wolfd);
        tb_annunciate->setObjectName(QStringLiteral("tb_annunciate"));
        tb_annunciate->setGeometry(QRect(270, 130, 471, 141));
        QFont font2;
        font2.setPointSize(13);
        tb_annunciate->setFont(font2);
        te_write = new QTextEdit(wdg_wolfd);
        te_write->setObjectName(QStringLiteral("te_write"));
        te_write->setGeometry(QRect(270, 760, 471, 41));
        pb_send = new QPushButton(wdg_wolfd);
        pb_send->setObjectName(QStringLiteral("pb_send"));
        pb_send->setGeometry(QRect(750, 760, 71, 41));
        pb_send->setFont(font2);
        pb_audio = new QPushButton(wdg_wolfd);
        pb_audio->setObjectName(QStringLiteral("pb_audio"));
        pb_audio->setGeometry(QRect(140, 760, 121, 41));
        pb_audio->setFont(font1);
        pb_player5 = new QPushButton(wdg_wolfd);
        pb_player5->setObjectName(QStringLiteral("pb_player5"));
        pb_player5->setGeometry(QRect(810, 100, 141, 151));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/desk.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pb_player5->setIcon(icon);
        pb_player5->setIconSize(QSize(170, 161));
        pb_player5->setFlat(true);
        tb_chat = new QTextBrowser(wdg_wolfd);
        tb_chat->setObjectName(QStringLiteral("tb_chat"));
        tb_chat->setGeometry(QRect(270, 310, 471, 441));
        tb_chat->setFont(font2);
        pushButton_22 = new QPushButton(wdg_wolfd);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(10, 50, 191, 31));
        QFont font3;
        font3.setPointSize(12);
        pushButton_22->setFont(font3);
        pushButton_22->setAutoRepeatDelay(299);
        pushButton_22->setFlat(false);
        pushButton_23 = new QPushButton(wdg_wolfd);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setGeometry(QRect(980, 10, 30, 30));
        QFont font4;
        font4.setPointSize(14);
        pushButton_23->setFont(font4);
        pushButton_24 = new QPushButton(wdg_wolfd);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setGeometry(QRect(270, 90, 81, 31));
        pushButton_24->setFont(font3);
        pushButton_24->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pushButton_24->setFlat(true);
        pushButton_25 = new QPushButton(wdg_wolfd);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setGeometry(QRect(270, 270, 81, 31));
        pushButton_25->setFont(font3);
        pushButton_25->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pushButton_25->setFlat(true);
        pb_identity = new QPushButton(wdg_wolfd);
        pb_identity->setObjectName(QStringLiteral("pb_identity"));
        pb_identity->setGeometry(QRect(640, 50, 301, 31));
        pb_identity->setFont(font4);
        pb_identity->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pb_identity->setFlat(true);
        pb_roomid = new QPushButton(wdg_wolfd);
        pb_roomid->setObjectName(QStringLiteral("pb_roomid"));
        pb_roomid->setGeometry(QRect(10, 7, 271, 41));
        pb_roomid->setFont(font2);
        pb_roomid->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pb_player6 = new QPushButton(wdg_wolfd);
        pb_player6->setObjectName(QStringLiteral("pb_player6"));
        pb_player6->setGeometry(QRect(810, 270, 141, 151));
        pb_player6->setIcon(icon);
        pb_player6->setIconSize(QSize(170, 161));
        pb_player6->setFlat(true);
        pb_player7 = new QPushButton(wdg_wolfd);
        pb_player7->setObjectName(QStringLiteral("pb_player7"));
        pb_player7->setGeometry(QRect(810, 430, 141, 151));
        pb_player7->setIcon(icon);
        pb_player7->setIconSize(QSize(170, 161));
        pb_player7->setFlat(true);
        pb_player8 = new QPushButton(wdg_wolfd);
        pb_player8->setObjectName(QStringLiteral("pb_player8"));
        pb_player8->setGeometry(QRect(810, 590, 141, 151));
        pb_player8->setIcon(icon);
        pb_player8->setIconSize(QSize(170, 161));
        pb_player8->setFlat(true);
        pb_player3 = new QPushButton(wdg_wolfd);
        pb_player3->setObjectName(QStringLiteral("pb_player3"));
        pb_player3->setGeometry(QRect(50, 420, 141, 151));
        pb_player3->setIcon(icon);
        pb_player3->setIconSize(QSize(170, 161));
        pb_player3->setFlat(true);
        pb_player1 = new QPushButton(wdg_wolfd);
        pb_player1->setObjectName(QStringLiteral("pb_player1"));
        pb_player1->setGeometry(QRect(50, 90, 141, 151));
        pb_player1->setIcon(icon);
        pb_player1->setIconSize(QSize(170, 161));
        pb_player1->setFlat(true);
        pb_player4 = new QPushButton(wdg_wolfd);
        pb_player4->setObjectName(QStringLiteral("pb_player4"));
        pb_player4->setGeometry(QRect(50, 580, 141, 151));
        pb_player4->setIcon(icon);
        pb_player4->setIconSize(QSize(170, 161));
        pb_player4->setFlat(true);
        pb_player2 = new QPushButton(wdg_wolfd);
        pb_player2->setObjectName(QStringLiteral("pb_player2"));
        pb_player2->setGeometry(QRect(50, 260, 141, 151));
        pb_player2->setIcon(icon);
        pb_player2->setIconSize(QSize(170, 161));
        pb_player2->setFlat(true);
        pb_firstID = new QPushButton(wdg_wolfd);
        pb_firstID->setObjectName(QStringLiteral("pb_firstID"));
        pb_firstID->setGeometry(QRect(10, 139, 41, 51));
        pb_firstID->setFont(font2);
        pb_firstID->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pb_firstID->setFlat(true);
        pb_secondID = new QPushButton(wdg_wolfd);
        pb_secondID->setObjectName(QStringLiteral("pb_secondID"));
        pb_secondID->setGeometry(QRect(10, 310, 41, 51));
        pb_secondID->setFont(font2);
        pb_secondID->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pb_secondID->setFlat(true);
        pb_threeID = new QPushButton(wdg_wolfd);
        pb_threeID->setObjectName(QStringLiteral("pb_threeID"));
        pb_threeID->setGeometry(QRect(10, 470, 41, 51));
        pb_threeID->setFont(font2);
        pb_threeID->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pb_threeID->setFlat(true);
        pb_fourID = new QPushButton(wdg_wolfd);
        pb_fourID->setObjectName(QStringLiteral("pb_fourID"));
        pb_fourID->setGeometry(QRect(10, 640, 41, 51));
        pb_fourID->setFont(font2);
        pb_fourID->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pb_fourID->setFlat(true);
        pb_eightID = new QPushButton(wdg_wolfd);
        pb_eightID->setObjectName(QStringLiteral("pb_eightID"));
        pb_eightID->setGeometry(QRect(960, 650, 41, 51));
        pb_eightID->setFont(font2);
        pb_eightID->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pb_eightID->setFlat(true);
        pu_fiveID = new QPushButton(wdg_wolfd);
        pu_fiveID->setObjectName(QStringLiteral("pu_fiveID"));
        pu_fiveID->setGeometry(QRect(960, 149, 41, 51));
        pu_fiveID->setFont(font2);
        pu_fiveID->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pu_fiveID->setFlat(true);
        pb_sevenID = new QPushButton(wdg_wolfd);
        pb_sevenID->setObjectName(QStringLiteral("pb_sevenID"));
        pb_sevenID->setGeometry(QRect(960, 480, 41, 51));
        pb_sevenID->setFont(font2);
        pb_sevenID->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pb_sevenID->setFlat(true);
        pb_sixID = new QPushButton(wdg_wolfd);
        pb_sixID->setObjectName(QStringLiteral("pb_sixID"));
        pb_sixID->setGeometry(QRect(960, 320, 41, 51));
        pb_sixID->setFont(font2);
        pb_sixID->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pb_sixID->setFlat(true);
        pb_days = new QPushButton(wdg_wolfd);
        pb_days->setObjectName(QStringLiteral("pb_days"));
        pb_days->setGeometry(QRect(430, 10, 201, 41));
        pb_days->setFont(font2);
        pb_days->setLayoutDirection(Qt::RightToLeft);
        pb_days->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pushButton_37 = new QPushButton(wdg_wolfd);
        pushButton_37->setObjectName(QStringLiteral("pushButton_37"));
        pushButton_37->setGeometry(QRect(920, 760, 91, 41));
        pushButton_37->setMaximumSize(QSize(16777215, 16777215));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font5.setPointSize(10);
        pushButton_37->setFont(font5);
        pb_myselfprrpare = new QPushButton(wdg_wolfd);
        pb_myselfprrpare->setObjectName(QStringLiteral("pb_myselfprrpare"));
        pb_myselfprrpare->setGeometry(QRect(830, 760, 81, 41));
        pb_myselfprrpare->setFont(font2);
        pb_myselfprrpare->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 0);"));
        pb_prepare1 = new QPushButton(wdg_wolfd);
        pb_prepare1->setObjectName(QStringLiteral("pb_prepare1"));
        pb_prepare1->setGeometry(QRect(210, 150, 61, 41));
        pb_prepare1->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 0);"));
        pb_prepare2 = new QPushButton(wdg_wolfd);
        pb_prepare2->setObjectName(QStringLiteral("pb_prepare2"));
        pb_prepare2->setGeometry(QRect(210, 340, 61, 41));
        pb_prepare2->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 0);"));
        pb_prepare3 = new QPushButton(wdg_wolfd);
        pb_prepare3->setObjectName(QStringLiteral("pb_prepare3"));
        pb_prepare3->setGeometry(QRect(210, 490, 61, 41));
        pb_prepare3->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 0);"));
        pb_prepare4 = new QPushButton(wdg_wolfd);
        pb_prepare4->setObjectName(QStringLiteral("pb_prepare4"));
        pb_prepare4->setGeometry(QRect(210, 650, 61, 41));
        pb_prepare4->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 0);"));
        pb_prepare8 = new QPushButton(wdg_wolfd);
        pb_prepare8->setObjectName(QStringLiteral("pb_prepare8"));
        pb_prepare8->setGeometry(QRect(740, 660, 61, 41));
        pb_prepare8->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 0);"));
        pb_prepare5 = new QPushButton(wdg_wolfd);
        pb_prepare5->setObjectName(QStringLiteral("pb_prepare5"));
        pb_prepare5->setGeometry(QRect(740, 150, 61, 41));
        pb_prepare5->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 0);"));
        pb_prepare6 = new QPushButton(wdg_wolfd);
        pb_prepare6->setObjectName(QStringLiteral("pb_prepare6"));
        pb_prepare6->setGeometry(QRect(740, 350, 61, 41));
        pb_prepare6->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 0);"));
        pb_prepare7 = new QPushButton(wdg_wolfd);
        pb_prepare7->setObjectName(QStringLiteral("pb_prepare7"));
        pb_prepare7->setGeometry(QRect(740, 500, 61, 41));
        pb_prepare7->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 0);"));
        pb_invitefriends = new QPushButton(wdg_wolfd);
        pb_invitefriends->setObjectName(QStringLiteral("pb_invitefriends"));
        pb_invitefriends->setGeometry(QRect(20, 760, 111, 41));
        pb_invitefriends->setFont(font2);
        pb_landlord = new QPushButton(wdg_wolfd);
        pb_landlord->setObjectName(QStringLiteral("pb_landlord"));
        pb_landlord->setGeometry(QRect(200, 50, 221, 31));
        pb_landlord->setFont(font3);
        pb_landlord->setAutoFillBackground(false);
        pb_landlord->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 255);"));
        pb_landlord->setFlat(true);
        pushButton = new QPushButton(wdg_wolfd);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(950, 10, 30, 30));
        pushButton->setFont(font2);
        lb_time = new QLabel(wdg_wolfd);
        lb_time->setObjectName(QStringLiteral("lb_time"));
        lb_time->setGeometry(QRect(480, 80, 101, 51));
        lb_time->setMinimumSize(QSize(101, 51));
        lb_time->setMaximumSize(QSize(101, 51));
        QFont font6;
        font6.setPointSize(30);
        font6.setBold(true);
        font6.setWeight(75);
        lb_time->setFont(font6);
        lb_time->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        lb_time->setAlignment(Qt::AlignCenter);
        lb_time->setWordWrap(false);

        retranslateUi(WerewolfDialog);

        QMetaObject::connectSlotsByName(WerewolfDialog);
    } // setupUi

    void retranslateUi(QDialog *WerewolfDialog)
    {
        WerewolfDialog->setWindowTitle(QApplication::translate("WerewolfDialog", "Dialog", 0));
        pb_send->setText(QApplication::translate("WerewolfDialog", "\345\217\221\351\200\201", 0));
        pb_audio->setText(QApplication::translate("WerewolfDialog", "\346\211\223\345\274\200\351\237\263\351\242\221\350\256\276\345\244\207", 0));
        pb_player5->setText(QString());
        pushButton_22->setText(QApplication::translate("WerewolfDialog", "\346\270\270\346\210\217\350\247\204\345\210\231\346\211\213\345\206\214", 0));
        pushButton_23->setText(QApplication::translate("WerewolfDialog", "\303\227", 0));
        pushButton_24->setText(QApplication::translate("WerewolfDialog", "\351\200\232\345\221\212", 0));
        pushButton_25->setText(QApplication::translate("WerewolfDialog", "\350\201\212\345\244\251", 0));
        pb_identity->setText(QApplication::translate("WerewolfDialog", "\345\275\223\345\211\215\344\275\240\347\232\204\350\272\253\344\273\275\347\211\214\344\270\272:\351\200\217\346\230\216\344\272\272", 0));
        pb_roomid->setText(QApplication::translate("WerewolfDialog", "\346\210\277\351\227\264\345\217\267:0", 0));
        pb_player6->setText(QString());
        pb_player7->setText(QString());
        pb_player8->setText(QString());
        pb_player3->setText(QString());
        pb_player1->setText(QString());
        pb_player4->setText(QString());
        pb_player2->setText(QString());
        pb_firstID->setText(QApplication::translate("WerewolfDialog", "\344\270\200", 0));
        pb_secondID->setText(QApplication::translate("WerewolfDialog", "\344\272\214", 0));
        pb_threeID->setText(QApplication::translate("WerewolfDialog", "\344\270\211", 0));
        pb_fourID->setText(QApplication::translate("WerewolfDialog", "\345\233\233", 0));
        pb_eightID->setText(QApplication::translate("WerewolfDialog", "\345\205\253", 0));
        pu_fiveID->setText(QApplication::translate("WerewolfDialog", "\344\272\224", 0));
        pb_sevenID->setText(QApplication::translate("WerewolfDialog", "\344\270\203", 0));
        pb_sixID->setText(QApplication::translate("WerewolfDialog", "\345\205\255", 0));
        pb_days->setText(QApplication::translate("WerewolfDialog", "\346\270\270\346\210\217\345\244\251\346\225\260:", 0));
        pushButton_37->setText(QApplication::translate("WerewolfDialog", "\347\246\273\345\274\200\346\210\277\351\227\264", 0));
        pb_myselfprrpare->setText(QApplication::translate("WerewolfDialog", "\345\207\206\345\244\207", 0));
        pb_prepare1->setText(QApplication::translate("WerewolfDialog", "\346\234\252\345\207\206\345\244\207", 0));
        pb_prepare2->setText(QApplication::translate("WerewolfDialog", "\346\234\252\345\207\206\345\244\207", 0));
        pb_prepare3->setText(QApplication::translate("WerewolfDialog", "\346\234\252\345\207\206\345\244\207", 0));
        pb_prepare4->setText(QApplication::translate("WerewolfDialog", "\346\234\252\345\207\206\345\244\207", 0));
        pb_prepare8->setText(QApplication::translate("WerewolfDialog", "\346\234\252\345\207\206\345\244\207", 0));
        pb_prepare5->setText(QApplication::translate("WerewolfDialog", "\346\234\252\345\207\206\345\244\207", 0));
        pb_prepare6->setText(QApplication::translate("WerewolfDialog", "\346\234\252\345\207\206\345\244\207", 0));
        pb_prepare7->setText(QApplication::translate("WerewolfDialog", "\346\234\252\345\207\206\345\244\207", 0));
        pb_invitefriends->setText(QApplication::translate("WerewolfDialog", "\351\202\200\350\257\267\345\245\275\345\217\213", 0));
        pb_landlord->setText(QApplication::translate("WerewolfDialog", "\345\275\223\345\211\215\346\210\277\344\270\273\344\270\272:", 0));
        pushButton->setText(QApplication::translate("WerewolfDialog", "\357\274\215", 0));
        lb_time->setText(QApplication::translate("WerewolfDialog", "00", 0));
    } // retranslateUi

};

namespace Ui {
    class WerewolfDialog: public Ui_WerewolfDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEREWOLFDIALOG_H
