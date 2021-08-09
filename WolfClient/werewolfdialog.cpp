#include "werewolfdialog.h"
#include "ui_werewolfdialog.h"
#include<QPalette>
#include<QMessageBox>
WerewolfDialog::WerewolfDialog(QWidget *parent) :
    /*QDialog*/CustomMoveDialog(parent),m_wolfRoomID(0),m_gameDays(0),m_false(0),m_playerSeatID(-1),m_praptefalse(0),
    m_GameTime(0),false_dicussion(0),false_death(0),false_DarkOver(0),
    ui(new Ui::WerewolfDialog)
{
    ui->setupUi(this);


    //定时器
    m_Time=new QTimer(this);

    connect(m_Time,&QTimer::timeout,this,&WerewolfDialog::SetTimeDate);

    //设置背景
    QPalette pal=this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/images/background.jpg")));
    setPalette(pal);

    this->repaint();  //直接调用重绘事件


    //游戏规则手册
    m_GameRule=new GameRuleDialog;



    //对每个控件进行绑定   方便判断 事件 然后对其进行不同的处理

    btn[0]=ui->pb_player1;
    btn[1]=ui->pb_player2;
    btn[2]=ui->pb_player3;
    btn[3]=ui->pb_player4;
    btn[4]=ui->pb_player5;
    btn[5]=ui->pb_player6;
    btn[6]=ui->pb_player7;
    btn[7]=ui->pb_player8;



    prepare[0]=ui->pb_prepare1;
    prepare[1]=ui->pb_prepare2;
    prepare[2]=ui->pb_prepare3;
    prepare[3]=ui->pb_prepare4;
    prepare[4]=ui->pb_prepare5;
    prepare[5]=ui->pb_prepare6;
    prepare[6]=ui->pb_prepare7;
    prepare[7]=ui->pb_prepare8;

    for(int i=0;i<8;i++)
    {
        connect(btn[i],SIGNAL(clicked()),this,SLOT(btnclick()));
    }

}

WerewolfDialog::~WerewolfDialog()
{
    delete ui;
    if(m_GameRule)
    {
        delete m_GameRule;
        m_GameRule=NULL;
    }
}
//点击×退出房间
void WerewolfDialog::on_pushButton_23_clicked()
{
    on_pushButton_37_clicked();  //调用离开房间按钮事件
}
//重绘事件
void WerewolfDialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/images/background.jpg"),QRect());
}
//设置当前玩家信息
void WerewolfDialog::setInfo(int roomid,int playerID)
{
    m_wolfRoomID=roomid;


    m_playerID=playerID;

    ui->pb_roomid->setText(QString("房间号:%1").arg(m_wolfRoomID));


}
//设置当前玩家的身份牌
void WerewolfDialog::SetIdentity(int Identity)
{
    m_yourIdentity=Identity;
    switch(Identity)
    {
    case 2021:
        ui->pb_identity->setText(QString("当前你的身份牌为:平民"));
        RecvAnnunciateMsg(QString("当前你的身份牌为:平民"));
        break;
    case 2022:
        ui->pb_identity->setText(QString("当前你的身份牌为:预言家"));
         RecvAnnunciateMsg(QString("当前你的身份牌为:预言家"));
        break;
    case 2023:
        ui->pb_identity->setText(QString("当前你的身份牌为:猎人"));
         RecvAnnunciateMsg(QString("当前你的身份牌为:猎人"));
        break;
    case 2024:
        ui->pb_identity->setText(QString("当前你的身份牌为:女巫"));
         RecvAnnunciateMsg(QString("当前你的身份牌为:女巫"));
        break;
    case 2025:
        ui->pb_identity->setText(QString("当前你的身份牌为:狼人"));
         RecvAnnunciateMsg(QString("当前你的身份牌为:狼人"));
        break;
    case 2026:
        ui->pb_identity->setText(QString("当前你的身份牌为:死人"));
         RecvAnnunciateMsg(QString("当前你的身份牌为:死人"));
        break;
    case 2027:
        ui->pb_identity->setText(QString("当前你的身份牌为:透明人"));
         RecvAnnunciateMsg(QString("当前你的身份牌为:透明人"));
        break;
    default:break;
    }
}
//设置游戏天数
void WerewolfDialog::SetGameDays(int days)
{
     m_gameDays=days;
     ui->pb_days->setText(QString("游戏天数:%1").arg(m_gameDays));
}
//处理玩家死后禁用所有的按钮组件
void WerewolfDialog::SetDEADPERSONToDo()
{
    ui->pb_audio->hide();       //禁用语音键

    ui->pb_invitefriends->hide();  //禁用邀请好友键

    ui->pb_send->hide();            //禁用发送键

    ui->pb_audio->setText("打开音频设备");
}
//玩家死后设置 玩家的头像为死亡的头像
void WerewolfDialog::SetDEADPERSONIcon(int playerID)
{
    //当映射中没有该玩家的时候  不处理 直接退出
    if(m_mapIDToButton.find(playerID)==m_mapIDToButton.end())return ;

    QPushButton*DeathPlayerIcon=m_mapIDToButton[playerID];

    DeathPlayerIcon->setIcon(QIcon(QString(":/images/death2.jpg")));   //设置为死亡的头像

    this->repaint();  //重绘
}

