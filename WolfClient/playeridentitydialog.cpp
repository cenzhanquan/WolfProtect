#include "playeridentitydialog.h"
#include "ui_playeridentitydialog.h"

PlayerIdentityDialog::PlayerIdentityDialog(QWidget *parent) :
    /*QDialog*/CustomMoveDialog(parent),
    ui(new Ui::PlayerIdentityDialog)
{
    ui->setupUi(this);
}

PlayerIdentityDialog::~PlayerIdentityDialog()
{
    delete ui;
}
//设置玩家身份
void PlayerIdentityDialog::setPlayerIdentity(int Identity)
{
    switch(Identity)
    {
    case 2021:
        ui->lb_identity->setText(QString("当前你的身份牌为:平民"));
        ui->pb_icon->setIcon(QIcon(QString(":/images/civilian.jpg")));   //设置为平民的头像
        this->repaint();  //重绘
        break;
    case 2022:
        ui->lb_identity->setText(QString("当前你的身份牌为:预言家"));
        ui->pb_icon->setIcon(QIcon(QString(":/images/prophet.jpg")));
        this->repaint();  //重绘
        break;
    case 2023:
        ui->lb_identity->setText(QString("当前你的身份牌为:猎人"));
        ui->pb_icon->setIcon(QIcon(QString(":/images/hunter.jpg")));
        this->repaint();  //重绘
        break;
    case 2024:
        ui->lb_identity->setText(QString("当前你的身份牌为:女巫"));
        ui->pb_icon->setIcon(QIcon(QString(":/images/witch.jpg")));
        this->repaint();  //重绘
        break;
    case 2025:
        ui->lb_identity->setText(QString("当前你的身份牌为:狼人"));
        ui->pb_icon->setIcon(QIcon(QString(":/images/werwolf.jpg")));
        this->repaint();  //重绘
        break;
    case 2026:
        ui->lb_identity->setText(QString("当前你的身份牌为:死人"));
        ui->pb_icon->setIcon(QIcon(QString(":/images/death2.jpg")));
        this->repaint();  //重绘
        break;
    case 2027:
        ui->lb_identity->setText(QString("当前你的身份牌为:透明人"));
        ui->pb_icon->setIcon(QIcon(QString(":/images/Help.png")));
        this->repaint();  //重绘
        break;
    default:break;
    }
}

void PlayerIdentityDialog::on_pushButton_clicked()
{
    this->slot_close();
}
