#ifndef _PACKDEF_H
#define _PACKDEF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/epoll.h>
#include <sys/stat.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include "err_str.h"
#include <malloc.h>

#include<iostream>
#include<map>
#include<list>


//边界值
#define _DEF_SIZE 45
#define _DEF_BUFFERSIZE 1000
#define _DEF_PORT 8000
#define _DEF_SERVERIP "0.0.0.0"  


#define TRUE true
#define FALSE false


#define _DEF_LISTEN 128
#define _DEF_EPOLLSIZE 4096
#define _DEF_IPSIZE 16
#define _DEF_COUNT 10
#define _DEF_TIMEOUT 10
#define _DEF_SQLIEN 400



#define BOOL bool
#define DEF_PACK_BASE  (10000)


////注册
//#define  DEF_PACK_REGISTER_RQ    (DEF_PACK_BASE + 0)
//#define  DEF_PACK_REGISTER_RS    (DEF_PACK_BASE + 1)
////登录
//#define  DEF_PACK_LOGIN_RQ    (DEF_PACK_BASE + 2)
//#define  DEF_PACK_LOGIN_RS    (DEF_PACK_BASE + 3)
////创建房间
//#define DEF_PACK_CREATEROOM_RQ  (DEF_PACK_BASE + 4)
//#define DEF_PACK_CREATEROOM_RS  (DEF_PACK_BASE + 5)
////加入房间
//#define DEF_PACK_JOINROOM_RQ  (DEF_PACK_BASE + 6)
//#define DEF_PACK_JOINROOM_RS  (DEF_PACK_BASE + 7)
////房间列表请求
//#define DEF_PACK_ROOM_MEMBER    (DEF_PACK_BASE + 8)
////音频数据
//#define DEF_PACK_AUDIO_FRAME    (DEF_PACK_BASE + 9)
////退出房间请求
//#define DEF_PACK_LEAVEROOM_RQ   (DEF_PACK_BASE + 10)
////退出房间回复
//#define DEF_PACK_LEAVEROOM_RS   (DEF_PACK_BASE + 11)

typedef enum Net_PACK
{
    DEF_PACK_REGISTER_RQ = 10000,
    DEF_PACK_REGISTER_RS,

    DEF_PACK_LOGIN_RQ,
    DEF_PACK_LOGIN_RS,

    DEF_PACK_CREATEROOM_RQ,
    DEF_PACK_CREATEROOM_RS,

    DEF_PACK_JOINROOM_RQ ,
    DEF_PACK_JOINROOM_RS,

    DEF_PACK_ROOM_MEMBER ,

    DEF_PACK_AUDIO_FRAME,

    DEF_PACK_LEAVEROOM_RQ ,
    DEF_PACK_LEAVEROOM_RS ,

    DEF_PACK_ADD_FRIEND_RQ,
    DEF_PACK_ADD_FRIEND_RS,

    DEF_PACK_FRIEND_INFO,

    DEF_PACK_CHAT_RQ,
    DEF_PACK_CHAT_RS,

    DEF_PACK_OFFLINRE_RQ,
    DEF_PACK_OFFLINRE_RS,

    DEF_PACK_VIDEO_FRAME,
    DEF_PACK_FORCE_OFFLINE,


    //-------------------------------------------------狼人杀--------------------------------------------------

    DEF_PACK_CREATEWOLFROOM_RQ,//创建房间请求包头
    DEF_PACK_CREATEWOLFROOM_RS,//创建房间回复包头

    DEF_PACK_JOINWOLFROOMRQ,   //加入狼人杀房间请求  包头
    DEF_PACK_JOINWOLFROOMRS,  //加入狼人杀房间回复  包头


    DEF_PACK_LEAVEWOLFROOM_RQ,  //离开狼人杀房间 请求 包头
    DFE_PACK_LEAVEWOLFROOM_RS,  //离开狼人杀房间  回复  包头

    DEF_PACK_WOLFROOM_MEMBER, //狼人杀房间成员请求

    DEF_PACK_WOLFROOM_PLAYER_INFO,  //狼人杀玩家信息

    DFE_PACK_PREPARE_RQ, //点击准备请求

    DEF_PACK_PREPARE_INFO, //准备玩家的信息

    DEF_WOLFROOM_CHAT_RQ,  //聊天请求

    DEF_PACK_AUDIO_FRAME_WOLF,//音频

    DEF_STARTGAME_INFO,  //游戏开始的玩家信息

    DEF_CIVILIAN_RQ,//平民请求

    DEF_CIVILIAN_RS,//平民回复

    DEF_WEREWOLF_RQ, //狼人请求

    DEF_WEREWOLF_RS, //狼人回复


    DEF_WITCH_RQ,// 女巫请求

    DEF_WITCH_RS, //女巫回复

    DEF_SEER_RQ,//预言家请求

    DEF_SEER_RS,//预言家回复

    DEF_CHECK_INFO, //查验人的信息

    DEF_HUNTER_RQ,//猎人请求包

    DEF_HUNTER_RS,//猎人回复包

    DEF_DayBreaks,//天亮信息包

    DEF_DeathPlayer,//死者信息包

    DEF_Vote_RQ,//投票请求

    DEF_Vote_RS,//投票回复

    DEF_GameOver,//游戏结束包

    DEF_WolfDecide,//狼人的决定

    DEF_InToNight,//进入黑夜包

    DEF_ChangeDady,//更新游戏天数
       //-------------------------------------------------狼人杀--------------------------------------------------

}Net_PACK;
//==========================================================狼人杀================================
//玩家的角色种类
typedef enum PLAYROLE
{
    CIVILIAN=2021,  //平民

    SEER,   //预言家

    HUNTER,  //猎人

    WITCH, //女巫

    WEREWOLF, //狼人

    DEADPERSON, //死人

    HOLLOWMAN, //透明人(指没有分配身份的人)


}PLAYROLE;
//========================================================狼人杀=====================================