//设置加入房间的玩家头像 以及绑定ID
void WerewolfDialog::SetRoomMemberInfo(int playerID,int playerIconID,int playerSeat)
{
    //当玩家的座位ID为-1的时候代表没有入座  所以不用设置信息头像等
    if(playerSeat==-1)return ;

    // 拿玩家和 对应的每个PushButton绑定关系
    m_mapIDToButton[playerID]=btn[playerSeat];

    //设置UI  头像显示
    btn[playerSeat]->setIcon(QIcon(QString(":/tx/%1.png").arg(playerIconID)));

    this->repaint();  //重绘

}
//设置房主信息显示的信息
void WerewolfDialog::SetLandlord(int playerSeat)
{
    if(playerSeat==0)
    {
        ui->pb_landlord->setText(QString("当前房主为:玩家一号"));
    }
    if(playerSeat==1)
    {
        ui->pb_landlord->setText(QString("当前房主为:玩家二号"));
    }
    if(playerSeat==2)
    {
        ui->pb_landlord->setText(QString("当前房主为:玩家三号"));
    }
    if(playerSeat==3)
    {
        ui->pb_landlord->setText(QString("当前房主为:玩家四号"));
    }
    if(playerSeat==4)
    {
        ui->pb_landlord->setText(QString("当前房主为:玩家五号"));
    }
    if(playerSeat==5)
    {
        ui->pb_landlord->setText(QString("当前房主为:玩家六号"));
    }
    if(playerSeat==6)
    {
        ui->pb_landlord->setText(QString("当前房主为:玩家七号"));
    }
    if(playerSeat==7)
    {
        ui->pb_landlord->setText(QString("当前房主为:玩家八号"));
    }

}
//设置当前玩家的头像
void WerewolfDialog::solt_setplayerImage(int imageIcon)
{
    //可以通过判断MAP里所有头像有无设置来判断房间有无满人 ...TO DO
    m_playerIconID=imageIcon;

}
#include<QString>
#include<QDebug>
//处理不同鼠标发出的点击事件 ,处理不同的事情  当点击不同的房间里的作为的时候显示加入房间玩家的头像
void WerewolfDialog::btnclick()
{
    //处理多次点击换头像的问题
    if(m_false==1)return ;
    //发送者信号的对象
    QPushButton *optoBtn=qobject_cast<QPushButton*>(sender());


    for(int j=0;j<8;++j)
    {
        if(optoBtn==btn[j])
        {
            m_mapIDToButton[m_playerID]=btn[j];
            btn[j]->setIcon(QIcon(QString(":/tx/%1.png").arg(m_playerIconID)));

            m_playerSeatID=j;

            qDebug()<<QString("此时玩家选择的座位为%1").arg(j);

            //做为信号抛出此时玩家的座位 以及个人信息
            Q_EMIT SIG_PLAYERINFO(this->m_playerID,this->m_playerIconID,j,m_wolfRoomID);

            m_false=1;

            break;

        }
    }
    return ;
}

