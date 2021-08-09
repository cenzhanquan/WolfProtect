#include "friendofflinedialog.h"
#include "ui_friendofflinedialog.h"

FriendOfflineDialog::FriendOfflineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendOfflineDialog)
{
    ui->setupUi(this);
}

FriendOfflineDialog::~FriendOfflineDialog()
{
    delete ui;
}
//设置窗口信息
void FriendOfflineDialog::SetInfo(QString name)
{
    ui->lb_tittlt->setText(name);
}