//-------------------------------------------------狼人杀--------------------------------------------------
//为房主
#define ISHOUSEOWNER  1
//不是房主
#define NOHOUSEOWNER 0


//使用了解药
#define ISSAVEPLAYER  1
//没有使用解药
#define NOSAVEPLAYER 0

//好人胜利
#define GOODIESVICTORY 1

//狼人胜利
#define WOLFVICTORY 0

//游戏正在继续
#define GAMEING 2
//-------------------------------------------------狼人杀--------------------------------------------------

//注册请求结果
#define userid_is_exist      0
#define register_sucess      1

//登录请求结果
#define userid_no_exist      0
#define password_error       1
#define login_sucess         2
#define user_online          3

//创建房间结果
#define room_is_exist        0
#define create_success       1

//加入房间结果
#define room_no_exist        0
#define join_success         1

//上传请求结果
#define file_is_exist        0
#define file_uploaded        1
#define file_uploadrq_sucess 2
#define file_upload_refuse   3

//上传回复结果
#define fileblock_failed     0
#define fileblock_success    1

//下载请求结果
#define file_downrq_failed   0
#define file_downrq_success  1


//添加好友结果
#define no_this_user    0
#define user_refused    1
#define user_is_offline 2
#define add_success     3



#define _downloadfileblock_fail  0
#define _downloadfileblock_success	1

#define DEF_PACK_COUNT (100)

#define MAX_PATH            (280 )
#define MAX_SIZE            (60  )
#define DEF_HOBBY_COUNT     (8  )
#define MAX_CONTENT_LEN     (4096 )


/////////////////////网络//////////////////////////////////////


#define DEF_MAX_BUF	  1024
#define DEF_BUFF_SIZE	  4096


typedef int PackType;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//登录请求
typedef struct STRU_LOGIN_RQ
{
    STRU_LOGIN_RQ()
    {
        m_nType = DEF_PACK_LOGIN_RQ;
        memset(m_szUser,0,MAX_SIZE);
        memset(m_szPassword,0,MAX_SIZE);
    }

    PackType m_nType;   //包类型
    char     m_szUser[MAX_SIZE] ; //用户ID
    char     m_szPassword[MAX_SIZE];  //密码
} STRU_LOGIN_RQ;


//登录回复
typedef struct STRU_LOGIN_RS
{
    STRU_LOGIN_RS()
    {
        m_nType= DEF_PACK_LOGIN_RS;
        m_UserID = 0;
        m_lResult = 0;
    }
    PackType m_nType;   //包类型
    int  m_UserID;
    int  m_lResult ; //注册结果

} STRU_LOGIN_RS;


