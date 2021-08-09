#ifndef WEREWOLFDIALOG_H
#define WEREWOLFDIALOG_H

#include <QDialog>
#include"customwidget.h"
#include<QPixmap>
#include<QPainter>
#include<QRect>
#include"gameruledialog.h"
#include<QPushButton>
#include<QMap>
#include<QTimer>


namespace Ui {
class WerewolfDialog;
}

class WerewolfDialog : public /*QDialog*/CustomMoveDialog
{
    Q_OBJECT

public:
    explicit WerewolfDialog(QWidget *parent = 0);
    ~WerewolfDialog();
signals:
    void SIG_LEAVEWOLFROMM(int);    //离开狼人杀房间信号

    //点击座位的时候发出信号（玩家头像ID，玩家座位ID，玩家所在的房间号）
    void SIG_PLAYERINFO(int PlayerID,int PlayerIconID,int PlayerSeat,int PlayerWolfRoomID);

    void SIG_PLAYEROPENAUDIO();      //打开音频设备
    void SIG_PLAYERCLOSEAUDIO();      //关闭音频设备

    void SIG_PREPARE(int,int,int); //把准备人的信息抛出

    void SIG_SendChatMsgWolf(int id,int playerSeatID,QString content);//聊天信息

    void SIG_DicussionTimeOver();  //讨论时间到

    void SIG_GetDarkOver();  //天黑时间到

    void SIG_DeathTimeOver();//遗言时间到

public slots:
    void on_pushButton_23_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_22_clicked();
    void solt_setplayerImage(int playerIcon);   //设置当前客户端玩家的头像

    void btnclick();   //根据不同的按钮点击事件  分别处理不同的事情  主要处理玩家头像



public:
    void paintEvent(QPaintEvent*event);  //重绘

    void setInfo(int roomid=0,int playerID=0);  //设置成员信息

    void SetIdentity(int Identity);  //设置玩家的身份牌

    void SetGameDays(int days);  //设置天数

    void SetDEADPERSONToDo();       //当玩家死后 禁用所有的触发按钮

    void SetDEADPERSONIcon(int playerID);  //当玩家死后  设置玩家的状态

    void SetRoomMemberInfo(int playerID,int playerIconID,int playerSeat);   //设置加入房间的信息显示

    void SetLandlord(int playerSeat);  //设置房主是谁

    void RecvChatMsg(QString content,int playerSeatID);//接收聊天内容

    QString GetPlayerName(int playerSeatID);   //获得是哪个玩家说的

    void RecvAnnunciateMsg(QString content);  //接收通告消息

    void SetTimeDate();  //设置时间

    void SetReset();//重置时间

    void SetTimerStart(); //开启定时器

    void SetTimerStop();  //关闭定时器


private:
    Ui::WerewolfDialog *ui;
public:
    int m_wolfRoomID;       //房间号
    int m_gameDays;      //游戏天数;

    int m_false;  //标志位 为了让你点击了这个玩家头像按钮后不能点击下一个

    int m_praptefalse;  //标志位  玩家点击准备之后不能再点准备了

    int m_yourIdentity;   //当前你的身份牌

    int m_playerID;   //当前你的ID

    int m_playerIconID;    //当前客户端玩家对应的头像ID

    int m_playerSeatID; //玩家的座位ID

    int m_GameTime; //游戏时间

    int false_dicussion;  //讨论的标志

    int false_death;   //遗言的标志

    int false_DarkOver;   //控制天黑时间

    QTimer *m_Time;   //时间对象


    GameRuleDialog*m_GameRule;  //规则手册对象

    QPushButton*btn[8];  //QPushButton数组来管理玩家头像
    QPushButton*prepare[8];  //QPushButton数组来管理玩家头像
    QMap<int,QPushButton*>m_mapIDToButton;  //拿玩家ID和一个玩家头像绑定   方便管理
    Ui::WerewolfDialog *getUi() const;
private slots:
    void on_pb_audio_clicked();
    void on_pb_myselfprrpare_clicked();
    void on_pb_send_clicked();
    void on_pushButton_clicked();
};

#endif // WEREWOLFDIALOG_H