Ui::WerewolfDialog *WerewolfDialog::getUi() const
{
    return ui;
}
//离开房间
void WerewolfDialog::on_pushButton_37_clicked()
{
    if(m_wolfRoomID==0)
    {
        QMessageBox::about(this,"提示","还没加入房间");
        return ;

    }
    if(QMessageBox::question(this,"提示","是否要观战？")==QMessageBox::No)
    {
        this->close();
    }

    m_mapIDToButton[m_playerID]->setIcon(QIcon(QString(":/images/leave.png")));

    this->repaint();  //重绘

     //发送信号
     Q_EMIT SIG_LEAVEWOLFROMM(m_wolfRoomID);   //发送离开房间的信号

    //this->close();
}
//游戏规则说明手册
void WerewolfDialog::on_pushButton_22_clicked()
{
    //对应的窗口进行显示
    m_GameRule->show();
}
//点击打开音频
void WerewolfDialog::on_pb_audio_clicked()
{

    if(ui->pb_audio->text()=="打开音频设备")
    {
        //打开
        Q_EMIT SIG_PLAYEROPENAUDIO();

        ui->pb_audio->setText("关闭音频设备");
    }
    else
    {
        //close
        Q_EMIT SIG_PLAYERCLOSEAUDIO();

        ui->pb_audio->setText("打开音频设备");
    }
}
//玩家点击准备
void WerewolfDialog::on_pb_myselfprrpare_clicked()
{
    //如果座位ID没有改变  则不给玩家进行该操作  必须点击入座后才可以点准备
    if(m_playerSeatID==-1)return ;

    //玩家点击准备后 按钮失效  不能点击第二次了
    if(m_praptefalse==1)return ;

    ui->pb_myselfprrpare->setText(QString("已准备"));
    prepare[m_playerSeatID]->setText(QString("已准备"));

    m_praptefalse=1;

    //抛出信号（准备人的信息抛出 交给服务器处理）
    Q_EMIT SIG_PREPARE(m_playerID,m_playerSeatID,m_wolfRoomID);

}
#include<QTime>
//发送聊天
void WerewolfDialog::on_pb_send_clicked()
{
    QString content=ui->te_write->toPlainText();
    if(content.isEmpty())return ;

    ui->tb_chat->append(QString("[我]%1").arg(QTime::currentTime().toString("hh::mm::ss")));
    ui->tb_chat->append(content);


    ui->te_write->clear();

    //抛出 信号
    Q_EMIT SIG_SendChatMsgWolf(m_playerID,m_playerSeatID,content);
}
//接收聊天内容
void WerewolfDialog::RecvChatMsg(QString content,int playerSeatID)
{
    QString playerName=GetPlayerName(playerSeatID);
    ui->tb_chat->append(QString("[%1] %2").arg(playerName).arg(QTime::currentTime().toString("hh::mm::ss")));

    ui->tb_chat->append(content);
}
//获得哪个玩家说的
QString WerewolfDialog::GetPlayerName(int playerSeatID)
{
    if(playerSeatID==0)
    {
       QString playerName=QString("玩家一号");

       return playerName;
    }
    if(playerSeatID==1)
    {
        QString playerName=QString("玩家二号");

        return playerName;
    }
    if(playerSeatID==2)
    {
        QString playerName=QString("玩家三号");

        return playerName;
    }
    if(playerSeatID==3)
    {
        QString playerName=QString("玩家四号");

        return playerName;
    }
    if(playerSeatID==4)
    {
        QString playerName=QString("玩家五号");

        return playerName;
    }
    if(playerSeatID==5)
    {
        QString playerName=QString("玩家六号");

        return playerName;
    }
    if(playerSeatID==6)
    {
        QString playerName=QString("玩家七号");

        return playerName;
    }
    if(playerSeatID==7)
    {
        QString playerName=QString("玩家八号");

        return playerName;
    }
}
//接收通告消息
void WerewolfDialog::RecvAnnunciateMsg(QString content)
{
    ui->tb_annunciate->append(QString("%1").arg(QTime::currentTime().toString("hh::mm::ss")));

    ui->tb_annunciate->append(content);
}
//设置时间
void WerewolfDialog::SetTimeDate()
{
    m_GameTime++;
    QString textNUM;


    //控制讨论时间
    if(false_dicussion==1)
    {
        //讨论时间设置为6分钟  当时间到的时候抛出 信号
        if(m_GameTime==30)
        {
            //讨论时间到  抛出信号
            Q_EMIT SIG_DicussionTimeOver();
            m_GameTime=0;
            ui->lb_time->setText(textNUM.setNum(m_GameTime));
            //停止定时器
            this->SetTimerStop();
        }
    }
    //控制遗言发言时间
    if(false_death==1)
    {
        //遗言时间设置为6分钟  当时间到的时候抛出 信号
        if(m_GameTime==30)
        {
            Q_EMIT SIG_DeathTimeOver();
            m_GameTime=0;
            ui->lb_time->setText(textNUM.setNum(m_GameTime));
            //停止定时器
            this->SetTimerStop();
        }

    }
    //控制天黑时间
    if(false_DarkOver==1)
    {

        //天黑时间设置为6分钟  当时间到的时候抛出 信号
        if(m_GameTime==60)
        {
            Q_EMIT SIG_GetDarkOver();
            m_GameTime=0;
            ui->lb_time->setText(textNUM.setNum(m_GameTime));
            //停止定时器
            this->SetTimerStop();
        }
    }



    ui->lb_time->setText(textNUM.setNum(m_GameTime));
}
//重置时间
void WerewolfDialog::SetReset()
{
    m_GameTime=0;
}
//开启定时器
void WerewolfDialog::SetTimerStart()
{
    m_Time->start(1000);
}
//关闭定时器
void WerewolfDialog::SetTimerStop()
{
    m_Time->stop();
}
//缩小
void WerewolfDialog::on_pushButton_clicked()
{
    this->slot_showMin();
}