//注册请求
typedef struct STRU_REGISTER_RQ
{
    STRU_REGISTER_RQ()
    {
        m_nType = DEF_PACK_REGISTER_RQ;
        memset(m_szUser,0,MAX_SIZE);
        memset(m_szPassword,0,MAX_SIZE);
    }

    PackType m_nType;   //包类型
    char     m_szUser[MAX_SIZE] ; //用户名
    char     m_szPassword[MAX_SIZE];  //密码

} STRU_REGISTER_RQ;

//注册回复
typedef struct STRU_REGISTER_RS
{
    STRU_REGISTER_RS()
    {
        m_nType= DEF_PACK_REGISTER_RS;
        m_lResult = 0;
    }
    PackType m_nType;   //包类型
    int  m_lResult ; //注册结果

} STRU_REGISTER_RS;

//添加好友请求
typedef struct STRU_ADD_FRIEND_RQ
{
    STRU_ADD_FRIEND_RQ()
    {
        m_nType = DEF_PACK_ADD_FRIEND_RQ;
        m_userID = 0;
        memset(m_szUserName,0,MAX_SIZE);
        memset(m_szAddFriendName,0,MAX_SIZE);
    }
    PackType   m_nType;   //包类型
    int m_userID;
    char m_szUserName[MAX_SIZE];
    char m_szAddFriendName[MAX_SIZE];

}STRU_ADD_FRIEND_RQ;
//聊天请求
typedef struct STRU_CHAT_RQ
{
    STRU_CHAT_RQ()
    {
        m_nType = DEF_PACK_CHAT_RQ;
        m_userID = 0;
        m_friendID = 0;
        memset(m_ChatContent,0,MAX_SIZE);
    }
    PackType   m_nType;   //包类型
    int m_userID;
    int m_friendID;
    char m_ChatContent[MAX_CONTENT_LEN];

}STRU_CHAT_RQ;

//聊天回复
typedef struct STRU_CHAT_RS
{
    STRU_CHAT_RS()
    {
        m_nType = DEF_PACK_CHAT_RS;
    }
    PackType   m_nType;   //包类型
    int m_userID;
    int m_friendID;
    int m_result;

}STRU_CHAT_RS;

//添加好友回复
typedef struct STRU_ADD_FRIEND_RS
{
    STRU_ADD_FRIEND_RS()
    {
        m_nType = DEF_PACK_ADD_FRIEND_RS;
        m_userID = 0;
        m_friendID = 0;
        m_result = 0;
        memset(szAddFriendName,0,MAX_SIZE);
    }
    PackType   m_nType;   //包类型
    int m_userID;
    int m_friendID;
    int m_result;
    char szAddFriendName[MAX_SIZE];

}STRU_ADD_FRIEND_RS;

//好友信息
typedef struct STRU_FRIEND_INFO
{
    STRU_FRIEND_INFO()
    {
        m_nType = DEF_PACK_FRIEND_INFO;
        m_userID = 0;
        m_iconID = 0;
        m_state = 0;

        memset(m_szName,0,MAX_SIZE);
        memset(m_feeling,0,MAX_SIZE);
    }
    PackType   m_nType;   //包类型
    int m_userID;
    int m_iconID;
    int m_state;
    char m_szName[MAX_SIZE];
    char m_feeling[MAX_SIZE];

}STRU_FRIEND_INFO;


//用户信息
typedef struct UserInfo
{
    UserInfo()
    {
         m_fd = 0;
         m_id = 0;
         m_iconID= 0;
         m_state= 0;
         m_roomid=0;

         memset(m_userName, 0 , MAX_SIZE);
         memset(m_feeling, 0 , MAX_SIZE);
    }
    int  m_fd;
    int  m_id;
    int  m_iconID;
    int  m_state;
    int  m_roomid;
    char m_userName[MAX_SIZE];
    char m_feeling[MAX_SIZE];

}UserInfo;

//创建房间请求
typedef struct STRU_CREATEROOM_RQ
{
    STRU_CREATEROOM_RQ()
    {
        m_nType = DEF_PACK_CREATEROOM_RQ;
        m_UserID = 0;
    }

    PackType m_nType;   //包类型
    int m_UserID;

}STRU_CREATEROOM_RQ;

