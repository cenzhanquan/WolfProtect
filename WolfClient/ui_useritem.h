/********************************************************************************
** Form generated from reading UI file 'useritem.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERITEM_H
#define UI_USERITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserItem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_icon;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *lb_name;
    QLabel *lb_feeling;

    void setupUi(QWidget *UserItem)
    {
        if (UserItem->objectName().isEmpty())
            UserItem->setObjectName(QStringLiteral("UserItem"));
        UserItem->resize(290, 61);
        UserItem->setMinimumSize(QSize(290, 60));
        UserItem->setMaximumSize(QSize(10000000, 61));
        UserItem->setStyleSheet(QLatin1String("QWidget:hover{ background-color: rgb(214, 214, 214);}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(UserItem);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(UserItem);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 1, 0, 0);
        pb_icon = new QPushButton(widget);
        pb_icon->setObjectName(QStringLiteral("pb_icon"));
        pb_icon->setMinimumSize(QSize(40, 40));
        pb_icon->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/tx/7.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_icon->setIcon(icon);
        pb_icon->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(pb_icon);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(241, 60));
        widget_2->setMaximumSize(QSize(16777215, 60));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 5, -1, 5);
        lb_name = new QLabel(widget_2);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setMinimumSize(QSize(54, 20));
        lb_name->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(12);
        lb_name->setFont(font);

        verticalLayout->addWidget(lb_name);

        lb_feeling = new QLabel(widget_2);
        lb_feeling->setObjectName(QStringLiteral("lb_feeling"));
        lb_feeling->setMinimumSize(QSize(54, 20));
        lb_feeling->setMaximumSize(QSize(16777215, 20));
        lb_feeling->setFont(font);

        verticalLayout->addWidget(lb_feeling);


        horizontalLayout->addWidget(widget_2);


        horizontalLayout_2->addWidget(widget);


        retranslateUi(UserItem);

        QMetaObject::connectSlotsByName(UserItem);
    } // setupUi

    void retranslateUi(QWidget *UserItem)
    {
        UserItem->setWindowTitle(QApplication::translate("UserItem", "Form", 0));
        pb_icon->setText(QString());
        lb_name->setText(QApplication::translate("UserItem", "\345\247\223\345\220\215", 0));
        lb_feeling->setText(QApplication::translate("UserItem", "\346\257\224\350\276\203\346\207\222", 0));
    } // retranslateUi

};

namespace Ui {
    class UserItem: public Ui_UserItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERITEM_H
