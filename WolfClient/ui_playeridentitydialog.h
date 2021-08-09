/********************************************************************************
** Form generated from reading UI file 'playeridentitydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERIDENTITYDIALOG_H
#define UI_PLAYERIDENTITYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PlayerIdentityDialog
{
public:
    QPushButton *pb_icon;
    QLabel *lb_identity;
    QPushButton *pushButton;

    void setupUi(QDialog *PlayerIdentityDialog)
    {
        if (PlayerIdentityDialog->objectName().isEmpty())
            PlayerIdentityDialog->setObjectName(QStringLiteral("PlayerIdentityDialog"));
        PlayerIdentityDialog->resize(328, 432);
        PlayerIdentityDialog->setMinimumSize(QSize(328, 432));
        PlayerIdentityDialog->setMaximumSize(QSize(328, 432));
        pb_icon = new QPushButton(PlayerIdentityDialog);
        pb_icon->setObjectName(QStringLiteral("pb_icon"));
        pb_icon->setGeometry(QRect(30, 70, 271, 341));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/civilian.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pb_icon->setIcon(icon);
        pb_icon->setIconSize(QSize(271, 341));
        pb_icon->setFlat(true);
        lb_identity = new QLabel(PlayerIdentityDialog);
        lb_identity->setObjectName(QStringLiteral("lb_identity"));
        lb_identity->setGeometry(QRect(40, 20, 241, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(20);
        lb_identity->setFont(font);
        pushButton = new QPushButton(PlayerIdentityDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 0, 30, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(13);
        pushButton->setFont(font1);

        retranslateUi(PlayerIdentityDialog);

        QMetaObject::connectSlotsByName(PlayerIdentityDialog);
    } // setupUi

    void retranslateUi(QDialog *PlayerIdentityDialog)
    {
        PlayerIdentityDialog->setWindowTitle(QApplication::translate("PlayerIdentityDialog", "Dialog", 0));
        pb_icon->setText(QString());
        lb_identity->setText(QApplication::translate("PlayerIdentityDialog", "\345\275\223\345\211\215\344\275\240\347\232\204\350\272\253\344\273\275\344\270\272\357\274\232", 0));
        pushButton->setText(QApplication::translate("PlayerIdentityDialog", "\303\227", 0));
    } // retranslateUi

};

namespace Ui {
    class PlayerIdentityDialog: public Ui_PlayerIdentityDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERIDENTITYDIALOG_H
