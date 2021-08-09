#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include"customwidget.h"
namespace Ui {
class LoginDialog;
}

class LoginDialog : public /*QDialog*/CustomMoveDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
signals:
    void SIG_LoginCommit(QString name , QString password);   //登录信号
    void SIG_RegisterCommit(QString name , QString password);  //注册信号
private slots:
    void on_pb_clear_clicked();

    void on_pb_register_clear_clicked();

    void on_pb_commit_clicked();

    void on_pb_register_commit_clicked();

    void on_pb_close_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
