 #include<TCPKernel.h>
#include "packdef.h"
#include<stdio.h>
#include<sys/time.h>
#include<vector>
#include<algorithm>
using namespace std;


////注册
//#define  DEF_PACK_REGISTER_RQ    (DEF_PACK_BASE + 0)
//#define  DEF_PACK_REGISTER_RS    (DEF_PACK_BASE + 1)
////登录
//#define  DEF_PACK_LOGIN_RQ    (DEF_PACK_BASE + 2)
//#define  DEF_PACK_LOGIN_RS    (DEF_PACK_BASE + 3)

static const ProtocolMap m_ProtocolMapEntries[] =
{
    {DEF_PACK_REGISTER_RQ , &TcpKernel::RegisterRq},
    {DEF_PACK_LOGIN_RQ , &TcpKernel::LoginRq},
    {DEF_PACK_ADD_FRIEND_RQ,&TcpKernel::AddFriendRq},
    {DEF_PACK_ADD_FRIEND_RS,&TcpKernel::AddFriendRs},
    {DEF_PACK_OFFLINRE_RQ,&TcpKernel::OfflineRq},
    {DEF_PACK_CHAT_RQ,&TcpKernel::ChatRq},
    {DEF_PACK_CREATEROOM_RQ,&TcpKernel::CreateRoomRq},
    {DEF_PACK_JOINROOM_RQ,&TcpKernel::JoinRoomRq},
    {DEF_PACK_LEAVEROOM_RQ,&TcpKernel::LeaveRoomRq},
    {DEF_PACK_VIDEO_FRAME,&TcpKernel::VideFrame},
    {DEF_PACK_AUDIO_FRAME,&TcpKernel::AudioFrame},
    {DEF_PACK_CREATEWOLFROOM_RQ,&TcpKernel::CreateWolfRoomRq},
    {DEF_PACK_WOLFROOM_PLAYER_INFO,&TcpKernel::AddPlayerSeatInfo},
    {DEF_PACK_JOINWOLFROOMRQ,&TcpKernel::JoinWolfRoomRq},
    {DEF_PACK_LEAVEWOLFROOM_RQ,&TcpKernel::leaveWolfRoomRq},
    {DFE_PACK_PREPARE_RQ,&TcpKernel::PrapreRq},
    {DEF_WOLFROOM_CHAT_RQ,&TcpKernel::ChatRqWolf},
    {DEF_PACK_AUDIO_FRAME_WOLF,&TcpKernel::AudioFrameWolf},
    {DEF_WEREWOLF_RS,&TcpKernel::WEREWOLF_RS},
    {DEF_WITCH_RS,&TcpKernel::WITCH_RS},
    {DEF_SEER_RS,&TcpKernel::SEER_RS},
    {DEF_HUNTER_RS,&TcpKernel::HUNTER_RS},
    {DEF_DayBreaks,&TcpKernel::DayBreaks_Rq},
    {DEF_Vote_RQ,&TcpKernel::VoteRq},
    {DEF_InToNight,&TcpKernel::InToNightRq},
    {0,0}
};
#define RootPath   "/home/colin/Video/"

int TcpKernel::Open()
{
    InitRand();
    m_GameDays=0;
    KillPlayerNums=0;
    NoKillPlayerNUms=0;
    KillPlayerID=0;
    PosionPlayerID=0;
    TakePlayrID=0;
    VotePlayerID=0;
    NoKillPlayer=0;
    VotePlayerNums=0;
    Votefalse=1;
    m_sql = new CMysql;
    m_tcp = new TcpNet(this);
    m_tcp->SetpThis(m_tcp);
    pthread_mutex_init(&m_tcp->alock,NULL);
    pthread_mutex_init(&m_tcp->rlock,NULL);
    if(  !m_sql->ConnectMysql("localhost","root","colin123","myqq")  )
    {
        printf("Conncet Mysql Failed...\n");
        return FALSE;
    }
    else
    {
        printf("MySql Connect Success...\n");
    }
    if( !m_tcp->InitNetWork()  )
    {
        printf("InitNetWork Failed...\n");
        return FALSE;
    }
    else
    {
        printf("Init Net Success...\n");
    }

    return TRUE;
}

void TcpKernel::Close()
{
    m_sql->DisConnect();
    m_tcp->UnInitNetWork();

    for( auto ite = m_mapIDToUserInfo.begin(); ite != m_mapIDToUserInfo.end(); ++ite)
    {
        delete ite->second;
    }
    m_mapIDToUserInfo.clear();
}


void TcpKernel::DealData(int clientfd,char *szbuf,int nlen)
{
    PackType *pType = (PackType*)szbuf;
    int i = 0;
    while(1)
    {
        if(*pType == m_ProtocolMapEntries[i].m_type)
        {
            PFUN fun= m_ProtocolMapEntries[i].m_pfun;
            (this->*fun)(clientfd,szbuf,nlen);
        }
        else if(m_ProtocolMapEntries[i].m_type == 0 &&
                m_ProtocolMapEntries[i].m_pfun == 0)
            return;
        ++i;
    }
    return;
}


////注册请求结果
//#define userid_is_exist      0
//#define register_sucess      1


//注册
void TcpKernel::RegisterRq(int clientfd,char* szbuf,int nlen)
{
    printf("clientfd:%d RegisterRq\n", clientfd);

    //注册请求包
    STRU_REGISTER_RQ * rq = (STRU_REGISTER_RQ *)szbuf;
    //注册回复包
    STRU_REGISTER_RS rs;

    //根据用户名  查用户
    char sqlStr[1024]={0};

    sprintf(sqlStr,"select name from t_user where name='%s';",rq->m_szUser);
    list<string>resList;

    //对sql语句进行查询  并且进行错误处理
    if(!m_sql->SelectMysql(sqlStr,1,resList))
    {
        printf("SelectMysql error：%s\n",sqlStr);
        return ;
    }

    if(resList.size()==0)
    {
        //没有用户  可以注册   -----写表
        rs.m_lResult=register_sucess;
        sprintf(sqlStr,"insert into t_user(name,password) values('%s','%s');"
                ,rq->m_szUser,rq->m_szPassword);

        //更新数据库中的数据，把数据写入数据库中
        if(!m_sql->UpdataMysql(sqlStr))
        {
            printf("UpdataMysql error：%s\n",sqlStr);
        }
        //t_userInfo(id name icon feeling)

        sprintf(sqlStr,"select id from t_user where name='%s';",rq->m_szUser);
        list<string>resID;
        m_sql->SelectMysql(sqlStr,1,resID);
        int id=0;
        if(resID.size()>0)  id=atoi(resID.front().c_str());
        sprintf(sqlStr,"insert into t_userInfo(id,name,icon,feeling) values('%d','%s',0,'')",id,rq->m_szUser);

        m_sql->UpdataMysql(sqlStr);

    }

    else
    {
        //有用户   就注册失败
        rs.m_lResult=userid_is_exist;
    }
    m_tcp->SendData( clientfd , (char*)&rs , sizeof(rs) );
}

