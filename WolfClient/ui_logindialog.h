/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QTabWidget *tw_page;
    QWidget *tab_1;
    QLabel *lb_name;
    QLabel *lb_password;
    QLineEdit *le_name;
    QLineEdit *le_password;
    QPushButton *pb_clear;
    QPushButton *pb_commit;
    QWidget *tab_2;
    QLineEdit *le_register_name;
    QLabel *lb_register_name;
    QLineEdit *le_register_password;
    QLabel *lb_register_password;
    QLabel *lb_register_confirm;
    QLineEdit *le_register_confirm;
    QPushButton *pb_register_clear;
    QPushButton *pb_register_commit;
    QLabel *lb_icon;
    QPushButton *pb_close;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(618, 289);
        QFont font;
        font.setPointSize(12);
        LoginDialog->setFont(font);
        tw_page = new QTabWidget(LoginDialog);
        tw_page->setObjectName(QStringLiteral("tw_page"));
        tw_page->setGeometry(QRect(190, 10, 431, 281));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        lb_name = new QLabel(tab_1);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setGeometry(QRect(30, 30, 61, 31));
        lb_password = new QLabel(tab_1);
        lb_password->setObjectName(QStringLiteral("lb_password"));
        lb_password->setGeometry(QRect(30, 90, 54, 30));
        le_name = new QLineEdit(tab_1);
        le_name->setObjectName(QStringLiteral("le_name"));
        le_name->setGeometry(QRect(110, 30, 271, 30));
        le_password = new QLineEdit(tab_1);
        le_password->setObjectName(QStringLiteral("le_password"));
        le_password->setGeometry(QRect(110, 90, 271, 30));
        le_password->setEchoMode(QLineEdit::Password);
        pb_clear = new QPushButton(tab_1);
        pb_clear->setObjectName(QStringLiteral("pb_clear"));
        pb_clear->setGeometry(QRect(190, 210, 75, 30));
        pb_commit = new QPushButton(tab_1);
        pb_commit->setObjectName(QStringLiteral("pb_commit"));
        pb_commit->setGeometry(QRect(300, 210, 75, 30));
        tw_page->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        le_register_name = new QLineEdit(tab_2);
        le_register_name->setObjectName(QStringLiteral("le_register_name"));
        le_register_name->setGeometry(QRect(110, 30, 271, 30));
        lb_register_name = new QLabel(tab_2);
        lb_register_name->setObjectName(QStringLiteral("lb_register_name"));
        lb_register_name->setGeometry(QRect(30, 30, 61, 31));
        le_register_password = new QLineEdit(tab_2);
        le_register_password->setObjectName(QStringLiteral("le_register_password"));
        le_register_password->setGeometry(QRect(110, 90, 271, 30));
        le_register_password->setEchoMode(QLineEdit::Password);
        lb_register_password = new QLabel(tab_2);
        lb_register_password->setObjectName(QStringLiteral("lb_register_password"));
        lb_register_password->setGeometry(QRect(30, 90, 54, 30));
        lb_register_confirm = new QLabel(tab_2);
        lb_register_confirm->setObjectName(QStringLiteral("lb_register_confirm"));
        lb_register_confirm->setGeometry(QRect(30, 150, 54, 30));
        le_register_confirm = new QLineEdit(tab_2);
        le_register_confirm->setObjectName(QStringLiteral("le_register_confirm"));
        le_register_confirm->setGeometry(QRect(110, 150, 271, 30));
        le_register_confirm->setEchoMode(QLineEdit::Password);
        pb_register_clear = new QPushButton(tab_2);
        pb_register_clear->setObjectName(QStringLiteral("pb_register_clear"));
        pb_register_clear->setGeometry(QRect(190, 210, 75, 30));
        pb_register_commit = new QPushButton(tab_2);
        pb_register_commit->setObjectName(QStringLiteral("pb_register_commit"));
        pb_register_commit->setGeometry(QRect(300, 210, 75, 30));
        tw_page->addTab(tab_2, QString());
        lb_icon = new QLabel(LoginDialog);
        lb_icon->setObjectName(QStringLiteral("lb_icon"));
        lb_icon->setGeometry(QRect(0, 10, 191, 281));
        lb_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/desk.jpg")));
        lb_icon->setScaledContents(true);
        lb_icon->setAlignment(Qt::AlignCenter);
        pb_close = new QPushButton(LoginDialog);
        pb_close->setObjectName(QStringLiteral("pb_close"));
        pb_close->setGeometry(QRect(579, 0, 41, 31));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb_close->sizePolicy().hasHeightForWidth());
        pb_close->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(12);
        pb_close->setFont(font1);
        pb_close->setFocusPolicy(Qt::StrongFocus);
        pb_close->setContextMenuPolicy(Qt::NoContextMenu);
        pb_close->setLayoutDirection(Qt::LeftToRight);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_close->setIcon(icon);
        QWidget::setTabOrder(tw_page, le_name);
        QWidget::setTabOrder(le_name, le_password);
        QWidget::setTabOrder(le_password, pb_commit);
        QWidget::setTabOrder(pb_commit, pb_clear);
        QWidget::setTabOrder(pb_clear, le_register_name);
        QWidget::setTabOrder(le_register_name, le_register_password);
        QWidget::setTabOrder(le_register_password, le_register_confirm);
        QWidget::setTabOrder(le_register_confirm, pb_register_commit);
        QWidget::setTabOrder(pb_register_commit, pb_register_clear);

        retranslateUi(LoginDialog);

        tw_page->setCurrentIndex(0);
        pb_close->setDefault(false);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", 0));
        lb_name->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", 0));
        lb_password->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", 0));
#ifndef QT_NO_TOOLTIP
        le_name->setToolTip(QApplication::translate("LoginDialog", " \350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\346\210\226\345\257\206\347\240\201,  \351\225\277\345\272\246\344\270\215\350\266\205\350\277\20710 \344\275\215 ", 0));
#endif // QT_NO_TOOLTIP
        le_password->setText(QString());
        pb_clear->setText(QApplication::translate("LoginDialog", "\346\270\205\347\251\272", 0));
        pb_commit->setText(QApplication::translate("LoginDialog", "\346\217\220\344\272\244", 0));
        tw_page->setTabText(tw_page->indexOf(tab_1), QApplication::translate("LoginDialog", "  \347\231\273\345\275\225  ", 0));
        lb_register_name->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", 0));
        le_register_password->setText(QString());
        lb_register_password->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", 0));
        lb_register_confirm->setText(QApplication::translate("LoginDialog", "\347\241\256\350\256\244", 0));
        le_register_confirm->setText(QString());
        pb_register_clear->setText(QApplication::translate("LoginDialog", "\346\270\205\347\251\272", 0));
        pb_register_commit->setText(QApplication::translate("LoginDialog", "\346\217\220\344\272\244", 0));
        tw_page->setTabText(tw_page->indexOf(tab_2), QApplication::translate("LoginDialog", "  \346\263\250\345\206\214  ", 0));
        lb_icon->setText(QString());
        pb_close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
