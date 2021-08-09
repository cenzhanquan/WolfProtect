#include "chatdialog.h"
#include "ui_chatdialog.h"

chatDialog::chatDialog(QWidget *parent) :
    /*QDialog*/CustomMoveDialog(parent),
    ui(new Ui::chatDialog),m_id(0)
{
    ui->setupUi(this);
}

chatDialog::~chatDialog()
{
    delete ui;
}

void chatDialog::setInfo(int id, QString name)
{
    m_id=id;
    m_name=name;



    ui->lb_tittle->setText( QString("正在与[%1]的聊天").arg(m_name.toStdString().c_str()));
}
#include<QTime>
//发送聊天
void chatDialog::on_pb_send_clicked()
{
    QString content=ui->te_chat->toPlainText();
    if(content.isEmpty())return ;

    ui->tb_chat->append(QString("[我]%1").arg(QTime::currentTime().toString("hh::mm::ss")));
    ui->tb_chat->append(content);


    ui->te_chat->clear();

    //抛出 信号
    Q_EMIT SIG_SendChatMsg(m_id,content);
}
//接收聊天内容
void chatDialog::slot_recvChatMsg(QString content)
{
    ui->tb_chat->append(QString("[%1] %2").arg(m_name).arg(QTime::currentTime().toString("hh::mm::ss")));

    ui->tb_chat->append(content);
}
//发送聊天信息时对方离线  要显示对方离线
void chatDialog::slot_showOffline()
{
    ui->tb_chat->append(QString("用户[%1] 已离线").arg(m_name));

}
//最小化
void chatDialog::on_pb_min_clicked()
{
    this->slot_showMin();
}
//最大化
void chatDialog::on_pb_max_clicked()
{
    this->slot_showMax();
}
//关闭
void chatDialog::on_pb_close_clicked()
{
    this->slot_close();
}