////登录请求结果
//#define userid_no_exist      0
//#define password_error       1
//#define login_sucess         2
//#define user_online          3
//登录
void TcpKernel::LoginRq(int clientfd ,char* szbuf,int nlen)
{
    printf("clientfd:%d LoginRq\n", clientfd);

    //登录请求包
    STRU_LOGIN_RQ * rq = (STRU_LOGIN_RQ *)szbuf;
    //登录回复包
    STRU_LOGIN_RS rs;

    char sqlStr[1024]={0};
    sprintf(sqlStr,"select password , id from t_user where name = '%s';",rq->m_szUser);

    list<string>resList;

    if(!m_sql->SelectMysql(sqlStr,2,resList))
    {
        printf("SelectMysql error:%s\n",sqlStr);
        return ;
    }
    //有用户
    if(resList.size()>0)
    {
        //密码一致
        if(strcmp(resList.front().c_str(),rq->m_szPassword)==0)
        {
            rs.m_lResult=login_sucess;
            resList.pop_front();
            int id=atoi(resList.front().c_str());
             rs.m_UserID=id;

            m_tcp->SendData( clientfd , (char*)&rs , sizeof(rs) );


            UserInfo*info=NULL;
            if(m_mapIDToUserInfo.find(id)!=m_mapIDToUserInfo.end())
            {//找到了
                //强制前一个下线----
                //发送离线通知包给和登录的客户端ID一样的客户端  强制下线功能
                STRU_FORCE_OFFLINE offline;
                offline.m_UserID=id;
                info=m_mapIDToUserInfo[id];
                m_tcp->SendData(info->m_fd,(char*)&offline,sizeof(offline));
            }
            else
            {
                info=new UserInfo;
            }


            info->m_fd=clientfd;
            info->m_id=id;
            strcpy(info->m_userName,rq->m_szUser);
            info->m_state=1;

            //更新映射关系
            m_mapIDToUserInfo[info->m_id]=info;
            //去同步数据库的数据到用户信息  info
            GetUserInfoFromSql(info->m_id);
            //获取好友列表
            UserGetFriendList(info->m_id);
            return ;
        }

        //密码不一致
        else
        {
            rs.m_lResult=password_error;
        }

    }
    //没有用户
    else
    {
        rs.m_lResult=userid_no_exist;
    }


    m_tcp->SendData( clientfd , (char*)&rs , sizeof(rs) );
}
// 去同步数据库的数据到用户信息  info
void TcpKernel::GetUserInfoFromSql(int id)
{
    //首先要在线
    if(m_mapIDToUserInfo.find(id)==m_mapIDToUserInfo.end())return ;
    UserInfo*info =m_mapIDToUserInfo[id];
    info->m_state=1;

    char strsql[1024]="";

    sprintf(strsql,"select icon,feeling from t_userInfo where id='%d';",id);
    list<string>resSql;
    m_sql->SelectMysql(strsql,2,resSql);
    if(resSql.size()==0)return ;

    info->m_iconID=atoi(resSql.front().c_str());
    resSql.pop_front();
    strcpy(info->m_feeling,resSql.front().c_str());
    resSql.pop_front();
}
//登录人获取好友列表（获得列表），登录人信息要发给在线的好友（上线提醒）
void TcpKernel::UserGetFriendList(int id)
{
    //首先保证在线
    if(m_mapIDToUserInfo.find(id)==m_mapIDToUserInfo.end())return ;

    //登录者信息
    UserInfo*loginer=m_mapIDToUserInfo[id];



    //登录人信息请求包
    STRU_FRIEND_INFO loginrq;
    strcpy(loginrq.m_feeling,loginer->m_feeling);
    loginrq.m_iconID=loginer->m_iconID;
    loginrq.m_state=1;
    strcpy(loginrq.m_szName,loginer->m_userName);
    loginrq.m_userID=loginer->m_id;

    //给自己也发一个状态
    m_tcp->SendData(loginer->m_fd,(char*)&loginrq,sizeof(loginrq));
    //查表   查好友  遍历好友
    char sqlstr[1024]="";
    sprintf(sqlstr,"select idA from t_friend where idB='%d';",id);
    list<string>resID;
    m_sql->SelectMysql(sqlstr,1,resID);
    if(resID.size()==0)return ;
    int nCount=resID.size();
    for(int i=0;i<nCount;++i)    //遍历好友
    {
        int friendID=atoi(resID.front().c_str());
        resID.pop_front();


        STRU_FRIEND_INFO friendrq;//写好友信息包
        if(m_mapIDToUserInfo.find(friendID)!=m_mapIDToUserInfo.end())
        { //好友在线  取info 然后 登录人的信息发送给好友
            UserInfo*friender=m_mapIDToUserInfo[friendID];
            strcpy(friendrq.m_feeling,friender->m_feeling);
            friendrq.m_iconID=friender->m_iconID;
            friendrq.m_state=friender->m_state;
            strcpy(friendrq.m_szName,friender->m_userName);
            friendrq.m_userID=friender->m_id;

            //循环的给好友发送登录人的消息
            m_tcp->SendData(friender->m_fd,(char*)&loginrq,sizeof(loginrq));
        }
        else
        {
            //好友不在线  从数据库取
            friendrq.m_state=0;
            friendrq.m_userID=friendID;

            char strsql[1024]="";
            sprintf(strsql,"select name,icon,feeling from t_userInfo where id='%d';",friendID);
            list<string>resSql;
            m_sql->SelectMysql(strsql,3,resSql);
            if(resSql.size()==0)return ;

            strcpy(friendrq.m_szName,resSql.front().c_str());
            resSql.pop_front();
            friendrq.m_iconID=atoi(resSql.front().c_str());
            resSql.pop_front();
            strcpy(friendrq.m_feeling,resSql.front().c_str());
            resSql.pop_front();

        }

        //循环的把好友的信息发送给登录者   让登录者获得好友列表
        //好友的信息发送给登录者
        m_tcp->SendData(loginer->m_fd,(char*)&friendrq,sizeof(friendrq));
    }

}
//处理用户离线请求
void TcpKernel::OfflineRq(int clientfd ,char* szbuf,int nlen)
{
    printf("clientfd:%d offlineRq\n",clientfd);
    //拆包
    STRU_OFFLINE_RQ *rq=(STRU_OFFLINE_RQ*)szbuf;

    char sqlbuf[1024]="";
    sprintf(sqlbuf,"select idB from t_friend where idA='%d';",rq->m_userID);
    list<string>lst;
    m_sql->SelectMysql(sqlbuf,1,lst);


    //解除映射关系
    if(m_mapIDToUserInfo.find(rq->m_userID)!=m_mapIDToUserInfo.end())
    {
        m_mapIDToUserInfo.erase(rq->m_userID);
    }
    //在房间里要退出房间

    //给所有的好友发离线
    while(lst.size()>0)
    {
        int id=atoi(lst.front().c_str());
        lst.pop_front();
        STRU_OFFLINE_RS rs;
        rs.m_userID=rq->m_userID;

        SendMsgToId(id,(char*)&rs,sizeof(rs));
    }

}