//创建房间回复
typedef struct STRU_CREATEROOM_RS
{
    STRU_CREATEROOM_RS()
    {
        m_nType= DEF_PACK_CREATEROOM_RS;
        m_lResult = 0;
        m_RoomId = 0;
    }
    PackType m_nType;   //包类型
    int  m_lResult ;    //注册结果
    int  m_RoomId;

}STRU_CREATEROOM_RS;

//加入房间请求
typedef struct STRU_JOINROOM_RQ
{
    STRU_JOINROOM_RQ()
    {
        m_nType = DEF_PACK_JOINROOM_RQ;
        m_UserID = 0;
        m_RoomID = 0;
    }

    PackType m_nType;   //包类型
    int m_UserID;
    int m_RoomID;

}STRU_JOINROOM_RQ;

//加入房间回复
typedef struct STRU_JOINROOM_RS
{
    STRU_JOINROOM_RS()
    {
        m_nType= DEF_PACK_JOINROOM_RS;
        m_lResult = 0;
        m_RoomID = 0;
    }
    PackType m_nType;   //包类型
    int  m_lResult ;    //注册结果
    int m_RoomID;
}STRU_JOINROOM_RS;

//房间成员请求
typedef struct STRU_ROOM_MEMBER_RQ
{
    STRU_ROOM_MEMBER_RQ()
    {
        m_nType= DEF_PACK_ROOM_MEMBER;
        m_UserID =0;
        memset(m_szUser,0,MAX_SIZE);
    }
    PackType m_nType;   //包类型
    int m_UserID;
    char m_szUser[MAX_SIZE];

}STRU_ROOM_MEMBER_RQ;


//离开房间请求
typedef struct STRU_LEAVEROOM_RQ
{
    STRU_LEAVEROOM_RQ()
    {
        m_nType = DEF_PACK_LEAVEROOM_RQ;
        m_nUserId = 0;
        m_RoomId = 0;
    }
    PackType   m_nType;   //包类型
    int    m_nUserId; //用户ID
    int    m_RoomId;
}STRU_LEAVEROOM_RQ;

//离开房间回复
typedef struct STRU_LEAVEROOM_RS
{
    STRU_LEAVEROOM_RS()
    {
        m_nType = DEF_PACK_LEAVEROOM_RS;
        m_UserID = 0;
        memset(szUserName,0,MAX_SIZE);
    }
    PackType   m_nType;   //包类型
    int m_UserID;
    char szUserName[MAX_SIZE];

}STRU_LEAVEROOM_RS;


//离线请求
typedef struct STRU_OFFLINE_RQ
{
    STRU_OFFLINE_RQ()
    {
        m_nType = DEF_PACK_OFFLINRE_RQ;
    }
    PackType   m_nType;   //包类型
    int m_userID;

}STRU_OFFLINE_RQ;

//离线回复
typedef struct STRU_OFFLINE_RS
{
    STRU_OFFLINE_RS()
    {
        m_nType = DEF_PACK_OFFLINRE_RS;
    }
    PackType   m_nType;   //包类型
    int m_userID;

}STRU_OFFLINE_RS;

//强制下线
typedef struct STRU_FORCE_OFFLINE
{
    STRU_FORCE_OFFLINE()
    {
        m_nType = DEF_PACK_FORCE_OFFLINE;
        m_UserID = 0;
    }
    PackType   m_nType;   //包类型
    int m_UserID;

}STRU_FORCE_OFFLINE;

//========================================================狼人杀=============================================================

//创建房间请求
typedef struct STRU_CREATEWOLFROOM_RQ
{
    STRU_CREATEWOLFROOM_RQ()
    {
        m_nType = DEF_PACK_CREATEWOLFROOM_RQ;
        m_UserID = 0;
    }

    PackType m_nType;   //包类型
    int m_UserID;

}STRU_CREATEWOLFROOM_RQ;
//创建房间回复
typedef struct STRU_CREATEWOLFROOM_RS
{
    STRU_CREATEWOLFROOM_RS()
    {
        m_nType= DEF_PACK_CREATEWOLFROOM_RS;
        m_lResult = 0;
        m_RoomId = 0;
    }
    PackType m_nType;   //包类型
    int  m_lResult ;    //注册结果
    int  m_RoomId;

}STRU_CREATEWOLFROOM_RS;

