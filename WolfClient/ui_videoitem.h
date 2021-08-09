/********************************************************************************
** Form generated from reading UI file 'videoitem.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOITEM_H
#define UI_VIDEOITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoItem
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lb_name;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *VideoItem)
    {
        if (VideoItem->objectName().isEmpty())
            VideoItem->setObjectName(QStringLiteral("VideoItem"));
        VideoItem->resize(190, 150);
        VideoItem->setMinimumSize(QSize(190, 150));
        VideoItem->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(VideoItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lb_name = new QLabel(VideoItem);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setMinimumSize(QSize(0, 20));
        lb_name->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        lb_name->setFont(font);
        lb_name->setStyleSheet(QStringLiteral(""));
        lb_name->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_name);

        verticalSpacer = new QSpacerItem(20, 127, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(VideoItem);

        QMetaObject::connectSlotsByName(VideoItem);
    } // setupUi

    void retranslateUi(QWidget *VideoItem)
    {
        VideoItem->setWindowTitle(QApplication::translate("VideoItem", "Form", 0));
        lb_name->setText(QApplication::translate("VideoItem", "\347\224\250\346\210\267\345\220\215:--", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoItem: public Ui_VideoItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOITEM_H