//处理用户添加好友请求
void TcpKernel::AddFriendRq(int clientfd ,char* szbuf,int nlen)
{
    printf("clientfd:%d AddFriendRq\n", clientfd);

    STRU_ADD_FRIEND_RQ *rq=(STRU_ADD_FRIEND_RQ*)szbuf;
    STRU_ADD_FRIEND_RS rs;
    //根据用户名  拿到ID
    char strSql[1024]="";
    sprintf(strSql,"select id from t_user where name='%s';",rq->m_szAddFriendName);
    list<string>resID;
    if(!m_sql->SelectMysql(strSql,1,resID))
    {
        //没查找到
        printf("SelectMysql Error:%s\n",strSql);
    }
    //是否有这个用户  当为0的时候证明没有这个用户   设置回复包里的协议
    if(resID.size()==0)
    {
        rs.m_result=no_this_user;
    }
    else
    {
        //看是否在线
        int id=atoi(resID.front().c_str());
        if(m_mapIDToUserInfo.find(id)!=m_mapIDToUserInfo.end())
        {
            //在线转发
            SendMsgToId(id,szbuf,nlen);
            return ;
        }
        else
        {//不在线  给回复包结果设置为不在线状态
            rs.m_result=userid_is_exist;
        }
    }
    m_tcp->SendData(clientfd,(char *)&rs,sizeof(rs));

}
//处理用户添加好友回复
void TcpKernel::AddFriendRs(int clientfd ,char* szbuf,int nlen)
{
    printf("clientfd:%d AddFriendRs\n", clientfd);
    STRU_ADD_FRIEND_RS *rs=(STRU_ADD_FRIEND_RS*)szbuf;

    if(rs->m_result==add_success)
    {//同意  写数据库  id A-B  B-A 更新好友列表
        char strSql[1024]="";
        sprintf(strSql,"insert into t_friend (idA,idB) values(%d,%d);",rs->m_userID,rs->m_friendID);
        m_sql->UpdataMysql(strSql);

        sprintf(strSql,"insert into t_friend (idA,idB) values(%d,%d);",rs->m_friendID,rs->m_userID);
        m_sql->UpdataMysql(strSql);

        //更新好友列表---todo
        UserGetFriendList(rs->m_userID);

    }
    SendMsgToId(rs->m_userID,szbuf,nlen);
}
//根据ID转发
void  TcpKernel::SendMsgToId(int id,char*szbuf,int nlen)
{
    //用户在线转发
    if(m_mapIDToUserInfo.find(id)!=m_mapIDToUserInfo.end())
    {
        UserInfo *user=m_mapIDToUserInfo[id];
        m_tcp->SendData(user->m_fd,szbuf,nlen);
    }
}
//处理聊天请求
void TcpKernel::ChatRq(int clientfd ,char* szbuf,int nlen)
{
     printf("clientfd:%d ChatRq\n", clientfd);

     STRU_CHAT_RQ *rq=(STRU_CHAT_RQ*)szbuf;

     //在线 成功发送聊天请求
     if(m_mapIDToUserInfo.find(rq->m_friendID)!=m_mapIDToUserInfo.end())
     {
         SendMsgToId(rq->m_friendID,szbuf,nlen);
     }
     else
     {//不在线则发送聊天回复包  说明要发的用户已经离线
         STRU_CHAT_RS rs;
         rs.m_result=user_is_offline;
         rs.m_userID=rq->m_userID;
         rs.m_friendID=rq->m_friendID;

         m_tcp->SendData(clientfd,(char*)&rs,sizeof(rs));
     }
}
//处理创建房间请求
void TcpKernel::CreateRoomRq(int clientfd, char *szbuf, int nlen)
{

    printf("clientfd:%d CreateRoomRq\n", clientfd);

    //拆包
    STRU_CREATEROOM_RQ *rq=(STRU_CREATEROOM_RQ *)szbuf;
     //map  查看有没有 user
    if(m_mapIDToUserInfo.find(rq->m_UserID)==m_mapIDToUserInfo.end())return ;

    UserInfo*info=m_mapIDToUserInfo[rq->m_UserID];
    //随机roomid  判定是否重复
    int roomid=0;
    do
    {
        roomid=rand()%999999+1;

    }while(roomid==0||m_mapRoomIDToUserInfoList.find(roomid)!=m_mapRoomIDToUserInfoList.end());
    //list 添加 用户  加入到map中

    info->m_roomid=roomid;
    list<UserInfo*>lst;
    lst.push_back(info);
    m_mapRoomIDToUserInfoList[roomid]=lst;

    //回复信息  rs
    STRU_CREATEROOM_RS rs;
    rs.m_RoomId=roomid;
    rs.m_lResult=1;

    m_tcp->SendData(clientfd,(char*)&rs,sizeof(rs));
}
//处理加入房间请求
void TcpKernel::JoinRoomRq(int clientfd, char *szbuf, int nlen)
{
     printf("clientfd:%d JoinRoomRq\n", clientfd);

     //拆包
     STRU_JOINROOM_RQ *rq=(STRU_JOINROOM_RQ*)szbuf;
     STRU_JOINROOM_RS rs;


     //先看map中有没有这个人   没有返回
     if(m_mapIDToUserInfo.find(rq->m_UserID)==m_mapIDToUserInfo.end())
     {
         rs.m_RoomID=0;
         rs.m_lResult=0;
         m_tcp->SendData(clientfd,(char*)&rs,sizeof(rs));
         return ;
     }

     UserInfo* joiner=m_mapIDToUserInfo[rq->m_UserID];
     joiner->m_roomid=rq->m_RoomID;
     //再看房间有没有   有to do  没有 返回
     if(m_mapRoomIDToUserInfoList.find(rq->m_RoomID)==m_mapRoomIDToUserInfoList.end())
     {
         rs.m_RoomID=rq->m_RoomID;
         rs.m_lResult=0;
         m_tcp->SendData(clientfd,(char*)&rs,sizeof(rs));
         return ;
     }

     //获取房间成员的列表
     list<UserInfo*>lst=m_mapRoomIDToUserInfoList[rq->m_RoomID];  //假定 map中lst链表中的节点全部都是有效的

     rs.m_RoomID=rq->m_RoomID;
     rs.m_lResult=1;
     m_tcp->SendData(clientfd,(char*)&rs,sizeof(rs));

     //有这个房间  写  加入人的信息

     STRU_ROOM_MEMBER_RQ joinrq;
     joinrq.m_UserID=rq->m_UserID;
     strcpy(joinrq.m_szUser,joiner->m_userName);
     //遍历列表  ---写房间内人的成员信息

     for(auto ite=lst.begin();ite!=lst.end();++ite)
     {
         UserInfo* inner=*ite;
         STRU_ROOM_MEMBER_RQ innerrq;
         innerrq.m_UserID=inner->m_id;
         strcpy(innerrq.m_szUser,inner->m_userName);

           //加入人的信息发送给房间内所有的人
         m_tcp->SendData(inner->m_fd,(char*)&joinrq,sizeof(joinrq));
         //房间内所有的人信息  发送给加入人
         m_tcp->SendData(joiner->m_fd,(char*)&innerrq,sizeof(innerrq));
     }


     //加入人的信息添加到list  然后更新

     lst.push_back(joiner);
     m_mapRoomIDToUserInfoList[rq->m_RoomID]=lst;   //浅拷贝
}
//处理离开房间请求
void TcpKernel::LeaveRoomRq(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d LeaveRoomRq\n", clientfd);

    //拆包
    STRU_LEAVEROOM_RQ *rq=(STRU_LEAVEROOM_RQ*)szbuf;
    //看map有没有这个人  没有  不处理
    if(m_mapIDToUserInfo.find(rq->m_nUserId)==m_mapIDToUserInfo.end())return ;
    UserInfo*leaver=m_mapIDToUserInfo[rq->m_nUserId];
    //看map  看房间有没有  没有 不处理

    if(m_mapRoomIDToUserInfoList.find(rq->m_RoomId)==m_mapRoomIDToUserInfoList.end())return ;
    //map中找房间  list
    list<UserInfo*>lst=m_mapRoomIDToUserInfoList[rq->m_RoomId];


    STRU_LEAVEROOM_RS rs;
    rs.m_UserID=leaver->m_id;
    strcpy(rs.szUserName,leaver->m_userName);
    //遍历list  不是这个人  发这个人离开   是这个人  erase 该节点

    for(auto ite=lst.begin();ite!=lst.end();)
    {
        UserInfo*inner=*ite;
        if(inner->m_id!=leaver->m_id)
        {
            m_tcp->SendData(inner->m_fd,(char*)&rs,sizeof(rs));
            ++ite;
        }
        else
        {
            ite=lst.erase(ite);
        }
    }
    //更新 map
    m_mapRoomIDToUserInfoList[rq->m_RoomId]=lst;
    //如果离开房间后  房间成员为零的话  就要删除对应的房间   从map中去除
    if(lst.size()==0)
    {
        m_mapRoomIDToUserInfoList.erase(rq->m_RoomId);
    }
}
//处理转发视频帧
void TcpKernel::VideFrame(int clientfd, char *szbuf, int nlen)
{


    printf("clientfd:%d VideFrame\n", clientfd);
    ///视频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// QByteArray videoFrame;
    ///

    //拆包
    char *tmp=szbuf;
    int type=*(int*)tmp;  //每次读四位
    tmp+=sizeof(int);

    int userId=*(int*)tmp;
    tmp+=sizeof(int);

    int roomId=*(int*)tmp;
    tmp+=sizeof(int);

    //找到map里面的房间  转发给其他人

    if(m_mapRoomIDToUserInfoList.find(roomId)==m_mapRoomIDToUserInfoList.end()) return ;
    list<UserInfo*>lst=m_mapRoomIDToUserInfoList[roomId];
    for(auto ite=lst.begin();ite!=lst.end();++ite)
    {
        UserInfo*user=*ite;
        if(user->m_id!=userId)
        {
            SendMsgToId(user->m_id,szbuf,nlen);
        }
    }

}


//处理转发音频帧
void TcpKernel::AudioFrame(int clientfd, char *szbuf, int nlen)
{


     printf("clientfd:%d AudioFrame\n", clientfd);
    ///音频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// QByteArray audioFrame;
    ///

    //拆包
    char *tmp=szbuf;
    int type=*(int*)tmp;  //每次读四位
    tmp+=sizeof(int);

    int userId=*(int*)tmp;
    tmp+=sizeof(int);

    int roomId=*(int*)tmp;
    tmp+=sizeof(int);

    //找到map里面的房间  转发给其他人

    if(m_mapRoomIDToUserInfoList.find(roomId)==m_mapRoomIDToUserInfoList.end()) return ;
    list<UserInfo*>lst=m_mapRoomIDToUserInfoList[roomId];
    for(auto ite=lst.begin();ite!=lst.end();++ite)
    {
        UserInfo*user=*ite;
        if(user->m_id!=userId)
        {
            SendMsgToId(user->m_id,szbuf,nlen);
        }
    }

}


//====================================================================狼人杀============================================================