//加入房间请求
typedef struct STRU_JOINWOLFROOM_RQ
{
    STRU_JOINWOLFROOM_RQ()
    {
        m_nType = DEF_PACK_JOINWOLFROOMRQ;
        m_UserID = 0;
        m_RoomID = 0;
    }

    PackType m_nType;   //包类型
    int m_UserID;
    int m_RoomID;

}STRU_JOINWOLFROOM_RQ;

//加入房间回复
typedef struct STRU_JOINWOLFROOM_RS
{
    STRU_JOINWOLFROOM_RS()
    {
        m_nType= DEF_PACK_JOINWOLFROOMRS;
        m_lResult = 0;
        m_RoomID = 0;
        m_playerID=0;
    }
    PackType m_nType;   //包类型
    int  m_lResult ;    //注册结果
    int m_RoomID;
    int m_playerID;    //玩家的ID
}STRU_JOINWOLFROOM_RS;
//房间成员请求
typedef struct STRU_WOLFROOM_MEMBER_RQ
{
    STRU_WOLFROOM_MEMBER_RQ()
    {
        m_nType= DEF_PACK_WOLFROOM_MEMBER;
        m_UserID =0;
        memset(m_szUser,0,MAX_SIZE);
    }
    PackType m_nType;   //包类型
    int m_UserID;
    char m_szUser[MAX_SIZE];

}STRU_WOLFROOM_MEMBER_RQ;


//离开房间请求
typedef struct STRU_LEAVEWOLFROOM_RQ
{
    STRU_LEAVEWOLFROOM_RQ()
    {
        m_nType = DEF_PACK_LEAVEWOLFROOM_RQ;
        m_nUserId = 0;
        m_RoomId = 0;
    }
    PackType   m_nType;   //包类型
    int    m_nUserId; //用户ID
    int    m_RoomId;
}STRU_LEAVEWOLFROOM_RQ;

//离开房间回复
typedef struct STRU_LEAVEWOLFROOM_RS
{
    STRU_LEAVEWOLFROOM_RS()
    {
        m_nType = DFE_PACK_LEAVEWOLFROOM_RS;
        m_UserID = 0;
        memset(szUserName,0,MAX_SIZE);
    }
    PackType   m_nType;   //包类型
    int m_UserID;
    char szUserName[MAX_SIZE];

}STRU_LEAVEWOLFROOM_RS;


//=============================================狼人杀==============================================================

//狼人杀房间内成员的信息
typedef struct WOLFPLAYERINFO
{
    WOLFPLAYERINFO()
    {
        m_nType = DEF_PACK_WOLFROOM_PLAYER_INFO;
        m_PlayID = 0;
        m_PlayerSeat=-1;
        m_PlayerIconID=0;
        m_PlayerIdentity=HOLLOWMAN;        //初始状态设置为透明人  (就是没有分配身份的人)
        m_Playerfd=0;
        m_IsHouseOwner=NOHOUSEOWNER;           //是否为房主  ,初始的时候每个人默认都不是房主
        m_RoomID=0;                        //所在的狼人杀房间号
        memset(szUserName,0,MAX_SIZE);
    }
    PackType   m_nType;   //包类型
    int m_PlayID;                                 //玩家的ID
    int m_PlayerSeat;             //玩家的座位的位置
    int m_PlayerIconID;              //玩家的头像信息
    int m_PlayerIdentity;                         //玩家的身份信息
    int m_Playerfd;
    int m_IsHouseOwner;               //是否为房主
    int m_RoomID;
    char szUserName[MAX_SIZE];

}WOLFPLAYERINFO;


//点击准备请求
typedef struct STRU_PREPARE_RQ
{
    STRU_PREPARE_RQ()
    {
        m_nType = DFE_PACK_PREPARE_RQ;
        playerID=0;
        playerSeat=-1;
        wolfRoomID=0;

    }
    PackType   m_nType;   //包类型
    int playerID;
    int wolfRoomID;
    int playerSeat;


}STRU_PREPARE_RQ;

//玩家准备信息
typedef struct STRU_praprePlayerID
{
    STRU_praprePlayerID()
    {
        m_nType=DEF_PACK_PREPARE_INFO;
        playerID=0;
        playerSeat=-1;
        wolfRoomID=0;
    }
    PackType   m_nType;   //包类型
    int playerID;
    int wolfRoomID;
    int playerSeat;
}STRU_praprePlayerID;

