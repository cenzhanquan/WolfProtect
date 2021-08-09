/********************************************************************************
** Form generated from reading UI file 'myqqdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYQQDIALOG_H
#define UI_MYQQDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imtoolbox.h"

QT_BEGIN_NAMESPACE

class Ui_MyQQDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_tittle;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_tittle;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_min;
    QPushButton *pb_close;
    QWidget *wdg_top;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_icon;
    QWidget *wdg_right;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *cbx_state;
    QLabel *lb_name;
    QLineEdit *le_feeling;
    QWidget *wdg_search;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pb_search;
    QLineEdit *le_search;
    QWidget *wdg_mid;
    QVBoxLayout *verticalLayout_3;
    QWidget *wdg_page;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pb_friend;
    QPushButton *pb_group;
    QPushButton *pb_space;
    QStackedWidget *sw_page;
    QWidget *page_1;
    QVBoxLayout *verticalLayout_4;
    IMToolBox *wdg_box;
    QWidget *page_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pb_menu;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_test3;
    QPushButton *pb_test2;
    QPushButton *pb_test;

    void setupUi(QDialog *MyQQDialog)
    {
        if (MyQQDialog->objectName().isEmpty())
            MyQQDialog->setObjectName(QStringLiteral("MyQQDialog"));
        MyQQDialog->resize(300, 630);
        MyQQDialog->setMinimumSize(QSize(300, 630));
        MyQQDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(MyQQDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 3, 0, 3);
        wdg_tittle = new QWidget(MyQQDialog);
        wdg_tittle->setObjectName(QStringLiteral("wdg_tittle"));
        wdg_tittle->setMinimumSize(QSize(301, 41));
        wdg_tittle->setMaximumSize(QSize(16777215, 41));
        horizontalLayout = new QHBoxLayout(wdg_tittle);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        lb_tittle = new QLabel(wdg_tittle);
        lb_tittle->setObjectName(QStringLiteral("lb_tittle"));
        lb_tittle->setMinimumSize(QSize(54, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(10);
        lb_tittle->setFont(font);

        horizontalLayout->addWidget(lb_tittle);

        horizontalSpacer = new QSpacerItem(136, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_min = new QPushButton(wdg_tittle);
        pb_min->setObjectName(QStringLiteral("pb_min"));
        pb_min->setMinimumSize(QSize(30, 30));
        pb_min->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        pb_min->setFont(font1);

        horizontalLayout->addWidget(pb_min);

        pb_close = new QPushButton(wdg_tittle);
        pb_close->setObjectName(QStringLiteral("pb_close"));
        pb_close->setMinimumSize(QSize(30, 30));
        pb_close->setMaximumSize(QSize(30, 30));
        pb_close->setFont(font1);

        horizontalLayout->addWidget(pb_close);


        verticalLayout->addWidget(wdg_tittle);

        wdg_top = new QWidget(MyQQDialog);
        wdg_top->setObjectName(QStringLiteral("wdg_top"));
        wdg_top->setMinimumSize(QSize(301, 81));
        wdg_top->setMaximumSize(QSize(16777215, 81));
        horizontalLayout_3 = new QHBoxLayout(wdg_top);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 0);
        pb_icon = new QPushButton(wdg_top);
        pb_icon->setObjectName(QStringLiteral("pb_icon"));
        pb_icon->setMinimumSize(QSize(60, 60));
        pb_icon->setMaximumSize(QSize(60, 60));
        QIcon icon;
        icon.addFile(QStringLiteral(":/tx/5.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_icon->setIcon(icon);
        pb_icon->setIconSize(QSize(60, 60));
        pb_icon->setFlat(true);

        horizontalLayout_3->addWidget(pb_icon);

        wdg_right = new QWidget(wdg_top);
        wdg_right->setObjectName(QStringLiteral("wdg_right"));
        wdg_right->setMinimumSize(QSize(0, 80));
        wdg_right->setMaximumSize(QSize(16777215, 80));
        verticalLayout_2 = new QVBoxLayout(wdg_right);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 0, 5, 10);
        widget_6 = new QWidget(wdg_right);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(0, 41));
        widget_6->setMaximumSize(QSize(16777215, 41));
        horizontalLayout_2 = new QHBoxLayout(widget_6);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, -1, -1, -1);
        cbx_state = new QComboBox(widget_6);
        cbx_state->setObjectName(QStringLiteral("cbx_state"));
        cbx_state->setMinimumSize(QSize(60, 30));
        cbx_state->setMaximumSize(QSize(60, 30));
        QFont font2;
        font2.setPointSize(12);
        cbx_state->setFont(font2);

        horizontalLayout_2->addWidget(cbx_state);

        lb_name = new QLabel(widget_6);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setMinimumSize(QSize(0, 30));
        lb_name->setMaximumSize(QSize(16777215, 30));
        lb_name->setFont(font2);

        horizontalLayout_2->addWidget(lb_name);


        verticalLayout_2->addWidget(widget_6);

        le_feeling = new QLineEdit(wdg_right);
        le_feeling->setObjectName(QStringLiteral("le_feeling"));
        le_feeling->setMinimumSize(QSize(0, 30));
        le_feeling->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(le_feeling);


        horizontalLayout_3->addWidget(wdg_right);


        verticalLayout->addWidget(wdg_top);

        wdg_search = new QWidget(MyQQDialog);
        wdg_search->setObjectName(QStringLiteral("wdg_search"));
        wdg_search->setMinimumSize(QSize(301, 41));
        wdg_search->setMaximumSize(QSize(16777215, 41));
        horizontalLayout_4 = new QHBoxLayout(wdg_search);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, 9);
        pb_search = new QPushButton(wdg_search);
        pb_search->setObjectName(QStringLiteral("pb_search"));
        pb_search->setMinimumSize(QSize(30, 30));
        pb_search->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/searchbox_button.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_search->setIcon(icon1);
        pb_search->setIconSize(QSize(30, 30));

        horizontalLayout_4->addWidget(pb_search);

        le_search = new QLineEdit(wdg_search);
        le_search->setObjectName(QStringLiteral("le_search"));
        le_search->setMinimumSize(QSize(0, 30));
        le_search->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(le_search);


        verticalLayout->addWidget(wdg_search);

        wdg_mid = new QWidget(MyQQDialog);
        wdg_mid->setObjectName(QStringLiteral("wdg_mid"));
        wdg_mid->setMinimumSize(QSize(301, 400));
        verticalLayout_3 = new QVBoxLayout(wdg_mid);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        wdg_page = new QWidget(wdg_mid);
        wdg_page->setObjectName(QStringLiteral("wdg_page"));
        wdg_page->setMinimumSize(QSize(301, 30));
        wdg_page->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_6 = new QHBoxLayout(wdg_page);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pb_friend = new QPushButton(wdg_page);
        pb_friend->setObjectName(QStringLiteral("pb_friend"));
        pb_friend->setMinimumSize(QSize(100, 30));
        pb_friend->setMaximumSize(QSize(16777215, 30));
        pb_friend->setFont(font2);
        pb_friend->setCheckable(true);
        pb_friend->setChecked(true);
        pb_friend->setFlat(true);

        horizontalLayout_6->addWidget(pb_friend);

        pb_group = new QPushButton(wdg_page);
        pb_group->setObjectName(QStringLiteral("pb_group"));
        pb_group->setMinimumSize(QSize(100, 30));
        pb_group->setMaximumSize(QSize(16777215, 30));
        pb_group->setFont(font2);
        pb_group->setCheckable(true);
        pb_group->setFlat(true);

        horizontalLayout_6->addWidget(pb_group);

        pb_space = new QPushButton(wdg_page);
        pb_space->setObjectName(QStringLiteral("pb_space"));
        pb_space->setMinimumSize(QSize(100, 30));
        pb_space->setMaximumSize(QSize(16777215, 30));
        pb_space->setFont(font2);
        pb_space->setCheckable(true);
        pb_space->setChecked(false);
        pb_space->setFlat(true);

        horizontalLayout_6->addWidget(pb_space);


        verticalLayout_3->addWidget(wdg_page);

        sw_page = new QStackedWidget(wdg_mid);
        sw_page->setObjectName(QStringLiteral("sw_page"));
        page_1 = new QWidget();
        page_1->setObjectName(QStringLiteral("page_1"));
        verticalLayout_4 = new QVBoxLayout(page_1);
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        wdg_box = new IMToolBox(page_1);
        wdg_box->setObjectName(QStringLiteral("wdg_box"));

        verticalLayout_4->addWidget(wdg_box);

        sw_page->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        sw_page->addWidget(page_2);

        verticalLayout_3->addWidget(sw_page);


        verticalLayout->addWidget(wdg_mid);

        widget_4 = new QWidget(MyQQDialog);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(301, 41));
        widget_4->setMaximumSize(QSize(16777215, 41));
        horizontalLayout_5 = new QHBoxLayout(widget_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pb_menu = new QPushButton(widget_4);
        pb_menu->setObjectName(QStringLiteral("pb_menu"));
        pb_menu->setMinimumSize(QSize(30, 30));
        pb_menu->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/message.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_menu->setIcon(icon2);
        pb_menu->setIconSize(QSize(30, 30));
        pb_menu->setFlat(true);

        horizontalLayout_5->addWidget(pb_menu);

        horizontalSpacer_2 = new QSpacerItem(136, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        pb_test3 = new QPushButton(widget_4);
        pb_test3->setObjectName(QStringLiteral("pb_test3"));
        pb_test3->setMinimumSize(QSize(100, 30));
        pb_test3->setMaximumSize(QSize(100, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        pb_test3->setFont(font3);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_test3->setIcon(icon3);

        horizontalLayout_5->addWidget(pb_test3);

        pb_test2 = new QPushButton(widget_4);
        pb_test2->setObjectName(QStringLiteral("pb_test2"));
        pb_test2->setMinimumSize(QSize(100, 30));
        pb_test2->setMaximumSize(QSize(100, 30));
        pb_test2->setFont(font3);
        pb_test2->setIcon(icon3);

        horizontalLayout_5->addWidget(pb_test2);

        pb_test = new QPushButton(widget_4);
        pb_test->setObjectName(QStringLiteral("pb_test"));
        pb_test->setMinimumSize(QSize(30, 30));
        pb_test->setMaximumSize(QSize(30, 30));
        pb_test->setIcon(icon3);

        horizontalLayout_5->addWidget(pb_test);


        verticalLayout->addWidget(widget_4);


        retranslateUi(MyQQDialog);

        sw_page->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyQQDialog);
    } // setupUi

    void retranslateUi(QDialog *MyQQDialog)
    {
        MyQQDialog->setWindowTitle(QApplication::translate("MyQQDialog", "MyQQDialog", 0));
        lb_tittle->setText(QApplication::translate("MyQQDialog", "\347\213\274\344\272\272\346\235\200", 0));
        pb_min->setText(QApplication::translate("MyQQDialog", "\344\270\200", 0));
        pb_close->setText(QApplication::translate("MyQQDialog", "X", 0));
        pb_icon->setText(QString());
        cbx_state->clear();
        cbx_state->insertItems(0, QStringList()
         << QApplication::translate("MyQQDialog", "\345\234\250\347\272\277", 0)
         << QApplication::translate("MyQQDialog", "\347\246\273\347\272\277", 0)
         << QApplication::translate("MyQQDialog", "\345\277\231\347\242\214", 0)
        );
        lb_name->setText(QApplication::translate("MyQQDialog", "\351\232\224\345\243\201\350\200\201\347\216\213", 0));
        pb_search->setText(QString());
        pb_friend->setText(QApplication::translate("MyQQDialog", "\345\245\275\345\217\213", 0));
        pb_group->setText(QString());
        pb_space->setText(QString());
        pb_menu->setText(QString());
        pb_test3->setText(QApplication::translate("MyQQDialog", "\345\210\233\345\273\272\346\210\277\351\227\264", 0));
        pb_test2->setText(QApplication::translate("MyQQDialog", "\345\212\240\345\205\245\346\210\277\351\227\264", 0));
        pb_test->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyQQDialog: public Ui_MyQQDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQQDIALOG_H