//处理创建狼人杀房间的请求
void TcpKernel::CreateWolfRoomRq(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d CreateWolfRoomRq\n", clientfd);

   //拆包
    STRU_CREATEWOLFROOM_RQ *rq=(STRU_CREATEWOLFROOM_RQ *)szbuf;

    //看MAP中有么有这个人  没有就不处理

    if(m_mapIDToUserInfo.find(rq->m_UserID)==m_mapIDToUserInfo.end())return ;

    UserInfo*info=m_mapIDToUserInfo[rq->m_UserID];

    //狼人杀房间的消息
    WOLFPLAYERINFO *PlayerInfo=new WOLFPLAYERINFO;

    PlayerInfo->m_nType=DEF_PACK_WOLFROOM_PLAYER_INFO;
    PlayerInfo->m_PlayID=info->m_id;
    strcpy(PlayerInfo->szUserName,info->m_userName);
    PlayerInfo->m_Playerfd=clientfd;
    PlayerInfo->m_PlayerIconID=info->m_iconID;
    PlayerInfo->m_IsHouseOwner=ISHOUSEOWNER;      //当前创建房间的这个人就是房主



    //随机roomid  判定是否重复
    int roomid=0;
    do
    {
        roomid=rand()%9+1;

    }while(roomid==0||m_mapRoomIDToWolfPlayerInfoList.find(roomid)!=m_mapRoomIDToWolfPlayerInfoList.end());
    //list 添加 用户  加入到map中


    PlayerInfo->m_RoomID=roomid;
    list<WOLFPLAYERINFO*>lst;
    lst.push_back(PlayerInfo);
    m_mapRoomIDToWolfPlayerInfoList[roomid]=lst;


    //list<WOLFPLAYERINFO*>aa=m_mapRoomIDToWolfPlayerInfoList[roomid];

    //回复信息  rs
    STRU_CREATEWOLFROOM_RS rs;
    rs.m_RoomId=roomid;
    rs.m_lResult=1;

    m_tcp->SendData(clientfd,(char*)&rs,sizeof(rs));

}
//处理入座人的信息记录   更新到MAP映射表中
void TcpKernel::AddPlayerSeatInfo(int clientfd, char *szbuf, int nlen)
{
      printf("clientfd:%d AddPlayerSeatInfo\n", clientfd);

    WOLFPLAYERINFO *rq=(WOLFPLAYERINFO*)szbuf;

    //没有找到此人在线  不处理
    if(m_mapIDToUserInfo.find(rq->m_PlayID)==m_mapIDToUserInfo.end())return ;

    UserInfo * Userinfo=m_mapIDToUserInfo[rq->m_PlayID];


    //没有此房间  不处理
    if(m_mapRoomIDToWolfPlayerInfoList.find(rq->m_RoomID)==m_mapRoomIDToWolfPlayerInfoList.end())return ;


    list<WOLFPLAYERINFO*>lst=m_mapRoomIDToWolfPlayerInfoList[rq->m_RoomID];


    WOLFPLAYERINFO*PlayerInfo=new WOLFPLAYERINFO;


    for( auto ite=lst.begin();ite!=lst.end();)
    {
        WOLFPLAYERINFO *info=*ite;
        if(info->m_PlayID==rq->m_PlayID)
        {

            PlayerInfo->m_PlayID=info->m_PlayID;

            PlayerInfo->m_RoomID=info->m_RoomID;

            PlayerInfo->m_Playerfd=clientfd;

            strcpy(PlayerInfo->szUserName,Userinfo->m_userName);

            PlayerInfo->m_PlayerSeat=rq->m_PlayerSeat;

            PlayerInfo->m_PlayerIconID=rq->m_PlayerIconID;

            WOLFPLAYERINFO*playerIdentity=SetPlayerIdentity(info->m_PlayID,info->m_RoomID,HOLLOWMAN);
            PlayerInfo->m_PlayerIdentity=playerIdentity->m_PlayerIdentity;

            PlayerInfo->m_IsHouseOwner=info->m_IsHouseOwner;

            //删除原来的狼人杀房间内的信息
            lst.erase(ite);

            //添加新的到上面去
            lst.push_back(PlayerInfo);

            //重新和房间号进行绑定
            m_mapRoomIDToWolfPlayerInfoList[rq->m_RoomID]=lst;
            //开始添加加节点的情况  当删除的时候为0的时候  就跳出循环
            if(lst.size()==0)
            {
                break;
            }

            break;
        }
        //把新入座人的相关信息发送给在房间内的人
        else
        {
            //入坐人的信息发送给房间内所有的人  （  在线转发  ）
            SendMsgToId(info->m_PlayID,szbuf,nlen);
            ++ite;
        }

    }
    //更新座位信息后给自己也发一份自己的信息更改情况  (根据ID 在线转发)
    SendMsgToId(rq->m_PlayID,szbuf,nlen);


}
////玩家的角色种类
//typedef enum PLAYROLE
//{
//    CIVILIAN=2021,  //平民

//    SEER,   //预言家

//    HUNTER,  //猎人

//    WITCH, //女巫

//    WEREWOLF, //狼人

//    DEADPERSON, //死人

//    HOLLOWMAN, //透明人(指没有分配身份的人)


