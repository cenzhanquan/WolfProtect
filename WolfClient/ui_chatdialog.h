/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_tittlt;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lb_tittle;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pb_min;
    QPushButton *pb_max;
    QPushButton *pb_close;
    QWidget *wdg_content;
    QHBoxLayout *horizontalLayout;
    QWidget *wdg_left;
    QVBoxLayout *verticalLayout_3;
    QWidget *wdg_left_top;
    QVBoxLayout *verticalLayout_5;
    QTextBrowser *tb_chat;
    QWidget *wdg_tools;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_tool2;
    QPushButton *pb_tool4;
    QPushButton *pb_tool1;
    QPushButton *pb_tool3;
    QPushButton *pb_tool5;
    QSpacerItem *horizontalSpacer;
    QWidget *wdg_left_bottom;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *te_chat;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_send;
    QWidget *wdg_right;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tw_page;
    QWidget *tab_1;
    QWidget *tab_2;

    void setupUi(QDialog *chatDialog)
    {
        if (chatDialog->objectName().isEmpty())
            chatDialog->setObjectName(QStringLiteral("chatDialog"));
        chatDialog->resize(800, 600);
        chatDialog->setMinimumSize(QSize(800, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        chatDialog->setFont(font);
        chatDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(chatDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_tittlt = new QWidget(chatDialog);
        wdg_tittlt->setObjectName(QStringLiteral("wdg_tittlt"));
        wdg_tittlt->setMinimumSize(QSize(801, 41));
        wdg_tittlt->setMaximumSize(QSize(16777215, 41));
        horizontalLayout_4 = new QHBoxLayout(wdg_tittlt);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 11);
        lb_tittle = new QLabel(wdg_tittlt);
        lb_tittle->setObjectName(QStringLiteral("lb_tittle"));
        lb_tittle->setMinimumSize(QSize(201, 30));
        lb_tittle->setMaximumSize(QSize(16777215, 30));
        lb_tittle->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lb_tittle);

        horizontalSpacer_3 = new QSpacerItem(400, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pb_min = new QPushButton(wdg_tittlt);
        pb_min->setObjectName(QStringLiteral("pb_min"));
        pb_min->setMinimumSize(QSize(49, 30));
        pb_min->setMaximumSize(QSize(49, 30));

        horizontalLayout_4->addWidget(pb_min);

        pb_max = new QPushButton(wdg_tittlt);
        pb_max->setObjectName(QStringLiteral("pb_max"));
        pb_max->setMinimumSize(QSize(30, 30));
        pb_max->setMaximumSize(QSize(49, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        pb_max->setFont(font1);

        horizontalLayout_4->addWidget(pb_max);

        pb_close = new QPushButton(wdg_tittlt);
        pb_close->setObjectName(QStringLiteral("pb_close"));
        pb_close->setMinimumSize(QSize(49, 30));
        pb_close->setMaximumSize(QSize(49, 30));

        horizontalLayout_4->addWidget(pb_close);


        verticalLayout->addWidget(wdg_tittlt);

        wdg_content = new QWidget(chatDialog);
        wdg_content->setObjectName(QStringLiteral("wdg_content"));
        horizontalLayout = new QHBoxLayout(wdg_content);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_left = new QWidget(wdg_content);
        wdg_left->setObjectName(QStringLiteral("wdg_left"));
        verticalLayout_3 = new QVBoxLayout(wdg_left);
        verticalLayout_3->setSpacing(7);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        wdg_left_top = new QWidget(wdg_left);
        wdg_left_top->setObjectName(QStringLiteral("wdg_left_top"));
        verticalLayout_5 = new QVBoxLayout(wdg_left_top);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tb_chat = new QTextBrowser(wdg_left_top);
        tb_chat->setObjectName(QStringLiteral("tb_chat"));

        verticalLayout_5->addWidget(tb_chat);


        verticalLayout_3->addWidget(wdg_left_top);

        wdg_tools = new QWidget(wdg_left);
        wdg_tools->setObjectName(QStringLiteral("wdg_tools"));
        wdg_tools->setMinimumSize(QSize(560, 30));
        wdg_tools->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_2 = new QHBoxLayout(wdg_tools);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(6, 0, 0, 0);
        pb_tool2 = new QPushButton(wdg_tools);
        pb_tool2->setObjectName(QStringLiteral("pb_tool2"));
        pb_tool2->setMinimumSize(QSize(49, 30));
        pb_tool2->setMaximumSize(QSize(16777215, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/bq/0.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_tool2->setIcon(icon);
        pb_tool2->setIconSize(QSize(30, 30));
        pb_tool2->setFlat(true);

        horizontalLayout_2->addWidget(pb_tool2);

        pb_tool4 = new QPushButton(wdg_tools);
        pb_tool4->setObjectName(QStringLiteral("pb_tool4"));
        pb_tool4->setMinimumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/bq/003.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_tool4->setIcon(icon1);
        pb_tool4->setIconSize(QSize(30, 30));
        pb_tool4->setFlat(true);

        horizontalLayout_2->addWidget(pb_tool4);

        pb_tool1 = new QPushButton(wdg_tools);
        pb_tool1->setObjectName(QStringLiteral("pb_tool1"));
        pb_tool1->setMinimumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/bq/004.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_tool1->setIcon(icon2);
        pb_tool1->setIconSize(QSize(30, 30));
        pb_tool1->setFlat(true);

        horizontalLayout_2->addWidget(pb_tool1);

        pb_tool3 = new QPushButton(wdg_tools);
        pb_tool3->setObjectName(QStringLiteral("pb_tool3"));
        pb_tool3->setMinimumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/bq/011.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_tool3->setIcon(icon3);
        pb_tool3->setIconSize(QSize(30, 30));
        pb_tool3->setFlat(true);

        horizontalLayout_2->addWidget(pb_tool3);

        pb_tool5 = new QPushButton(wdg_tools);
        pb_tool5->setObjectName(QStringLiteral("pb_tool5"));
        pb_tool5->setMinimumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/bq/8.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_tool5->setIcon(icon4);
        pb_tool5->setIconSize(QSize(30, 30));
        pb_tool5->setFlat(true);

        horizontalLayout_2->addWidget(pb_tool5);

        horizontalSpacer = new QSpacerItem(295, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(wdg_tools);

        wdg_left_bottom = new QWidget(wdg_left);
        wdg_left_bottom->setObjectName(QStringLiteral("wdg_left_bottom"));
        wdg_left_bottom->setMinimumSize(QSize(571, 221));
        wdg_left_bottom->setMaximumSize(QSize(16777215, 221));
        verticalLayout_4 = new QVBoxLayout(wdg_left_bottom);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, 18, 0);
        te_chat = new QTextEdit(wdg_left_bottom);
        te_chat->setObjectName(QStringLiteral("te_chat"));

        verticalLayout_4->addWidget(te_chat);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(408, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pb_send = new QPushButton(wdg_left_bottom);
        pb_send->setObjectName(QStringLiteral("pb_send"));
        pb_send->setMinimumSize(QSize(75, 30));
        pb_send->setMaximumSize(QSize(75, 30));

        horizontalLayout_3->addWidget(pb_send);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(wdg_left_bottom);


        horizontalLayout->addWidget(wdg_left);

        wdg_right = new QWidget(wdg_content);
        wdg_right->setObjectName(QStringLiteral("wdg_right"));
        wdg_right->setMinimumSize(QSize(230, 561));
        wdg_right->setMaximumSize(QSize(230, 16777215));
        verticalLayout_2 = new QVBoxLayout(wdg_right);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tw_page = new QTabWidget(wdg_right);
        tw_page->setObjectName(QStringLiteral("tw_page"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        tw_page->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tw_page->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tw_page);


        horizontalLayout->addWidget(wdg_right);


        verticalLayout->addWidget(wdg_content);


        retranslateUi(chatDialog);

        tw_page->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(chatDialog);
    } // setupUi

    void retranslateUi(QDialog *chatDialog)
    {
        chatDialog->setWindowTitle(QApplication::translate("chatDialog", "Dialog", 0));
        lb_tittle->setText(QApplication::translate("chatDialog", "\344\270\216[name]\350\201\212\345\244\251", 0));
        pb_min->setText(QApplication::translate("chatDialog", "\344\270\200", 0));
        pb_max->setText(QApplication::translate("chatDialog", "\345\217\243", 0));
        pb_close->setText(QApplication::translate("chatDialog", "\303\227", 0));
        pb_tool2->setText(QString());
        pb_tool4->setText(QString());
        pb_tool1->setText(QString());
        pb_tool3->setText(QString());
        pb_tool5->setText(QString());
        pb_send->setText(QApplication::translate("chatDialog", "\345\217\221\351\200\201", 0));
        tw_page->setTabText(tw_page->indexOf(tab_1), QApplication::translate("chatDialog", "\345\261\236\346\200\2471", 0));
        tw_page->setTabText(tw_page->indexOf(tab_2), QApplication::translate("chatDialog", "\345\261\236\346\200\2472", 0));
    } // retranslateUi

};

namespace Ui {
    class chatDialog: public Ui_chatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
