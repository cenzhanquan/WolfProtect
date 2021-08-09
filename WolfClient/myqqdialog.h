#ifndef MYQQDIALOG_H
#define MYQQDIALOG_H

#include <QDialog>
#include"qmytcpclient.h"
#include"Packdef.h"
#include"logindialog.h"
#include"IMToolBox.h"
#include<QMenu>
#include<QMap>
#include"useritem.h"
#include<QCloseEvent>
#include<chatdialog.h>
#include"roomdialog.h"

#include "video_read.h"

#include"audio_read.h"

#include"audio_write.h"

#include"customwidget.h"

#include"werewolfdialog.h"

#include"wolfpackdf.h"   //狼人杀协议头

#include "friendofflinedialog.h"

#include "ui_werewolfdialog.h"
#include "playeridentitydialog.h"

namespace Ui {
class MyQQDialog;
}

class MyQQDialog : public /*QDialog*/CustomMoveDialog
{
    Q_OBJECT

public:
    explicit MyQQDialog(QWidget *parent = 0);
    ~MyQQDialog();
signals:
    void SIG_addFriend(QString name);
    void SIG_CREATEWOLFROOM();
    void SIG_GETPLAYERIMAGE(int);                         //获得玩家的游戏头像信号

private slots:
    void on_pb_test_clicked();
    void slot_ReadyData(char* buf,int nlen);

    void slot_LoginCommit(QString name ,QString password);

    void slot_RegisterCommit(QString name ,QString password);

    void slot_RegisterRs( char * buf,  int nlen);
    void slot_LoginRs( char * buf,  int nlen);
    void slot_ForceOffline( char * buf,  int nlen);

    void slot_dealMenu(QAction* action);
    void on_pb_menu_clicked();

    void slot_addFriendRq(QString name);

    void slot_dealAddFriendRq(char * buf,int nlen);
    void slot_dealAddFriendRs(char *buf, int nlen);
    void slot_FriendInfo(char *buf, int nlen);

    void slot_FriendOfflineRS(char *buf, int nlen);   //处理离线请求
    void slot_ChatRq(char *buf, int nlen);
    void slot_ChatRs(char *buf, int nlen);
    void slot_CreateRoomRs(char *buf, int nlen);
    void slot_JoinRoomRs(char *buf, int nlen);

    void slot_RoomMember(char *buf, int nlen);


    void slot_LeaveRoomRs(char *buf, int nlen);

    void slot_VideoFrame(char *buf, int nlen);

    void slot_AudioFrame(char *buf, int nlen);



    void slot_friendOfflineMessage(QString name);   //处理好友离线通知 弹出通知框

    void slot_UserItemClicked();
    void InitServerIP();
    void on_pb_close_clicked();

    void slot_Delete();
    void closeEvent(QCloseEvent * event);

    void slot_SendChatRq(int,QString);

    void slot_createRoom();
    void slot_joinRoom(QString roomid);
    void slot_leaveRoom(int);

    void slot_videoItemClicked(int id);

    //视频发送
    void slot_sendVideoFrame(QImage&img);

    //音频发送
    void slot_sendAudioFrame(QByteArray byte);

    void slot_refreshImage(int id, QImage &img);
    void on_pb_min_clicked();

    void on_pb_test3_clicked();

    void on_pb_test2_clicked();

public slots:
    //----------------------------------------------------狼人杀------------------------------------------------

    void slot_createwolfroomrq();  //处理创建狼人杀房间请求

    void slot_CreateWolfRoomRs(char *buf, int nlen);  //处理创建游戏房间回复

    void slot_playerSeatInfo(int PlayerID,int PlayerIconID,int PlayerSeatID,int PlayerWolfRoomID);

    void slot_WolfjoinRoom(QString roomid);   //加入狼人杀房间
    void slot_JoinWolfRoomRs(char *buf, int nlen);  //处理创建狼人杀房间回复

    void slot_WolfRoomMember(char *buf, int nlen);  //处理服务器发来的狼人杀房间成员信息

    void slot_leaveWolfRoomRq(int roomID); //离开狼人杀房间请求

    void  slot_leaveWolfRoomRs(char *buf, int nlen);  //离开狼人杀房间回复

    void slot_prepare(int playerID,int playerSeatID,int wolfRoomID);  //发送点击准备请求