//}PLAYROLE;
//设置身份
WOLFPLAYERINFO* TcpKernel::SetPlayerIdentity(int PlayerID,int WolfRoomID,int Identity)
{
    //没有找到此人在线  不处理
    if(m_mapIDToUserInfo.find(PlayerID)==m_mapIDToUserInfo.end())return NULL;
    //没有此房间  不处理
    if(m_mapRoomIDToWolfPlayerInfoList.find(WolfRoomID)==m_mapRoomIDToWolfPlayerInfoList.end())return NULL;

    list<WOLFPLAYERINFO*>lst=m_mapRoomIDToWolfPlayerInfoList[WolfRoomID];

    WOLFPLAYERINFO*PlayerInfo=new WOLFPLAYERINFO;

    for(auto ite=lst.begin();ite!=lst.end();++ite)
    {
        WOLFPLAYERINFO *info=*ite;
        if(info->m_PlayID==PlayerID)
        {
            //设置身份信息

            PlayerInfo->m_PlayerIdentity=Identity;
        }
    }

    return PlayerInfo;

}
//处理加入狼人杀房间请求
void TcpKernel::JoinWolfRoomRq(int clientfd, char *szbuf, int nlen)
{
     printf("clientfd:%d JoinWolfRoomRq\n", clientfd);
    //拆包
    STRU_JOINWOLFROOM_RQ *rq=(STRU_JOINWOLFROOM_RQ*)szbuf;

    //登录回复包
    STRU_JOINWOLFROOM_RS rs;


    //先看map中有没有这个人   没有返回
    if(m_mapIDToUserInfo.find(rq->m_UserID)==m_mapIDToUserInfo.end())
    {
        rs.m_RoomID=0;
        rs.m_lResult=0;
        m_tcp->SendData(clientfd,(char*)&rs,sizeof(rs));
        return ;
    }


//    UserInfo:

//    int  m_fd;
//    int  m_id;
//    int  m_iconID;
//    int  m_state;
//    int  m_roomid;
//    char m_userName[MAX_SIZE];
//    char m_feeling[MAX_SIZE];

    UserInfo* joiner=m_mapIDToUserInfo[rq->m_UserID];


    //再看房间有没有   有to do  没有 返回
    if(m_mapRoomIDToWolfPlayerInfoList.find(rq->m_RoomID)==m_mapRoomIDToWolfPlayerInfoList.end())
    {
        rs.m_RoomID=rq->m_RoomID;
        rs.m_lResult=0;
        m_tcp->SendData(clientfd,(char*)&rs,sizeof(rs));
        return ;
    }

    //获取房间成员的列表
    list<WOLFPLAYERINFO*>lst=m_mapRoomIDToWolfPlayerInfoList[rq->m_RoomID];  //假定 map中lst链表中的节点全部都是有效的



    //有这个房间  写  加入人的信息

    WOLFPLAYERINFO joinrqInfo;
    joinrqInfo.m_nType=DEF_PACK_WOLFROOM_PLAYER_INFO;
    joinrqInfo.m_PlayID=rq->m_UserID;
    joinrqInfo.m_Playerfd=clientfd;
    strcpy(joinrqInfo.szUserName,joiner->m_userName);
    joinrqInfo.m_PlayerSeat=-1;                                              //加入房间的初始座位ID为0
    joinrqInfo.m_IsHouseOwner=NOHOUSEOWNER;         //加入房间的每个人都不是房主
    joinrqInfo.m_PlayerIconID=joiner->m_iconID;
    joinrqInfo.m_PlayerIdentity=HOLLOWMAN;           //加入房间的每个人状态设为透明人状态
    joinrqInfo.m_RoomID=rq->m_RoomID;

    //遍历列表

    for(auto ite=lst.begin();ite!=lst.end();++ite)
    {
        WOLFPLAYERINFO* inner=*ite;
        //---写房间内人的成员信息
        WOLFPLAYERINFO innerrq;
        innerrq.m_nType=DEF_PACK_WOLFROOM_PLAYER_INFO;
        innerrq.m_PlayID=inner->m_PlayID;
        innerrq.m_RoomID=inner->m_RoomID;
        innerrq.m_Playerfd=inner->m_Playerfd;
        strcpy(innerrq.szUserName,inner->szUserName);
        innerrq.m_PlayerSeat=inner->m_PlayerSeat;
        innerrq.m_IsHouseOwner=inner->m_IsHouseOwner;  //不是房主
        innerrq.m_PlayerIconID=inner->m_PlayerIconID;
        innerrq.m_PlayerIdentity=inner->m_PlayerIdentity;  //身份

        //加入人的信息发送给房间内所有的人
        m_tcp->SendData(inner->m_Playerfd,(char*)&joinrqInfo,sizeof(joinrqInfo));
        //房间内所有的人信息  发送给加入人
        m_tcp->SendData(joiner->m_fd,(char*)&innerrq,sizeof(innerrq));


        //把准备玩家的信息也发送给加入人
        STRU_praprePlayerID prap;
        prap.playerID=innerrq.m_PlayID;
        prap.playerSeat=innerrq.m_PlayerSeat;
        prap.wolfRoomID=innerrq.m_RoomID;

        m_tcp->SendData(joiner->m_fd,(char*)&prap,sizeof(prap));
    }


    //加入人的信息添加到list  然后更新

    WOLFPLAYERINFO *joinrq=new WOLFPLAYERINFO;
    joinrq->m_nType=DEF_PACK_WOLFROOM_PLAYER_INFO;
    joinrq->m_PlayID=rq->m_UserID;
    joinrq->m_Playerfd=clientfd;
    strcpy(joinrq->szUserName,joiner->m_userName);
    joinrq->m_PlayerSeat=-1;                                              //加入房间的初始座位ID为0
    joinrq->m_IsHouseOwner=NOHOUSEOWNER;         //加入房间的每个人都不是房主
    joinrq->m_PlayerIconID=joiner->m_iconID;
    joinrq->m_PlayerIdentity=HOLLOWMAN;           //加入房间的每个人状态设为透明人状态
    joinrq->m_RoomID=rq->m_RoomID;

    lst.push_back(joinrq);
    m_mapRoomIDToWolfPlayerInfoList[rq->m_RoomID]=lst;   //浅拷贝

    rs.m_RoomID=rq->m_RoomID;
    rs.m_lResult=1;
    rs.m_playerID=rq->m_UserID;
    m_tcp->SendData(clientfd,(char*)&rs,sizeof(rs));

}
//处理离开狼人杀房间请求
void TcpKernel::leaveWolfRoomRq(int clientfd, char *szbuf, int nlen)
{
     printf("clientfd:%d leaveWolfRoomRq\n", clientfd);
    //拆包
    STRU_LEAVEWOLFROOM_RQ*rq=(STRU_LEAVEWOLFROOM_RQ*)szbuf;



    //没找到
    if(m_mapIDToUserInfo.find(rq->m_nUserId)==m_mapIDToUserInfo.end())return ;

    UserInfo*info=m_mapIDToUserInfo[rq->m_nUserId];

    //写回复包
    STRU_LEAVEWOLFROOM_RS rs;
    rs.m_UserID=info->m_id;
    strcpy(rs.szUserName,info->m_userName);

    //找房间  没找到直接结束
    if(m_mapRoomIDToWolfPlayerInfoList.find(rq->m_RoomId)==m_mapRoomIDToWolfPlayerInfoList.end())return ;


    //获得对应的房间内的成员链表信息
    list<WOLFPLAYERINFO*>lst=m_mapRoomIDToWolfPlayerInfoList[rq->m_RoomId];

    //遍历链表  把要退出房间的人的信息  发送给房间里所有的人


    for(auto ite=lst.begin();ite!=lst.end();)
    {
        WOLFPLAYERINFO*inner=*ite;
        //找到这个人  就把他的相关信息从链表里删除
        if(inner->m_PlayID==rq->m_nUserId)
        {
            ite=lst.erase(ite);

            if(lst.size()==0)
            {
                break;
            }
        }
        else
        { //把离开人的消息发送给房间里的所有人
            m_tcp->SendData(inner->m_Playerfd,(char*)&rs,sizeof(rs));
            ++ite;
        }
    }

    //更新list链表

    m_mapRoomIDToWolfPlayerInfoList[rq->m_RoomId]=lst;  //浅拷贝

    //如果离开房间后  房间成员为零的话  就要删除对应的房间   从map中去除
    if(lst.size()==0)
    {
        m_mapRoomIDToWolfPlayerInfoList.erase(rq->m_RoomId);
    }
}
//处理客户端发来的准备请求
void TcpKernel::PrapreRq(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d PrapreRq\n", clientfd);


    //拆包
    STRU_PREPARE_RQ*rq=(STRU_PREPARE_RQ*)szbuf;

    m_mapPlayerIDPrapreInfo[rq->playerID]=1;



    //没有找到此人在线  不处理
    if(m_mapIDToUserInfo.find(rq->playerID)==m_mapIDToUserInfo.end())return ;

    //没有此房间  不处理
    if(m_mapRoomIDToWolfPlayerInfoList.find(rq->wolfRoomID)==m_mapRoomIDToWolfPlayerInfoList.end())return ;


    list<WOLFPLAYERINFO*>lst=m_mapRoomIDToWolfPlayerInfoList[rq->wolfRoomID];



    for( auto ite=lst.begin();ite!=lst.end(); ++ite)
    {
        WOLFPLAYERINFO *info=*ite;
        if(info->m_PlayID!=rq->playerID)
        {
            // （  在线转发  ）
            SendMsgToId(info->m_PlayID,szbuf,nlen);
        }
    }

    if(m_mapPlayerIDPrapreInfo.size()==8)
    {
        //TO DO------------游戏开始  给每个客户端发送游戏开始的 提示  然后 给每个客户端分配身份  随后进行相操作
        PlayerIdentityID(rq->wolfRoomID);

    }

}
//处理浪人杀房间发来的聊天请求
void TcpKernel::ChatRqWolf(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d ChatRqWolf\n", clientfd);
    //拆包
    STRU_WOLFROOM_CHAT_RQ*rq=(STRU_WOLFROOM_CHAT_RQ*)szbuf;

    if(m_mapRoomIDToWolfPlayerInfoList.find(rq->m_wolfRoomID)==m_mapRoomIDToWolfPlayerInfoList.end())return ;

    list<WOLFPLAYERINFO*>lst=m_mapRoomIDToWolfPlayerInfoList[rq->m_wolfRoomID];

    for(auto ite=lst.begin();ite!=lst.end();++ite)
    {
        WOLFPLAYERINFO *inner=*ite;

        if(inner->m_PlayID!=rq->m_playerID)
        {
            //在线转发
            SendMsgToId(inner->m_PlayID,szbuf,nlen);
        }
    }

}
 //处理狼人杀房间成员发来的音频
void TcpKernel::AudioFrameWolf(int clientfd, char *szbuf, int nlen)
{

    printf("clientfd:%d AudioFrameWolf\n", clientfd);
   ///音频数据帧
   /// 成员描述
   /// int type;
   /// int userId;
   /// int roomId;
   /// QByteArray audioFrame;
   ///

   //拆包
   char *tmp=szbuf;
   int type=*(int*)tmp;  //每次读四位
   tmp+=sizeof(int);

   int userId=*(int*)tmp;
   tmp+=sizeof(int);

   int roomId=*(int*)tmp;
   tmp+=sizeof(int);

   //找到map里面的房间  转发给其他人

   if(m_mapRoomIDToWolfPlayerInfoList.find(roomId)==m_mapRoomIDToWolfPlayerInfoList.end()) return ;
   list<WOLFPLAYERINFO*>lst=m_mapRoomIDToWolfPlayerInfoList[roomId];
   for(auto ite=lst.begin();ite!=lst.end();++ite)
   {
       WOLFPLAYERINFO*user=*ite;
       if(user->m_PlayID!=userId)
       {
           SendMsgToId(user->m_PlayID,szbuf,nlen);
       }
   }
}

