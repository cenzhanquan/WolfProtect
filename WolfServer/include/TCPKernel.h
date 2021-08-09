#ifndef _TCPKERNEL_H
#define _TCPKERNEL_H



#include "TCPNet.h"
#include "Mysql.h"
#include<vector>
#include <algorithm>
class TcpKernel;
typedef void (TcpKernel::*PFUN)(int,char*,int nlen);

typedef struct
{
    PackType m_type;
    PFUN m_pfun;
} ProtocolMap;



class TcpKernel:public IKernel
{
public:
    int Open();
    void Close();
    void DealData(int,char*,int);

    //注册
    void RegisterRq(int,char*,int);
    //登录
    void LoginRq(int,char*,int);

    //添加好友请求
    void AddFriendRq(int,char*,int);

    //添加好友回复
    void AddFriendRs(int,char*,int);
    //根据ID转发
    void  SendMsgToId(int,char*,int);
    //从数据库中获得用户信息
    void GetUserInfoFromSql(int id);
    //用户获得好友列表，并把自己登录上线的消息发送给线上的所有好友
    void UserGetFriendList(int id);
    void OfflineRq(int,char* ,int );

    void ChatRq(int,char* ,int );

    void InitRand();

    //创建房间
    void CreateRoomRq(int clientfd,char*szbuf,int nlen);

    //加入房间
    void JoinRoomRq(int clientfd,char*szbuf,int nlen);

    //离开房间
     void LeaveRoomRq(int clientfd,char*szbuf,int nlen);


     //处理转发视频帧
     void VideFrame(int clientfd,char*szbuf,int nlen);

     //处理并转发音频帧
     void AudioFrame(int clientfd, char *szbuf, int nlen);


     //--------------------------------------狼人杀---------------------------------
     //创建狼人杀房间
     void CreateWolfRoomRq(int clientfd,char*szbuf,int nlen);

     //处理登记玩家入座时的信息 主要记录玩家入座在那个位置
     void AddPlayerSeatInfo(int clientfd,char*szbuf,int nlen);

     //设置玩家身份信息
     WOLFPLAYERINFO* SetPlayerIdentity(int PlayerID,int WolfRoomID,int Identity);

     //处理加入房间请求
     void JoinWolfRoomRq(int clientfd,char*szbuf,int nlen);

     //处理离开狼人杀房间请求
     void leaveWolfRoomRq(int clientfd,char*szbuf,int nlen);

     //处理客户端发来的准备请求
     void PrapreRq(int clientfd,char*szbuf,int nlen);

     //处理浪人杀房间发来的聊天请求
     void ChatRqWolf(int clientfd,char*szbuf,int nlen);


     //处理狼人杀房间成员发来的音频
     void AudioFrameWolf(int clientfd,char*szbuf,int nlen);

     //随机分配玩家身份
     void PlayerIdentityID(int WolfRoomID);

     //狼人的操作回复
     void WEREWOLF_RS(int clientfd,char*szbuf,int nlen);

     //狼人操作回复
     void WITCH_RS(int clientfd,char*szbuf,int nlen);

     //预言家操作回复
     void SEER_RS(int clientfd,char*szbuf,int nlen);

     //猎人的操作回复
     void HUNTER_RS(int clientfd,char*szbuf,int nlen);

      //天亮了  给房间内的所有玩家 发送 昨晚的情况
     void DayBreaks();

     //客户端发来的天亮信息包
     void DayBreaks_Rq(int clientfd,char*szbuf,int nlen);


     //处理玩家发来的投票请求
     void VoteRq(int clientfd,char*szbuf,int nlen);


     //判断是否游戏结束
     int IsGameOver();

     //开始下一天游戏
     void InToNightRq(int clientfd,char*szbuf,int nlen);

     //判断谁胜利了
     int WhoVictory(int wolfRoom);
     //-------------------------------------狼人杀---------------------------------
private:
    CMysql * m_sql;
    TcpNet * m_tcp;

    //添加映射关系 ID和客户端SOCKFD的映射关系
    //map<int,int>m_mapIDToFD;

    //根据用户ID去存储用户信息
    map<int,UserInfo*>m_mapIDToUserInfo;

    //根据房间号和用户信息进行绑定
    map<int ,list<UserInfo*>> m_mapRoomIDToUserInfoList;


    //=========================================================狼人杀===========================================
    int m_GameDays;         //记录游戏天数   （当一轮的投票结束  游戏天数+1）
    //根据狼人杀的房间号和房间内用户进行绑定
    map<int,list<WOLFPLAYERINFO*>>m_mapRoomIDToWolfPlayerInfoList;

    //拿玩家ID和玩家身份进行绑定
    map<int,int>m_mapPlayerIDToIdentityID;
    //记录死亡的人   玩家ID
    vector<int>Deathplayers;

    int KillPlayerID;  //记录被杀死玩家的ID
    int PosionPlayerID; //记录被毒人的玩家ID
    int TakePlayrID;  //记录带走了那个人
    int VotePlayerID;  //被票死的玩家ID
    int Votefalse;  //投票标志
    //=============================================
    //记录狼人要杀 的玩家ID
    vector<int> KillNums;
    //记录当前狼人杀人的杀人的人数
    int KillPlayerNums;
    //记录当前狼人杀的都不杀同一个人
    int NoKillPlayerNUms;
    //记录有多少个狼人没有杀人
    int NoKillPlayer;
    //===============================================

    //记录被投票的人
    vector<int>VoteNums;
    //记录投票人的比重
    int VotePlayerNums;
    //==============================================
    //记录神的数量
    vector<int>GodNums;
    //记录民的数俩
    vector<int>civilianNums;
    //记录狼的数量
    vector<int>wolfNums;
    //==============================================
    //记录每个点击准备的玩家
    map<int,int>m_mapPlayerIDPrapreInfo;

    //狼
    vector<int>wolfplayers;
    vector<int>civilianplayers;
    //========================================================狼人杀===============================================
};






////读取上传的视频流信息
//void UpLoadVideoInfoRq(int,char*);
//void UpLoadVideoStreamRq(int,char*);
//void GetVideoRq(int,char*);
//char* GetVideoPath(char*);
//void QuitRq(int,char*);
//void PraiseVideoRq(int,char*);
//void GetAuthorInfoRq(int,char*);
#endif