    void slot_PrapreRs(char *buf, int nlen);       //接收服务器发来的点击准备请求

    void slot_PrapreInfo(char *buf, int nlen);   //处理准备玩家的信息

    void slot_SendChatMsgWolf(int m_playerID,int m_playerSeatID,QString content); //发送聊天信息

    void slot_wolfRoomChatQq(char *buf, int nlen);  //处理聊天请求

    void slot_sendAudioFrameWolf(QByteArray byte);    //音频发送

    void slot_WolfAudioFrameQq(char *buf, int nlen);  //处理服务器发来房间内的成员音频  并播放

    void slot_StartGameQq(char *buf, int nlen);   //处理服务器发来的开始游戏请求

    void slot_CIVILIANQq(char *buf, int nlen);//处理服务器发来的请求  平民的

    void slot_WEREWOLFQq(char *buf, int nlen);//处理服务器发来的请求  狼人

    void slot_WITCHQq(char *buf, int nlen);//处理服务器发来的请求  女巫

    void slot_SEERQq(char *buf, int nlen);//处理服务器发来的请求  预言家

    void slot_CheckInfo(char *buf, int nlen);//处理 服务器发来的查验结果

    void  slot_HunterRq(char *buf, int nlen);//处理服务器发来的请求  猎人

    void slot_DayBreaksRq(char *buf, int nlen);//处理服务器发来的天亮请求

    void slot_DicussionTimeOver(); //当时间到的时候 进行投票然后 给服务器发送讨论结束 进入晚上

    void slot_DeathPlayerRq(char *buf, int nlen);//处理服务器发来的请求  对于死者的

    void slot_GetDarkOver();//天黑时间到  进入白天

    void slot_VoteRS(char *buf, int nlen);//投票回复
    void slot_WolfDecideRq(char *buf, int nlen); //狼人要杀的那个人的决定 请求

    void slot_DeathTimeOver();//遗言时间到

    void slot_ChangeDadyRq(char *buf, int nlen);  //更新游戏天数

    void slot_GameOverRq(char *buf, int nlen);  //游戏结束包

    void slot_heartConnect();  //心跳机制

    void slot_disConnect();  //断线重连
    //----------------------------------------------------狼人杀------------------------------------------------

private:

    Ui::MyQQDialog *ui;
    QMyTcpClient * m_tcpClient;
    QString m_serverIP;
    LoginDialog *m_loginDlg;
    int m_id;                         //当前客户端自己的ID
    IMToolList * m_widgetList;

    QString m_UserName;            //玩家的名字
    QMenu * m_mainMenu;
    int m_room_id; //视频会议房间号


    RoomDialog*m_roomdlg;
    Video_Read *m_pVideoRead;   //视频采集对象
    Audio_Read *m_pAudioRead;   //音频采集  对象


    FriendOfflineDialog *m_friendoffline;



    QMap<int , UserItem* > m_mapIDToUserItem;
    QMap<int , chatDialog* > m_mapIDToChatdlg;
    QMap<int , VideoItem*>m_mapIDToVideoItemList;


    QMap<int , Audio_Write*>m_mapIDToAudioWrite;   //为每个人分配一个音频播放对象  用于管理

     //------------------------------------------------------------------狼人杀------------------
     int m_wolfroom_id;           //游戏房间号
     WerewolfDialog*m_wolfRoom;  //狼人杀房间
     PlayerIdentityDialog *m_IdentityDolg;  //玩家的身份牌

     int witchSave;  //女巫的解药

     int witchpoison; //女巫的毒药


     //拿玩家ID和游戏房间内的玩家信息进行绑定
     QMap<int, WOLFPLAYERINFO*>m_mapPlayerIDToPlayerInfo;

     //拿玩家座位号和玩家ID进行绑定
     QMap<int,int>m_mapPlayerSeatIDToPlayerID;

     //拿玩家座位ID 和身份牌进行绑定  用来记录身份
     QMap<int,int>m_mapPlayerSeatIDIdentityID;

      QMap<int , Audio_Write*>m_mapIDToAudioWriteWolf;   //为每个人分配一个音频播放对象  用于管理
     //------------------------------------------------------------------狼人杀------------------


};

#endif // MYQQDIALOG_H