//    CIVILIAN=2021,  //平民

//    SEER,   //预言家

//    HUNTER,  //猎人

//    WITCH, //女巫

//    WEREWOLF, //狼人

//    DEADPERSON, //死人

//    HOLLOWMAN, //透明人(指没有分配身份的人)

//随机分配身份
void TcpKernel::PlayerIdentityID(int WolfRoomID)
{

    printf(" PlayerIdentityID\n");
    //游戏天数加一
    m_GameDays+=1;
//    //随机IdentutyID  判定是否重复
//    int N=8;
//    vector<int> nums(0);
//    int t;
//    for (int i = 0; nums.size() != N; i++) {
//        t = rand() % N;
//        nums.push_back(t);
//        if (i > 0) //从第二个元素开始
//            if (find(nums.begin(), nums.end() - 1, t) == nums.end() - 1)
//                continue;
//            else
//                nums.pop_back();
//    }
//    //0-2  为狼人身份 3-4 为民 5 为 预言家 6 为猎人 7 为女巫

    //查找有无该房间  没有直接结束
    if(m_mapRoomIDToWolfPlayerInfoList.find(WolfRoomID)==m_mapRoomIDToWolfPlayerInfoList.end())return ;

    list<WOLFPLAYERINFO*>lst=m_mapRoomIDToWolfPlayerInfoList[WolfRoomID];


    //测试用的
    m_mapPlayerIDToIdentityID[3]=SEER;  //预言家
    m_mapPlayerIDToIdentityID[4]=WEREWOLF; //狼
    m_mapPlayerIDToIdentityID[5]=WEREWOLF;  //狼
    m_mapPlayerIDToIdentityID[6]=WEREWOLF; //狼
    m_mapPlayerIDToIdentityID[7]=CIVILIAN;  //民
    m_mapPlayerIDToIdentityID[8]=CIVILIAN; //民
    m_mapPlayerIDToIdentityID[9]=WITCH;  //预言家
    m_mapPlayerIDToIdentityID[10]=HUNTER; //狼

    //遍历链表 然后改变里面的信息  发送游戏身份 以及游戏开始的消息
    //int i=0;
    int j=3;
    for(auto ite=lst.begin();ite!=lst.end(); ++ite)
    {
        //循环判断 得到对应的身份
            WOLFPLAYERINFO*info=*ite;

//            int Identity=0;
            //遍历随机数的表 从头开始判断每个数是多少  然后开始分配身份
//            switch(nums[i])
//            {
//            case 0:
//                Identity=WEREWOLF;  //狼人
//                break;
//            case 1:
//                Identity=WEREWOLF;
//                break;
//            case 2:
//                Identity=WEREWOLF;
//                break;
//            case 3:
//                Identity=CIVILIAN;  //平民
//                break;
//            case 4:
//                Identity=CIVILIAN;
//                break;
//            case 5:
//                Identity=SEER;   //预言家
//                break;
//            case 6:
//                Identity=HUNTER;  //猎人
//                break;
//            case 7:
//                Identity=WITCH;  //女巫
//                break;
//            default:break;
//            }


            //发送消息
            STRU_STARTGAME_INFO rq;
            rq.m_playerID=info->m_PlayID;
            rq.m_wolfRoomID=WolfRoomID;
            //            rq.m_playerIdentityID=Identity;
            rq.m_playerIdentityID=m_mapPlayerIDToIdentityID[j];
            rq.m_gamedays=m_GameDays;
            rq.m_playerSeat=info->m_PlayerSeat;


            //拿每个玩家的ID和身份 形成一个映射表
//            m_mapPlayerIDToIdentityID[rq.m_playerID]=Identity;

            //在线转发
            SendMsgToId(rq.m_playerID,(char*)&rq,sizeof(rq));

           // i++;
            j++;   //测试数据
    }

    //把每个人的身份  分开记录
    for( auto ite = m_mapPlayerIDToIdentityID.begin(); ite != m_mapPlayerIDToIdentityID.end(); ++ite)
    {
        if(ite->second==CIVILIAN)       //平民
        {
            //记录民的数量
            civilianNums.push_back(ite->first);
            //记录
            civilianplayers.push_back(ite->first);
        }
        if(ite->second==WEREWOLF)  //狼人
        {
            //记录狼的数量
            wolfNums.push_back(ite->first);
            //记录
            wolfplayers.push_back(ite->first);
        }
        if(ite->second==SEER)  //预言家
        {
            //记录神的数量
            GodNums.push_back(ite->first);

        }
        if(ite->second==HUNTER)  //猎人
        {

            //记录神的数量
            GodNums.push_back(ite->first);
        }
        if(ite->second==WITCH)
        {
            //记录神的数量
            GodNums.push_back(ite->first);
        }
    }



    //先给第一个狼人发送消息
    for(auto ite=wolfplayers.begin();ite!=wolfplayers.end();)
    {
        STRU_WEREWOLF_RQ  wolfrq;
        wolfrq.m_playerID=*ite;
        ite=wolfplayers.erase(ite);

        //在线转发
        SendMsgToId(wolfrq.m_playerID,(char*)&wolfrq,sizeof(wolfrq));
        return ;
    }

}
//========================================================================================================================================
//狼人的操作回复
void TcpKernel::WEREWOLF_RS(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d WEREWOLF_RS\n",clientfd);
    //拆包
    STRU_WEREWOLF_RS*rq=(STRU_WEREWOLF_RS*)szbuf;
    //狼人没有杀人的情况  TO DO
    if(rq->m_KillPlayerID==0)
    {
        NoKillPlayer++;

        KillPlayerID=0;
        //三个狼人都没有杀人  就发送消息给女巫
        if(NoKillPlayer==3)
        {
            //发送信息给女巫玩家
            for( auto ite = m_mapPlayerIDToIdentityID.begin(); ite != m_mapPlayerIDToIdentityID.end();++ite)
            {
                //女巫
                if(ite->second==WITCH)
                {
                    //写包  发送包
                    STRU_WITCH_RQ rqq;

                    rqq.KillPlayerID=0;  //狼人没有杀人

                    //在线转发  转发给女巫
                    SendMsgToId(ite->first,(char*)&rqq,sizeof(rqq));

                    return;

                }
            }
        }

    }
    else
    {  //狼人杀人的情况

        vector<int>::iterator result = find( KillNums.begin( ), KillNums.end( ), rq->m_KillPlayerID ); //查找
        if(result == KillNums.end( ))   //没找到
        {
            //把传来的要杀死的玩家存储起来
            KillNums.push_back(rq->m_KillPlayerID);
            NoKillPlayerNUms++;
            //证明三个狼人杀的都不是同一个人  即杀第一个传来的玩家
            if(NoKillPlayerNUms==3)
            {
                //记录狼人杀死了那个玩家
                Deathplayers.push_back(KillNums[0]);
                //记录被杀死的玩家杀哪一个
                KillPlayerID=rq->m_KillPlayerID;

                //判断游戏有没有结束 谁赢了
                int fal=WhoVictory(rq->wolfRoom);
                if(fal)return ;


                //发送要杀死的玩家ID给女巫玩家
                for( auto ite = m_mapPlayerIDToIdentityID.begin(); ite != m_mapPlayerIDToIdentityID.end();)
                {
                    //女巫
                    if(ite->second==WITCH)
                    {
                        //写包  发送包
                        STRU_WITCH_RQ rqq;

                        rqq.KillPlayerID=KillNums[0];

                        //在线转发  转发给女巫
                        SendMsgToId(ite->first,(char*)&rqq,sizeof(rqq));

                        return ;

                    }
                    else
                    {
                        ++ite;
                    }
                }

            }

        }
        else      //找到
        {
            KillPlayerNums++;
            //把传来的要杀死的玩家存储起来
            KillNums.push_back(rq->m_KillPlayerID);
            //当出现了两个狼同时杀一个人的时候  这时候就立刻发消息给女巫
            if(KillPlayerNums==1)
            {
                //记录狼人杀死了那个玩家
                Deathplayers.push_back(rq->m_KillPlayerID);

                //判断游戏有没有结束 谁赢了
                int fal=WhoVictory(rq->wolfRoom);
                if(fal)return ;

                //记录被杀死的玩家杀哪一个
                KillPlayerID=rq->m_KillPlayerID;

                //发送狼人的决定给最后一个狼人
                WolfDecide wolfdeciderq;

                wolfdeciderq.m_wolfkillplayerID=rq->m_KillPlayerID;

                int fiallywolfID=wolfplayers.back();

                //在线转发
                SendMsgToId(fiallywolfID,(char*)&wolfdeciderq,sizeof(wolfdeciderq));

                //发送要杀死的玩家ID给女巫玩家
                for( auto ite = m_mapPlayerIDToIdentityID.begin(); ite != m_mapPlayerIDToIdentityID.end();)
                {
                    //女巫
                    if(ite->second==WITCH)
                    {
                        //写包  发送包
                        STRU_WITCH_RQ rqq;

                        rqq.KillPlayerID=rq->m_KillPlayerID;

                        //在线转发  转发给女巫
                        SendMsgToId(ite->first,(char*)&rqq,sizeof(rqq));

                        return ;

                    }
                    else
                    {
                        ++ite;
                    }
                }

            }
        }

    }
    //再给下一个狼人发送消息
    if(wolfplayers.size()>0)
    {
        for(auto ite=wolfplayers.begin();ite!=wolfplayers.end();)
        {
            STRU_WEREWOLF_RQ  wolfrq;
            wolfrq.m_playerID=*ite;
            ite=wolfplayers.erase(ite);

            //在线转发
            SendMsgToId(wolfrq.m_playerID,(char*)&wolfrq,sizeof(wolfrq));
            break;
        }
    }

}
//处理女巫的操作
void TcpKernel::WITCH_RS(int clientfd, char *szbuf, int nlen)
{
     printf("clientfd:%d WITCH_RS\n",clientfd);

     //拆包
     STRU_WITCH_RS *rs=(STRU_WITCH_RS*)szbuf;

     //女巫有没有救人  女巫 有没有 毒人

     //救人了
     if(rs->IsSavePlayer==ISSAVEPLAYER)
     {
         //删除被人杀的记录
         //在vector中查找指定元素
         vector<int>::iterator iter=find(Deathplayers.begin(),Deathplayers.end(),KillPlayerID);

         //删除指定元素
         if(iter!=Deathplayers.end())Deathplayers.erase(iter);
         //清空
         KillPlayerID=0;
     }
     //没救人 不做处理


     //毒人了
     if(rs->posionPlayerID!=0)
     {
         //把被毒死的人存储起来
         Deathplayers.push_back(rs->posionPlayerID);



         //记录被毒人的ID
         PosionPlayerID=rs->posionPlayerID;
         //判断游戏有没有结束 谁赢了
         int fal=WhoVictory(rs->wolfRoom);
         if(fal)return ;
     }

     //给猎人发送消息
     for( auto ite = m_mapPlayerIDToIdentityID.begin(); ite != m_mapPlayerIDToIdentityID.end(); ++ite)
     {
         if(ite->second==HUNTER)
         {
             //写包
             STRU_HUNTER_RQ rq;

             //在线发送
             SendMsgToId(ite->first,(char*)&rq,sizeof(rq));

             return ;
         }
     }

}
//预言家操作回复
void TcpKernel::SEER_RS(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d SEER_RS\n",clientfd);
    //拆包
    STRU_SEER_RS*rs=(STRU_SEER_RS*)szbuf;

    CHECKPLAYERINFO infors; //查验人信息包

    //查身份
    if(m_mapPlayerIDToIdentityID.find(rs->CheckPlayerID)!=m_mapPlayerIDToIdentityID.end())
    {
        infors.checkplayerIdentity=m_mapPlayerIDToIdentityID[rs->CheckPlayerID];
    }

    //在线转发 把查验结果发回给预言家
    SendMsgToId(rs->m_playerID,(char*)&infors,sizeof(infors));

    //判断游戏有没有结束 谁赢了
    int fal=WhoVictory(rs->wolfRoom);
    if(fal)return ;

}
//猎人的操作回复
void TcpKernel::HUNTER_RS(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d HUNTER_RS\n",clientfd);
    //拆包
    STRU_HUNTER_RS *rs=(STRU_HUNTER_RS*)szbuf;

    //判断有无带走人
    if(rs->TakeAwayPlayerID!=0)
    {
        //把被带走的人存储起来
        Deathplayers.push_back(rs->TakeAwayPlayerID);
        //记录 带走了那个人
        TakePlayrID=rs->TakeAwayPlayerID;

        //判断游戏有没有结束 谁赢了
        int fal=WhoVictory(rs->wolfRoom);
        if(fal)return ;



    }

    //给预言家发送消息  叫预言家验人 预言家开始操作
    for( auto ite = m_mapPlayerIDToIdentityID.begin(); ite != m_mapPlayerIDToIdentityID.end(); ++ite)
    {
        if(ite->second==SEER)  //预言家
        {
            //写包
            STRU_SEER_RQ rq;

            //在线转发
            SendMsgToId(ite->first,(char*)&rq,sizeof(rq));

            return ;
        }

    }
}
 //天亮了  给房间内还活着的玩家 发送 昨晚的情况
