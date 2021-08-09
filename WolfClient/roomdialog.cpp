#include "roomdialog.h"
#include "ui_roomdialog.h"
RoomDialog::RoomDialog(QWidget *parent) :
    /*QDialog*/CustomMoveDialog(parent),
    ui(new Ui::RoomDialog)
{
    ui->setupUi(this);

    m_videoList=new IMToolList("房间成员");
    ui->wdg_right->addItem(m_videoList);


    clear();

}

RoomDialog::~RoomDialog()
{
    delete ui;
}
#include<QMessageBox>
//离开房间
void RoomDialog::on_pb_quit_clicked()
{
    if(m_roomid==0)
    {
        QMessageBox::about(this,"提示","还没加入房间");
        return ;

    }
    if(QMessageBox::question(this,"提示","确定要退出房间吗?")==QMessageBox::No)return ;

    //清空
     clear();

     //发送信号
     Q_EMIT SIG_quitRoom(m_roomid);

     this->hide();

}
//设置信息
void RoomDialog::slot_setInfo(int id)
{
    m_roomid=id;
    ui->lb_tittle->setText(QString("房间号:%1").arg(m_roomid));
}
//清空
void RoomDialog::clear()
{
    ui->lb_tittle->setText(QString("房间号:-----"));
    ui->pb_Audio->setText("打开音频设备");
    ui->pb_Video->setText("打开视频设备");

    m_roomid=0;
}
//点击打开视屏
void RoomDialog::on_pb_Video_clicked()
{
    if(ui->pb_Video->text()=="打开视频设备")
    {
        //打开
        Q_EMIT SIG_openVideoDev();

        ui->pb_Video->setText("关闭视频设备");
    }
    else
    {
        //close
        Q_EMIT SIG_closeVideoDev();

        ui->pb_Video->setText("打开视频设备");
    }
}
//点击打开音频
void RoomDialog::on_pb_Audio_clicked()
{

    if(ui->pb_Audio->text()=="打开音频设备")
    {
        //打开
        Q_EMIT SIG_openAudioDev();

        ui->pb_Audio->setText("关闭音频设备");
    }
    else
    {
        //close
        Q_EMIT SIG_closeAudioDev();

        ui->pb_Audio->setText("打开音频设备");
    }
}
//打开滤镜
void RoomDialog::on_cbx_tuzi_currentIndexChanged(const QString &arg1)
{
    if(arg1=="无滤镜")
    {
        Q_EMIT SIG_setMoji(0);
    }
    else if(arg1=="兔耳朵")
    {
         Q_EMIT SIG_setMoji(1);
    }
    else if(arg1=="圣诞帽")
    {
         Q_EMIT SIG_setMoji(2);
    }
}
//处理点击  ×  事件
void RoomDialog::on_pb_close_clicked()
{
    on_pb_quit_clicked();
}
//在右侧添加videoitem小窗口功能
void RoomDialog::slot_addVideoItem(VideoItem *item)
{
    m_videoList->addItem(item);
}
//清除右侧videoitem小窗口
void RoomDialog::slot_removeVideoItem(VideoItem *item)
{
    m_videoList->removeItem(item);
}
//设置大窗口的ID
void RoomDialog::slot_setBigImageID(int id,QString name)
{

     ui->wdg_video->setInfo(id,name);
}
//获取大窗口的ID
int RoomDialog::slot_getBigImageID()
{
    return ui->wdg_video->m_id;

}

Ui::RoomDialog *RoomDialog::getUi() const
{
    return ui;
}
