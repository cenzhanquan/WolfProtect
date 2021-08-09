/********************************************************************************
** Form generated from reading UI file 'roomdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMDIALOG_H
#define UI_ROOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <videoitem.h>
#include "imtoolbox.h"

QT_BEGIN_NAMESPACE

class Ui_RoomDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_tittle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_tittle;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_min;
    QPushButton *pb_max;
    QPushButton *pb_close;
    QWidget *wdg_mid;
    QHBoxLayout *horizontalLayout;
    QWidget *wdg_left;
    QVBoxLayout *verticalLayout_2;
    VideoItem *wdg_video;
    IMToolBox *wdg_right;
    QWidget *wdg_bottom;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_Video;
    QPushButton *pb_Audio;
    QComboBox *cbx_tuzi;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_quit;

    void setupUi(QDialog *RoomDialog)
    {
        if (RoomDialog->objectName().isEmpty())
            RoomDialog->setObjectName(QStringLiteral("RoomDialog"));
        RoomDialog->resize(800, 600);
        RoomDialog->setMinimumSize(QSize(800, 600));
        RoomDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(RoomDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_tittle = new QWidget(RoomDialog);
        wdg_tittle->setObjectName(QStringLiteral("wdg_tittle"));
        wdg_tittle->setMinimumSize(QSize(800, 40));
        wdg_tittle->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(wdg_tittle);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lb_tittle = new QLabel(wdg_tittle);
        lb_tittle->setObjectName(QStringLiteral("lb_tittle"));
        lb_tittle->setMinimumSize(QSize(191, 30));
        lb_tittle->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        lb_tittle->setFont(font);
        lb_tittle->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lb_tittle);

        horizontalSpacer = new QSpacerItem(466, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pb_min = new QPushButton(wdg_tittle);
        pb_min->setObjectName(QStringLiteral("pb_min"));
        pb_min->setMinimumSize(QSize(30, 30));
        pb_min->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(20);
        pb_min->setFont(font1);

        horizontalLayout_2->addWidget(pb_min);

        pb_max = new QPushButton(wdg_tittle);
        pb_max->setObjectName(QStringLiteral("pb_max"));
        pb_max->setMinimumSize(QSize(30, 30));
        pb_max->setMaximumSize(QSize(30, 30));
        pb_max->setFont(font);

        horizontalLayout_2->addWidget(pb_max);

        pb_close = new QPushButton(wdg_tittle);
        pb_close->setObjectName(QStringLiteral("pb_close"));
        pb_close->setMinimumSize(QSize(30, 30));
        pb_close->setMaximumSize(QSize(30, 30));
        pb_close->setFont(font);

        horizontalLayout_2->addWidget(pb_close);


        verticalLayout->addWidget(wdg_tittle);

        wdg_mid = new QWidget(RoomDialog);
        wdg_mid->setObjectName(QStringLiteral("wdg_mid"));
        horizontalLayout = new QHBoxLayout(wdg_mid);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_left = new QWidget(wdg_mid);
        wdg_left->setObjectName(QStringLiteral("wdg_left"));
        verticalLayout_2 = new QVBoxLayout(wdg_left);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        wdg_video = new VideoItem(wdg_left);
        wdg_video->setObjectName(QStringLiteral("wdg_video"));

        verticalLayout_2->addWidget(wdg_video);


        horizontalLayout->addWidget(wdg_left);

        wdg_right = new IMToolBox(wdg_mid);
        wdg_right->setObjectName(QStringLiteral("wdg_right"));
        wdg_right->setMinimumSize(QSize(241, 521));
        wdg_right->setMaximumSize(QSize(241, 16777215));

        horizontalLayout->addWidget(wdg_right);


        verticalLayout->addWidget(wdg_mid);

        wdg_bottom = new QWidget(RoomDialog);
        wdg_bottom->setObjectName(QStringLiteral("wdg_bottom"));
        wdg_bottom->setMinimumSize(QSize(800, 40));
        wdg_bottom->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_3 = new QHBoxLayout(wdg_bottom);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pb_Video = new QPushButton(wdg_bottom);
        pb_Video->setObjectName(QStringLiteral("pb_Video"));
        pb_Video->setMinimumSize(QSize(151, 40));
        pb_Video->setMaximumSize(QSize(151, 40));
        pb_Video->setFont(font);

        horizontalLayout_3->addWidget(pb_Video);

        pb_Audio = new QPushButton(wdg_bottom);
        pb_Audio->setObjectName(QStringLiteral("pb_Audio"));
        pb_Audio->setMinimumSize(QSize(151, 40));
        pb_Audio->setMaximumSize(QSize(151, 40));
        pb_Audio->setFont(font);

        horizontalLayout_3->addWidget(pb_Audio);

        cbx_tuzi = new QComboBox(wdg_bottom);
        cbx_tuzi->setObjectName(QStringLiteral("cbx_tuzi"));
        cbx_tuzi->setMinimumSize(QSize(95, 40));
        cbx_tuzi->setMaximumSize(QSize(95, 40));
        cbx_tuzi->setFont(font);
        cbx_tuzi->setInsertPolicy(QComboBox::InsertAfterCurrent);
        cbx_tuzi->setDuplicatesEnabled(false);

        horizontalLayout_3->addWidget(cbx_tuzi);

        horizontalSpacer_2 = new QSpacerItem(279, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pb_quit = new QPushButton(wdg_bottom);
        pb_quit->setObjectName(QStringLiteral("pb_quit"));
        pb_quit->setMinimumSize(QSize(93, 40));
        pb_quit->setMaximumSize(QSize(93, 40));
        pb_quit->setFont(font);

        horizontalLayout_3->addWidget(pb_quit);


        verticalLayout->addWidget(wdg_bottom);


        retranslateUi(RoomDialog);

        QMetaObject::connectSlotsByName(RoomDialog);
    } // setupUi

    void retranslateUi(QDialog *RoomDialog)
    {
        RoomDialog->setWindowTitle(QApplication::translate("RoomDialog", "Dialog", 0));
        lb_tittle->setText(QApplication::translate("RoomDialog", "\346\210\277\351\227\264\345\217\267:00000000", 0));
        pb_min->setText(QApplication::translate("RoomDialog", "-", 0));
        pb_max->setText(QApplication::translate("RoomDialog", "\345\217\243", 0));
        pb_close->setText(QApplication::translate("RoomDialog", "\303\227", 0));
        pb_Video->setText(QApplication::translate("RoomDialog", "\346\211\223\345\274\200\350\247\206\351\242\221\350\256\276\345\244\207", 0));
        pb_Audio->setText(QApplication::translate("RoomDialog", "\346\211\223\345\274\200\351\237\263\351\242\221\350\256\276\345\244\207", 0));
        cbx_tuzi->clear();
        cbx_tuzi->insertItems(0, QStringList()
         << QApplication::translate("RoomDialog", "\346\227\240\346\273\244\351\225\234", 0)
         << QApplication::translate("RoomDialog", "\345\205\224\350\200\263\346\234\265", 0)
         << QApplication::translate("RoomDialog", "\345\234\243\350\257\236\345\270\275\345\255\220", 0)
        );
        pb_quit->setText(QApplication::translate("RoomDialog", "\347\246\273\345\274\200\346\210\277\351\227\264", 0));
    } // retranslateUi

};

namespace Ui {
    class RoomDialog: public Ui_RoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMDIALOG_H