void TcpKernel::DayBreaks()
{


}
//处理客户端发来的天亮信息包
void TcpKernel::DayBreaks_Rq(int clientfd, char *szbuf, int nlen)
{
     printf("clientfd:%d DayBreaks_Rq\n",clientfd);

     //拆包
     STRU_DayBreaks *rs=(STRU_DayBreaks*)szbuf;

     //判断游戏有没有结束 谁赢了
     int fal=WhoVictory(rs->m_wolfRoom);
     if(fal)return ;
     //天亮了  给房间内的玩家 发送 昨晚的情况
     //写包
     STRU_DayBreaks rq;
     rq.m_TakePlayrID=TakePlayrID;
     rq.m_KillPlayerID=KillPlayerID;
     rq.m_PosionPlayerID=PosionPlayerID;
     STRU_DeathPlayer Deathrq;
     //有玩家死亡
     if(Deathplayers.size()>0)
     {
         //删除对应的映射节点
             for( auto ite = m_mapPlayerIDToIdentityID.begin(); ite != m_mapPlayerIDToIdentityID.end();)
             {
                 if(ite->first==KillPlayerID)
                 {
                     SendMsgToId(ite->first,(char*)&Deathrq,sizeof(Deathrq));
                     ite=m_mapPlayerIDToIdentityID.erase(ite);
                 }
                 else if(ite->first==PosionPlayerID)
                 {
                     SendMsgToId(ite->first,(char*)&Deathrq,sizeof(Deathrq));
                     ite=m_mapPlayerIDToIdentityID.erase(ite);
                 }
                 else if(ite->first==TakePlayrID)
                 {
                     SendMsgToId(ite->first,(char*)&Deathrq,sizeof(Deathrq));
                     ite=m_mapPlayerIDToIdentityID.erase(ite);
                 }
                 else
                 {
                     ++ite;
                 }
             }
     }


     //给房间内所有的玩家发送昨晚上的 消息情况  发送天亮信息包
     if(m_mapRoomIDToWolfPlayerInfoList.find(rs->m_wolfRoom)==m_mapRoomIDToWolfPlayerInfoList.end())return ;

     list<WOLFPLAYERINFO*>lst=m_mapRoomIDToWolfPlayerInfoList[rs->m_wolfRoom];

     for(auto ite=lst.begin();ite!=lst.end();++ite)
     {
         WOLFPLAYERINFO*info=*ite;

         //在线转发
         SendMsgToId(info->m_PlayID,(char*)&rq,sizeof(rq));

     }

}