//聊天请求
typedef struct STRU_WOLFROOM_CHAT_RQ
{
    STRU_WOLFROOM_CHAT_RQ()
    {
        m_nType=DEF_WOLFROOM_CHAT_RQ;
        m_playerID=0;
        m_playerSeatID=-1;
        m_wolfRoomID=0;
        memset(m_ChatContent,0,MAX_SIZE);
    }
    PackType m_nType;  //包类型
    int m_playerID;
    int m_playerSeatID;
    int m_wolfRoomID;
    char m_ChatContent[MAX_CONTENT_LEN];  //聊天信息
}STRU_WOLFROOM_CHAT_RQ;


//游戏开始的玩家信息
typedef struct STRU_STARTGAME_INFO
{
    STRU_STARTGAME_INFO()
    {
        m_nType=DEF_STARTGAME_INFO;
        m_playerID=0;
        m_playerIdentityID=0;
        m_wolfRoomID=0;
        m_gamedays=0;
        m_playerSeat=0;
    }
    PackType m_nType;  //包类型
    int m_playerID;
    int m_playerIdentityID;
    int m_wolfRoomID;
    int m_gamedays;
    int m_playerSeat;
}STRU_STARTGAME_INFO;



// CIVILIAN=2021,  //平民请求包

typedef struct STRU_CIVILIAN_RQ
{
    STRU_CIVILIAN_RQ()
    {
        m_nType=DEF_CIVILIAN_RQ;
        m_playerID=0;
    }
    PackType m_nType;  //包类型
    int m_playerID;
}STRU_CIVILIAN_RQ;

// CIVILIAN=2021,  //平民回复包
typedef struct STRU_CIVILIAN_RS
{
    STRU_CIVILIAN_RS()
    {
        m_nType=DEF_CIVILIAN_RS;
        m_playerID=0;
        m_votePlayerID=0;
    }
    PackType m_nType;  //包类型
    int m_playerID;
    int m_votePlayerID;
}STRU_CIVILIAN_RS;


//    WEREWOLF, //狼人请求包
typedef struct STRU_WEREWOLF_RQ
{
    STRU_WEREWOLF_RQ()
    {
        m_nType=DEF_WEREWOLF_RQ;
        m_playerID=0;
    }
    PackType m_nType;  //包类型
    int m_playerID;
}STRU_WEREWOLF_RQ;

//    WEREWOLF, //狼人回复包
typedef struct STRU_WEREWOLF_RS
{
    STRU_WEREWOLF_RS()
    {
        m_nType=DEF_WEREWOLF_RS;
        m_playerID=0;
        m_KillPlayerID=0;
        wolfRoom=0;
    }
    PackType m_nType;  //包类型
    int m_playerID;
    int m_KillPlayerID;
    int wolfRoom;
}STRU_WEREWOLF_RS;
//    WITCH, //女巫请求包
typedef struct STRU_WITCH_RQ
{
    STRU_WITCH_RQ()
    {
        m_nType=DEF_WITCH_RQ;
        KillPlayerID=0;
    }
    PackType m_nType;  //包类型
    int KillPlayerID;  //晚上死的人
}STRU_WITCH_RQ;
//    WITCH, //女巫回复包
typedef struct STRU_WITCH_RS
{
    STRU_WITCH_RS()
    {
        m_nType=DEF_WITCH_RS;
        m_playerID=0;
        posionPlayerID=0;       //默认毒死的人ID为0
        IsSavePlayer=NOSAVEPLAYER;      //默认没有救人
        wolfRoom=0;
    }
    PackType m_nType;  //包类型
    int m_playerID;
    int posionPlayerID;  //毒死的人
    int IsSavePlayer;  //是否救人了
    int wolfRoom;
}STRU_WITCH_RS;


//    SEER,   //预言家请求包
typedef struct STRU_SEER_RQ
{
    STRU_SEER_RQ()
    {
        m_nType=DEF_SEER_RQ;
    }
    PackType m_nType;  //包类型
}STRU_SEER_RQ;
//    SEER,   //预言家回复包
typedef struct STRU_SEER_RS
{
    STRU_SEER_RS()
    {
        m_nType=DEF_SEER_RS;
        m_playerID=0;
        CheckPlayerID=0;       //默认没有查验的话 ID为0
        wolfRoom=0;
    }
    PackType m_nType;  //包类型
    int m_playerID;
    int CheckPlayerID;  //查验的玩家ID
    int wolfRoom;   //房间号
}STRU_SEER_RS;

