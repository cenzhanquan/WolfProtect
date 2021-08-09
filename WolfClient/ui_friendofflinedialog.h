/********************************************************************************
** Form generated from reading UI file 'friendofflinedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDOFFLINEDIALOG_H
#define UI_FRIENDOFFLINEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_FriendOfflineDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *lb_tittlt;

    void setupUi(QDialog *FriendOfflineDialog)
    {
        if (FriendOfflineDialog->objectName().isEmpty())
            FriendOfflineDialog->setObjectName(QStringLiteral("FriendOfflineDialog"));
        FriendOfflineDialog->resize(150, 100);
        FriendOfflineDialog->setMinimumSize(QSize(150, 100));
        FriendOfflineDialog->setMaximumSize(QSize(150, 100));
        QFont font;
        font.setPointSize(30);
        FriendOfflineDialog->setFont(font);
        horizontalLayout = new QHBoxLayout(FriendOfflineDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lb_tittlt = new QLabel(FriendOfflineDialog);
        lb_tittlt->setObjectName(QStringLiteral("lb_tittlt"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(30);
        lb_tittlt->setFont(font1);

        horizontalLayout->addWidget(lb_tittlt);


        retranslateUi(FriendOfflineDialog);

        QMetaObject::connectSlotsByName(FriendOfflineDialog);
    } // setupUi

    void retranslateUi(QDialog *FriendOfflineDialog)
    {
        FriendOfflineDialog->setWindowTitle(QApplication::translate("FriendOfflineDialog", "Dialog", 0));
        lb_tittlt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendOfflineDialog: public Ui_FriendOfflineDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDOFFLINEDIALOG_H