//处理玩家发来的投票请求
void TcpKernel::VoteRq(int clientfd, char *szbuf, int nlen)
{

    if(Votefalse)
    {
        printf("clientfd:%d VoteRq\n",clientfd);
        //拆包
        STRU_Vote_RQ *rq=(STRU_Vote_RQ*)szbuf;

        STRU_Vote_RS  rs;



        //记录当前活着的人数
        int AlivePlayrNums=m_mapPlayerIDToIdentityID.size();


        vector<int>::iterator iter = VoteNums.begin();
        //找到
        while ((iter = find(iter, VoteNums.end(), rq->VotePlayerID)) != VoteNums.end())  //当iter等于A.end()时，意味着处理完毕，退出循环
        {
            // 使用找到的iter进行其它处理，在这里加上您的代码
            VotePlayerNums++;

            //如果被投票的人大于 活着的人的一半  则被投票出局
            if(VotePlayerNums>=(AlivePlayrNums/2))
            {
                //把投票标志位设置为0  不让其他投票人再次进来
                Votefalse=0;
                //把被票死的人存储起来
                Deathplayers.push_back(rq->VotePlayerID);
                //记录谁被票死
                VotePlayerID=rq->VotePlayerID;
                //判断游戏有没有结束 谁赢了
                int fal=WhoVictory(rq->wolfRoom);
                if(fal)return ;

                rs.WhereVotePlayerID=rq->VotePlayerID;
                //给房间内的成员发送投票结果消息 消息
                if(m_mapRoomIDToWolfPlayerInfoList.find(rq->wolfRoom)!=m_mapRoomIDToWolfPlayerInfoList.end())
                {
                    list<WOLFPLAYERINFO*>lst=m_mapRoomIDToWolfPlayerInfoList[rq->wolfRoom];
                    for(auto ite=lst.begin();ite!=lst.end();++ite)
                    {
                        WOLFPLAYERINFO *inner=*ite;
                        //在线转发
                        SendMsgToId(inner->m_PlayID,(char*)&rs,sizeof(rs));
                    }
                }
                //删除对应的映射节点
                for( auto ite = m_mapPlayerIDToIdentityID.begin(); ite != m_mapPlayerIDToIdentityID.end();)
                {
                    if(ite->first==rq->VotePlayerID)
                    {
                        ite=m_mapPlayerIDToIdentityID.erase(ite);
                    }
                    else
                    {
                        ++ite;
                    }
                }

            }

            iter++;  //iter加1，作为下次查找的起点。
        }
        //把被投票的人存储起来  记录那个人被投票
        VoteNums.push_back(rq->VotePlayerID);
    }

}
//判断是否游戏结束  谁胜利了
int TcpKernel::IsGameOver()
{
    //遍历被死掉的人
    for(auto ite=Deathplayers.begin();ite!=Deathplayers.end();++ite)
    {
        for(auto Godplayer=GodNums.begin();Godplayer!=GodNums.end();)
        {
            if(*Godplayer==*ite)
            {
                Godplayer=GodNums.erase(Godplayer);
            }
            else
            {
                ++Godplayer;
            }
        }
        for(auto civilanplayer=civilianNums.begin();civilanplayer!=civilianNums.end();)
        {
            if(*civilanplayer==*ite)
            {
                civilanplayer=civilianNums.erase(civilanplayer);
            }
            else
            {
                ++civilanplayer;
            }
        }
        for(auto wolfplayer=wolfNums.begin();wolfplayer!=wolfNums.end();)
        {
            if(*wolfplayer==*ite)
            {
                wolfplayer=wolfNums.erase(wolfplayer);
            }
            else
            {
                ++wolfplayer;
            }
        }
    }
    //狼人胜利
    if((GodNums.size()<=0)||(civilianNums.size()<=0))
    {
        return WOLFVICTORY;
    }
    //好人胜利
    else if((wolfNums.size()<=0))
    {
        return GOODIESVICTORY;
    }
    else
    {  //游戏正在继续
        return GAMEING;
    }
}
//开始下一天游戏
void TcpKernel::InToNightRq(int clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d VoteRq\n",clientfd);
    //拆包
    InToNight *intonightrq=(InToNight*)szbuf;


    //游戏天数加一
    m_GameDays+=1;

    //查找有无该房间  没有直接结束
    if(m_mapRoomIDToWolfPlayerInfoList.find(intonightrq->wolfRoom)==m_mapRoomIDToWolfPlayerInfoList.end())return ;

    list<WOLFPLAYERINFO*>lst=m_mapRoomIDToWolfPlayerInfoList[intonightrq->wolfRoom];

    //遍历链表  发送天数信息
    for(auto ite=lst.begin();ite!=lst.end(); ++ite)
    {
        //循环判断 得到对应的身份
        WOLFPLAYERINFO*info=*ite;

        //发送消息
        ChangeDady rq;
        rq.GameDays=m_GameDays;
        //在线转发
        SendMsgToId(info->m_PlayID,(char*)&rq,sizeof(rq));

    }

    //把每个人的身份  分开记录
    for( auto ite = m_mapPlayerIDToIdentityID.begin(); ite != m_mapPlayerIDToIdentityID.end(); ++ite)
    {
        if(ite->second==CIVILIAN)       //平民
        {
            //记录民的数量
            civilianNums.push_back(ite->first);
            //记录
            civilianplayers.push_back(ite->first);
        }
        if(ite->second==WEREWOLF)  //狼人
        {
            //记录狼的数量
            wolfNums.push_back(ite->first);
            //记录
            wolfplayers.push_back(ite->first);
        }
        if(ite->second==SEER)  //预言家
        {
            //记录神的数量
            GodNums.push_back(ite->first);

        }
        if(ite->second==HUNTER)  //猎人
        {

            //记录神的数量
            GodNums.push_back(ite->first);
        }
        if(ite->second==WITCH)
        {
            //记录神的数量
            GodNums.push_back(ite->first);
        }
    }


    //判断谁胜利了 然后给房间内的成员发送消息
    int fal=WhoVictory(intonightrq->wolfRoom);
    if(fal)return ;

    //先给第一个狼人发送消息
    for(auto ite=wolfplayers.begin();ite!=wolfplayers.end();)
    {
        STRU_WEREWOLF_RQ  wolfrq;
        wolfrq.m_playerID=*ite;
        ite=wolfplayers.erase(ite);

        //在线转发
        SendMsgToId(wolfrq.m_playerID,(char*)&wolfrq,sizeof(wolfrq));
        return ;
    }


}
//判断谁胜利了 然后给房间内的成员发送消息
int TcpKernel::WhoVictory(int wolfRoom)
{
    //写包
    STRU_DayBreaks rq;
    rq.m_TakePlayrID=TakePlayrID;
    rq.m_KillPlayerID=KillPlayerID;
    rq.m_PosionPlayerID=PosionPlayerID;
    rq.m_isGameOver=1;   //代表游戏胜利
    STRU_DeathPlayer Deathrq;
    //有玩家死亡
    if(Deathplayers.size()>0)
    {
        //删除对应的映射节点
            for( auto ite = m_mapPlayerIDToIdentityID.begin(); ite != m_mapPlayerIDToIdentityID.end();)
            {
                if(ite->first==KillPlayerID)
                {
                    SendMsgToId(ite->first,(char*)&Deathrq,sizeof(Deathrq));
                    ite=m_mapPlayerIDToIdentityID.erase(ite);
                }
                else if(ite->first==PosionPlayerID)
                {
                    SendMsgToId(ite->first,(char*)&Deathrq,sizeof(Deathrq));
                    ite=m_mapPlayerIDToIdentityID.erase(ite);
                }
                else if(ite->first==TakePlayrID)
                {
                    SendMsgToId(ite->first,(char*)&Deathrq,sizeof(Deathrq));
                    ite=m_mapPlayerIDToIdentityID.erase(ite);
                }
                else
                {
                    ++ite;
                }
            }
    }


    //给房间内所有的玩家发送昨晚上的 消息情况  发送天亮信息包

    list<WOLFPLAYERINFO*>lst=m_mapRoomIDToWolfPlayerInfoList[wolfRoom];

    for(auto ite=lst.begin();ite!=lst.end();++ite)
    {
        WOLFPLAYERINFO*info=*ite;

        //在线转发
        SendMsgToId(info->m_PlayID,(char*)&rq,sizeof(rq));

    }
    //判断游戏有没有结束 谁赢了
    int fal=0;
    int GameResult=IsGameOver();
    if(GameResult!=GAMEING)
    {
        GameOver gameOverrq;
        //好人胜利
        if(GameResult==GOODIESVICTORY)
        {
            //写包
            gameOverrq.m_GameResult=GOODIESVICTORY;
        }
        //狼人胜利
        if(GameResult==WOLFVICTORY)
        {
            //写包
            gameOverrq.m_GameResult=WOLFVICTORY;
        }
        //给房间内的成员发送 消息
        if(m_mapRoomIDToWolfPlayerInfoList.find(wolfRoom)!=m_mapRoomIDToWolfPlayerInfoList.end())
        {
            list<WOLFPLAYERINFO*>lst=m_mapRoomIDToWolfPlayerInfoList[wolfRoom];
            for(auto ite=lst.begin();ite!=lst.end();++ite)
            {
                WOLFPLAYERINFO *inner=*ite;
                //在线转发
                SendMsgToId(inner->m_PlayID,(char*)&gameOverrq,sizeof(gameOverrq));
            }
        }
        fal=1;

    }
    return fal;

}
//随机数初始化
void TcpKernel::InitRand()
{
    struct timeval time;
    gettimeofday(&time,NULL);
    srand(time.tv_sec+time.tv_usec);
}