//查验人的信息包
typedef struct CHECKPLAYERINFO
{
    CHECKPLAYERINFO()
    {
        m_nType=DEF_CHECK_INFO;
        checkplayerIdentity=0;
    }
    PackType m_nType;  //包类型
    int checkplayerIdentity;   //查验人的身份
}CHECKPLAYERINFO;


//    HUNTER,  //猎人请求包
typedef struct STRU_HUNTER_RQ
{
    STRU_HUNTER_RQ()
    {
        m_nType=DEF_HUNTER_RQ;
    }
    PackType m_nType;  //包类型
}STRU_HUNTER_RQ;
//    HUNTER,  //猎人回复包
typedef struct STRU_HUNTER_RS
{
    STRU_HUNTER_RS()
    {
        m_nType=DEF_HUNTER_RS;
        m_playerID=0;
        TakeAwayPlayerID=0;       //默认没有带人的话 ID为0
        wolfRoom=0;
    }
    PackType m_nType;  //包类型
    int m_playerID;
    int TakeAwayPlayerID;  //带走的玩家ID
    int wolfRoom;  //狼人杀房间
}STRU_HUNTER_RS;


//天亮信息包
typedef struct STRU_DayBreaks
{
    STRU_DayBreaks()
    {
        m_nType=DEF_DayBreaks;
        m_KillPlayerID=0;
        m_PosionPlayerID=0;
        m_TakePlayrID=0;
        m_wolfRoom=0;
        m_isGameOver=0;   //默认游戏没有胜利
    }
    PackType m_nType;  //包类型
    int m_KillPlayerID;  //记录被杀死玩家的ID
    int m_PosionPlayerID; //记录被毒人的玩家ID
    int m_TakePlayrID;  //记录带走了那个人
    int m_wolfRoom;
    int m_isGameOver;
}STRU_DayBreaks;


//死者的信息包
typedef struct STRU_DeathPlayer
{
    STRU_DeathPlayer()
    {
        m_nType=DEF_DeathPlayer;
    }
    PackType m_nType;  //包类型
}STRU_DeathPlayer;


//投票请求包
typedef struct STRU_Vote_RQ
{
    STRU_Vote_RQ()
    {
        m_nType=DEF_Vote_RQ;
        VotePlayerID=0;
        wolfRoom=0;
    }
    PackType m_nType;  //包类型
    int VotePlayerID;  //要投的人
    int wolfRoom;
}STRU_Vote_RQ;
//投票回复包
typedef struct STRU_Vote_RS
{
    STRU_Vote_RS()
    {
        m_nType=DEF_Vote_RS;
        WhereVotePlayerID=0;
    }
    PackType m_nType;  //包类型
    int WhereVotePlayerID;  //被投的人
}STRU_Vote_RS;

//游戏结束包
typedef struct GameOver
{
    GameOver()
    {
        m_nType=DEF_GameOver;
        m_GameResult=-1;
    }
    PackType m_nType;  //包类型
    int m_GameResult;  //游戏结果
}GameOver;

//狼人杀人的决定
typedef struct WolfDecide
{
    WolfDecide()
    {
        m_nType=DEF_WolfDecide;
        m_wolfkillplayerID=-1;
    }
    PackType m_nType;  //包类型
    int m_wolfkillplayerID;  //游戏结束的结果
}WolfDecide;


//进入黑夜包
typedef struct InToNight
{
    InToNight()
    {
        m_nType=DEF_InToNight;
        wolfRoom=-1;
    }
    PackType m_nType;  //包类型
    int wolfRoom;  //游戏结束的结果
}InToNight;

//更新游戏天数包
typedef struct ChangeDady
{
    ChangeDady()
    {
        m_nType=DEF_ChangeDady;
        GameDays=-1;
    }
    PackType m_nType;  //包类型
    int GameDays;  //游戏结束的结果
}ChangeDady;

//========================================================狼人杀=============================================================


///音频数据帧
/// 成员描述
/// int type;
/// int userId;
/// int roomId;
/// QByteArray audioFrame;
///


///视频数据帧
/// 成员描述
/// int type;
/// int userId;
/// int roomId;
/// QByteArray videoFrame;
///



#endif

