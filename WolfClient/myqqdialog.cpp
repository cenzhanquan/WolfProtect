#include "myqqdialog.h"
#include "ui_myqqdialog.h"
#include<QCryptographicHash>
#include<QMessageBox>
#include<QLayout>
#include<QVBoxLayout>
#include"useritem.h"
#include "ui_useritem.h"
#include<QScrollArea>
#include "videoitem.h"
#include "ui_videoitem.h"
#include"ui_roomdialog.h"

#define MD5_KEY 1234

//MD5加密  有加盐的操作
static QByteArray GetMD5( QString val)
{
    QCryptographicHash hash(QCryptographicHash::Md5);
    QString key = QString("%1_%2").arg(val).arg( MD5_KEY );

    hash.addData(  key.toLocal8Bit() );
    QByteArray bt =  hash.result();

    return bt.toHex();  // AD1234F....   32位  MD5
}

//构造函数
MyQQDialog::MyQQDialog(QWidget *parent) :
    /*QDialog*/CustomMoveDialog(parent),m_id(0),
    ui(new Ui::MyQQDialog),m_room_id(0),m_wolfroom_id(0),witchSave(1),witchpoison(1)
{
    ui->setupUi(this);

     this->setWindowFlags(Qt::FramelessWindowHint);    //去掉标题栏

    std::string strIP = DEF_SERVER_IP;
    m_serverIP = QString::fromStdString( strIP );
    InitServerIP();

    m_tcpClient = new QMyTcpClient;
    connect(m_tcpClient , SIGNAL(SIG_ReadyData(char*,int)) , this , SLOT( slot_ReadyData(char*,int)) );

    m_tcpClient->setIpAndPort( (char*) m_serverIP.toStdString().c_str() );

    m_loginDlg = new LoginDialog;
    connect(m_loginDlg , SIGNAL(SIG_LoginCommit(QString,QString)) ,
            this , SLOT( slot_LoginCommit(QString,QString))  );
    connect(m_loginDlg , SIGNAL(SIG_RegisterCommit(QString,QString)) ,
            this , SLOT( slot_RegisterCommit(QString,QString))  );


    m_loginDlg->show();
    // this->hide();


    //好友离线提示窗口

   m_friendoffline=new FriendOfflineDialog(this);

   m_IdentityDolg=new PlayerIdentityDialog;//玩家身份牌窗口


    m_widgetList = new IMToolList("我的好友");

    ui->wdg_box->addItem(m_widgetList);



    m_mainMenu = new QMenu(this); // this 传参 指定父控件 , 父控件回收的时候可以回收子控件

    m_mainMenu->addAction("添加好友");
    m_mainMenu->addSeparator();
    m_mainMenu->addAction("创建房间");
    m_mainMenu->addAction("加入房间");

    connect( m_mainMenu , SIGNAL(triggered(QAction*)) , this , SLOT(slot_dealMenu(QAction* )) );

    connect( this , SIGNAL(SIG_addFriend(QString)) ,
             this , SLOT(slot_addFriendRq(QString)) );

    m_roomdlg=new RoomDialog;
    connect(m_roomdlg,SIGNAL(SIG_quitRoom(int)),SLOT(slot_leaveRoom(int)));

//    m_pVideoRead=new Video_Read;

    m_pVideoRead = new Video_Read;

    //打开视频设备
    connect( m_roomdlg , SIGNAL(SIG_openVideoDev())
             ,m_pVideoRead , SLOT( slot_openVideo())  );


    //关闭视频设备
    connect( m_roomdlg , SIGNAL(SIG_closeVideoDev())
             ,m_pVideoRead , SLOT( slot_closeVideo()) );


    //发送视频画面
    connect( m_pVideoRead , SIGNAL( SIG_sendVideoFrame(QImage&)),
             this , SLOT( slot_sendVideoFrame(QImage&))   );

    //处理美颜中的兔子 耳朵等人脸识别装饰
    connect( m_roomdlg , SIGNAL(SIG_setMoji(int))
             ,m_pVideoRead , SLOT(slot_setMoji(int)) );

    m_pAudioRead=new Audio_Read;  //声音采集

    //声音采集完  抛出 然后与槽函数绑定
    connect(m_pAudioRead,SIGNAL(sig_net_tx_frame(QByteArray)),this,SLOT(slot_sendAudioFrame(QByteArray)));


    //打开音频设备

    connect(m_roomdlg,SIGNAL(SIG_openAudioDev()),m_pAudioRead,SLOT(ResumeAudio()));

    //关闭音频设备
    connect(m_roomdlg,SIGNAL(SIG_closeAudioDev()),m_pAudioRead,SLOT(PauseAudio()));

//=========================================================================================================================
    //创建狼人杀游戏
    m_wolfRoom=new WerewolfDialog;

    //声音采集完  抛出 然后与槽函数绑定
    connect(m_pAudioRead,SIGNAL(sig_net_tx_frame(QByteArray)),this,SLOT(slot_sendAudioFrameWolf(QByteArray)));

    //打开音频设备

    connect(m_wolfRoom,SIGNAL(SIG_PLAYEROPENAUDIO()),m_pAudioRead,SLOT(ResumeAudio()));

    //关闭音频设备
    connect(m_wolfRoom,SIGNAL(SIG_PLAYERCLOSEAUDIO()),m_pAudioRead,SLOT(PauseAudio()));

    //处理创建狼人房间的请求
    connect(this,SIGNAL(SIG_CREATEWOLFROOM()),this,SLOT(slot_createwolfroomrq()));

    connect(this,SIGNAL(SIG_GETPLAYERIMAGE(int)),m_wolfRoom,SLOT(solt_setplayerImage(int)));

    //给服务器发去此时狼人杀房间内 入座人的信息  当点入座的时候  发送给服务器  服务器进行处理
    connect(m_wolfRoom,SIGNAL(SIG_PLAYERINFO(int,int,int,int)),this,SLOT(slot_playerSeatInfo(int,int,int,int)));

    //离开房间
    connect(m_wolfRoom,SIGNAL(SIG_LEAVEWOLFROMM(int)),this,SLOT(slot_leaveWolfRoomRq(int)));

    //点击准备
    connect(m_wolfRoom,SIGNAL(SIG_PREPARE(int,int,int)),this,SLOT(slot_prepare(int,int,int)));

    connect(m_wolfRoom,SIGNAL(SIG_SendChatMsgWolf(int,int,QString)),this,SLOT(slot_SendChatMsgWolf(int,int,QString)));

    //当时间到的时候 进行投票然后 给服务器发送讨论结束 进入晚上
    connect(m_wolfRoom,SIGNAL(SIG_DicussionTimeOver()),this,SLOT(slot_DicussionTimeOver()));
    //天黑时间到
    connect(m_wolfRoom,SIGNAL(SIG_GetDarkOver()),this,SLOT(slot_GetDarkOver()));

    //遗言时间到
    connect(m_wolfRoom,SIGNAL(SIG_DeathTimeOver()),this,SLOT(slot_DeathTimeOver()));

    //断线重连
    connect(m_tcpClient,SIGNAL(SIG_disConnect()),this,SLOT(slot_disconnect()));

}

MyQQDialog::~MyQQDialog()
{
    delete ui;

    if( m_tcpClient )
    {
        delete m_tcpClient; m_tcpClient = NULL;
    }
    if(m_loginDlg )
    {
        delete m_loginDlg; m_loginDlg = NULL;
    }

}

//回收资源
void MyQQDialog::slot_Delete()
{
    if(m_pVideoRead)
    {
        m_pVideoRead->slot_closeVideo();
        delete m_pVideoRead;
        m_pVideoRead=NULL;
    }
    if( m_tcpClient )
    {
        delete m_tcpClient; m_tcpClient = NULL;
    }
    if(m_loginDlg )
    {
        delete m_loginDlg; m_loginDlg = NULL;
    }
    for( auto ite = m_mapIDToChatdlg.begin() ;ite !=  m_mapIDToChatdlg.end() ;++ite )
    {
        delete *ite;
        *ite = NULL;
    }
    m_mapIDToChatdlg.clear();

    if(m_pAudioRead)
    {
        m_pAudioRead->PauseAudio();
        delete m_pAudioRead;
        m_pAudioRead=NULL;
    }

    if(m_wolfRoom)
    {
        delete m_wolfRoom;
        m_wolfRoom=NULL;
    }

    //回收所有的音频播放对象
    for( auto ite = m_mapIDToAudioWriteWolf.begin() ;ite !=  m_mapIDToAudioWriteWolf.end() ;++ite )
    {
        delete *ite;
        *ite = NULL;
    }
    m_mapIDToAudioWriteWolf.clear();


}

void MyQQDialog::on_pb_test_clicked()
{
    STRU_LOGIN_RQ rq;
    strcpy(rq.m_szUser , "111");
    strcpy(rq.m_szPassword , "111");
    m_tcpClient ->SendData( ( char*)&rq , sizeof(rq));
}

void MyQQDialog::slot_ReadyData(char *buf, int nlen)
{
    int type = *(int*) buf;
    switch(type)
    {
    case DEF_PACK_LOGIN_RS:
        qDebug()<<  "DEF_PACK_LOGIN_RS";
        slot_LoginRs( buf,   nlen);
        break;
    case DEF_PACK_REGISTER_RS:
        qDebug()<<  "DEF_PACK_REGISTER_RS";
        slot_RegisterRs( buf,   nlen);
        break;
    case DEF_PACK_FORCE_OFFLINE:
        slot_ForceOffline(buf, nlen);
        break;
    case DEF_PACK_ADD_FRIEND_RQ:
        qDebug()<<  "DEF_PACK_ADD_FRIEND_RQ";
        slot_dealAddFriendRq(buf, nlen);
        break;
    case DEF_PACK_ADD_FRIEND_RS:
        qDebug()<<  "DEF_PACK_ADD_FRIEND_RS";
        slot_dealAddFriendRs(buf, nlen);
        break;
    case DEF_PACK_OFFLINRE_RS:                        //处理离线请求
        qDebug()<<  "DEF_PACK_OFFLINRE_RS";
        slot_FriendOfflineRS(buf, nlen);
        break;
    case DEF_PACK_FRIEND_INFO:
        qDebug()<<  "DEF_PACK_FRIEND_INFO";
        slot_FriendInfo(buf, nlen);
        break;
    case DEF_PACK_CHAT_RQ:
        qDebug()<<  "DEF_PACK_CHAT_RQ";
        slot_ChatRq(buf, nlen);
        break;
    case DEF_PACK_CHAT_RS:
        qDebug()<<  "DEF_PACK_CHAT_RS";
        slot_ChatRs(buf,nlen);
        break;
    case DEF_PACK_CREATEROOM_RS:
        qDebug()<<  "DEF_PACK_CREATEROOM_RS";
        slot_CreateRoomRs(buf,nlen);
        break;
    case DEF_PACK_JOINROOM_RS:
        qDebug()<<  "DEF_PACK_JOINROOM_RS";
        slot_JoinRoomRs(buf,nlen);
        break;
    case DEF_PACK_ROOM_MEMBER:
        qDebug()<<  "DEF_PACK_ROOM_MEMBER";
        slot_RoomMember(buf,nlen);
        break;
    case DEF_PACK_LEAVEROOM_RS:
        qDebug()<<  "DEF_PACK_LEAVEROOM_RS";
        slot_LeaveRoomRs(buf,nlen);
        break;
    case DEF_PACK_VIDEO_FRAME:
        qDebug()<<  "DEF_PACK_VIDEO_FRAME";
        slot_VideoFrame(buf,nlen);
        break;
    case DEF_PACK_AUDIO_FRAME:
        qDebug()<<  "DEF_PACK_AUDIO_FRAME";
        slot_AudioFrame(buf,nlen);
        break;
    case DEF_PACK_CREATEWOLFROOM_RS:
        qDebug()<<  "DEF_PACK_CREATEWOLFROOM_RS";
        slot_CreateWolfRoomRs(buf,nlen);
        break;
    case DEF_PACK_JOINWOLFROOMRS:
        qDebug()<<  "DEF_PACK_JOINWOLFROOMRS";
        slot_JoinWolfRoomRs(buf,nlen);
        break;
    case DEF_PACK_WOLFROOM_PLAYER_INFO:
        qDebug()<<  "DEF_PACK_WOLFROOM_PLAYER_INFO";
        slot_WolfRoomMember(buf,nlen);
        break;
    case DFE_PACK_LEAVEWOLFROOM_RS:
        qDebug()<<  "DFE_PACK_LEAVEWOLFROOM_RS";
        slot_leaveWolfRoomRs(buf,nlen);
        break;
    case DFE_PACK_PREPARE_RQ:
        qDebug()<<  "DFE_PACK_PREPARE_RQ";
        slot_PrapreRs(buf,nlen);
        break;
    case DEF_PACK_PREPARE_INFO:
        qDebug()<<  "DEF_PACK_PREPARE_INFO";
        slot_PrapreInfo(buf,nlen);
        break;
    case DEF_WOLFROOM_CHAT_RQ:
        qDebug()<<  "DEF_WOLFROOM_CHAT_RQ";
        slot_wolfRoomChatQq(buf,nlen);
        break;
    case DEF_PACK_AUDIO_FRAME_WOLF:
        qDebug()<<  "DEF_PACK_AUDIO_FRAME_WOLF";
        slot_WolfAudioFrameQq(buf,nlen);
        break;
    case DEF_STARTGAME_INFO:
        qDebug()<<  "DEF_STARTGAME_INFO";
        slot_StartGameQq(buf,nlen);
        break;
    case DEF_CIVILIAN_RQ:
        qDebug()<<  "DEF_CIVILIAN_RQ";
        slot_CIVILIANQq(buf,nlen);
        break;
    case DEF_WEREWOLF_RQ:
        qDebug()<<  "DEF_WEREWOLF_RQ";
        slot_WEREWOLFQq(buf,nlen);
        break;
    case DEF_WITCH_RQ:
        qDebug()<<  "DEF_WITCH_RQ";
        slot_WITCHQq(buf,nlen);
        break;
    case DEF_SEER_RQ:
        qDebug()<<  "DEF_SEER_RQ";
        slot_SEERQq(buf,nlen);
        break;
    case DEF_CHECK_INFO:
        qDebug()<<  "DEF_CHECK_INFO";
        slot_CheckInfo(buf,nlen);
        break;
    case DEF_HUNTER_RQ:
        qDebug()<<  "DEF_HUNTER_RQ";
        slot_HunterRq(buf,nlen);
        break;
    case DEF_DayBreaks:
        qDebug()<<  "DEF_DayBreaks";
        slot_DayBreaksRq(buf,nlen);
        break;
    case DEF_DeathPlayer:
        qDebug()<<  "DEF_DeathPlayer";
        slot_DeathPlayerRq(buf,nlen);
        break;
    case DEF_Vote_RS:
        qDebug()<<  "DEF_Vote_RS";
        slot_VoteRS(buf,nlen);
        break;
    case DEF_WolfDecide:
        qDebug()<<  "DEF_WolfDecide";
        slot_WolfDecideRq(buf,nlen);
        break;
    case DEF_ChangeDady:
        qDebug()<<  "DEF_ChangeDady";
        slot_ChangeDadyRq(buf,nlen);
        break;
    case DEF_GameOver:
        qDebug()<<  "DEF_GameOver";
        slot_GameOverRq(buf,nlen);
        break;
    default:break;

    }
    delete [] buf;
}

//提交登录
void MyQQDialog::slot_LoginCommit(QString name, QString password)
{
    STRU_LOGIN_RQ rq;
    //Unicode 中文兼容
    std::string strName = name.toStdString();
    const char* bufName = strName.c_str();
    strcpy_s( rq.m_szUser , MAX_SIZE , bufName );

    QByteArray btPassord = GetMD5 ( password );
    memcpy( rq.m_szPassword , btPassord.data() , btPassord.size() );

    m_UserName = name;
    m_tcpClient->SendData( (char*)&rq , sizeof(rq));
}

//提交注册
void MyQQDialog::slot_RegisterCommit(QString name, QString password)
{
    STRU_REGISTER_RQ rq;
    //Unicode 中文兼容
    std::string strName = name.toStdString();
    const char* bufName = strName.c_str();
    strcpy_s( rq.m_szUser , MAX_SIZE , bufName );


    //MD5进行加密
    QByteArray btPassord = GetMD5 ( password );


    memcpy( rq.m_szPassword , btPassord.data() , btPassord.size() );

    qDebug()<< rq.m_szPassword;
    m_tcpClient->SendData( (char*)&rq , sizeof(rq));
}

//注册回复
void MyQQDialog::slot_RegisterRs(char *buf, int nlen)
{
    STRU_REGISTER_RS * rs = (STRU_REGISTER_RS *)buf;
    switch( rs->m_lResult )
    {
    case userid_is_exist:
        QMessageBox::about( m_loginDlg , "提示" , "注册失败, 用户已存在");
        break;
    case register_sucess:
        QMessageBox::about( m_loginDlg , "提示" , "注册成功");
        break;
    default:break;
    }
}

//登录回复
void MyQQDialog::slot_LoginRs(char *buf, int nlen)
{
    STRU_LOGIN_RS * rs = (STRU_LOGIN_RS *)buf;
    switch( rs->m_lResult )
    {
    case userid_no_exist:
        QMessageBox::about( m_loginDlg , "提示" , "登录失败, 用户不存在");
        break;
    case password_error:
        QMessageBox::about( m_loginDlg , "提示" , "登录失败, 密码错误");
        break;
    case login_sucess:
        // QMessageBox::about( m_loginDlg , "提示" , "登录成功");
        // id 赋值
        m_id = rs->m_UserID;
        // ui 跳转
        m_loginDlg->hide();
        this ->show();
        break;
    default:break;
    }
}

//强制下线
void MyQQDialog::slot_ForceOffline(char *buf, int nlen)
{
    STRU_FORCE_OFFLINE * rs = (STRU_FORCE_OFFLINE *)buf;
    if(rs->m_UserID == m_id )
    {
        QMessageBox::about( this, "提示","异地登录, 强制下线");

        //退出程序 -- todo
        this->close();
        //exit(0);
    }
}
#include<QInputDialog>
//处理菜单
void MyQQDialog:: slot_dealMenu(QAction *action)
{
    if( action->text() == "添加好友")
    {
        qDebug()<< "添加好友";
        QString strName = QInputDialog::getText( this , "添加好友" , "输入好友名字");
        QRegExp reg("[a-zA-Z0-9]{1,10}");
        bool res = reg.exactMatch( strName );
        if( res )
        {
            //发送添加好友信号
            Q_EMIT SIG_addFriend(strName);
        }else
        {
            QMessageBox::about(this, "提示" , "用户名非法\n输入10位以内的数字或字母");
        }
    }else if( action->text() == "创建房间" )
    {
        qDebug()<< "创建房间";
        if(m_room_id!=0)
        {
            QMessageBox::about(this,"提示","已经在房间里了");
            return ;
        }
        slot_createRoom();
    }else if( action->text() == "加入房间" )
    {
        qDebug()<< "加入房间";
        if(m_room_id!=0)
        {
            QMessageBox::about(this,"提示","已经在房间里了");
            return ;
        }
        QString strRoom = QInputDialog::getText( this , "加入房间" , "请输入房间号");
        QRegExp reg("[0-9]{1,10}");
        bool res = reg.exactMatch( strRoom );
        if( res )
        {
            //加入房间  把房间号传入
            slot_joinRoom(strRoom);

        }else
        {
            QMessageBox::about(this, "提示" , "房间号非法\n输入8位以内的数字");
        }
    }
}

//点击菜单
void MyQQDialog::on_pb_menu_clicked()
{
    if( m_mainMenu )
    {
        QPoint p = QCursor::pos() ;
        QSize size = m_mainMenu->sizeHint();  //最终的大小 prefered size
        int  y = p.y () - size.height();
        m_mainMenu->exec( QPoint( p.x() , y ) );
    }
}

//发送好友请求
void MyQQDialog::slot_addFriendRq(QString name)
{
    if( m_UserName == name )
    {
        QMessageBox::about(this , "提示","不能添加自己");
        return;
    }
    //已经是好友不可以
    for( auto ite = m_mapIDToUserItem.begin() ; ite != m_mapIDToUserItem.end() ; ++ite)
    {
        //todo
        UserItem *item = *ite;
        if( item ->m_name == name )
        {
            QMessageBox::about(this , "提示","已经是好友,不能添加");
            return;
        }
    }

    STRU_ADD_FRIEND_RQ rq;
    std::string  strAddName = name.toStdString();
    strcpy_s( rq.m_szAddFriendName , MAX_SIZE , strAddName.c_str() );

    rq.m_userID = m_id;
    std::string  strUserName =  m_UserName.toStdString();
    strcpy_s( rq.m_szUserName , MAX_SIZE, strUserName.c_str() );

    m_tcpClient->SendData( (char*)&rq , sizeof(rq));
}

//处理添加好友请求
void MyQQDialog::slot_dealAddFriendRq(char *buf, int nlen)
{
    STRU_ADD_FRIEND_RQ * rq = (STRU_ADD_FRIEND_RQ *)buf;
    STRU_ADD_FRIEND_RS rs;
    strcpy_s( rs.szAddFriendName , MAX_SIZE , rq->m_szAddFriendName );
    rs.m_friendID = m_id;
    rs.m_userID = rq->m_userID ;

    if( QMessageBox::question( this , "好友请求" , QString( "用户[%1] 请求添加你为好友").arg(rq->m_szUserName) )
            == QMessageBox::Yes )
    {
        rs.m_result = add_success;
    }else
    {
        rs.m_result = user_refused;
    }
    m_tcpClient -> SendData( (char*)&rs , sizeof(rs));

}
////添加好友结果
//#define no_this_user    0
//#define user_refused    1
//#define user_is_offline 2
//#define add_success     3
//处理添加好友回复
void MyQQDialog::slot_dealAddFriendRs(char *buf, int nlen)
{
    STRU_ADD_FRIEND_RS* rs = (STRU_ADD_FRIEND_RS *)buf;
    switch( rs->m_result )
    {
    case no_this_user:
        QMessageBox::about(this , "提示","没有此用户");
        break;
    case user_refused:
        QMessageBox::about(this , "提示","用户拒绝添加");
        break;
    case user_is_offline:
        QMessageBox::about(this , "提示","用户离线");
        break;
    case add_success:
        QMessageBox::about(this , "提示", QString("成功添加[%1]为好友").arg(rs->szAddFriendName));
        break;
    }
}

//好友列表
void MyQQDialog::slot_FriendInfo(char *buf, int nlen)
{
    STRU_FRIEND_INFO * friendrq = (STRU_FRIEND_INFO *)buf;

    if( friendrq->m_userID == m_id )
    {
        ui->pb_icon->setIcon( QIcon( QString(":/tx/%1.png").arg(friendrq->m_iconID)) );

        Q_EMIT SIG_GETPLAYERIMAGE(friendrq->m_iconID);  //抛出玩家头像的信号  ----狼人杀


        ui->lb_name->setText( friendrq->m_szName );

        return;
    }
    if( m_mapIDToUserItem .find(friendrq->m_userID) == m_mapIDToUserItem.end() )
    {//没找到
        UserItem * item = new UserItem;
        item->setInfo( friendrq->m_userID , friendrq->m_state ,friendrq->m_szName ,
                       QString(":/tx/%1.png").arg(friendrq->m_iconID) );

        m_widgetList->addItem(item);
        connect( item , SIGNAL(SIG_ItemClicked()) ,
                 this, SLOT( slot_UserItemClicked()) );

        //处理当列表中的好友离线的时候 弹出提示
        connect(item,SIGNAL(SIG_Offline(QString)),this,SLOT(slot_friendOfflineMessage(QString)));

        m_mapIDToUserItem[ friendrq->m_userID ] = item;


        //创建聊天窗口
        chatDialog*chat=new chatDialog;
        chat->setInfo(friendrq->m_userID,friendrq->m_szName);

        connect(chat,SIGNAL(SIG_SendChatMsg(int,QString)),this,SLOT(slot_SendChatRq(int,QString)));

        //添加映射关系方便管理
        m_mapIDToChatdlg[friendrq->m_userID]=chat;


    }else
    {//找到
        UserItem * item = m_mapIDToUserItem[ friendrq->m_userID ];

        item->setInfo( friendrq->m_userID , friendrq->m_state ,friendrq->m_szName ,
                       QString(":/tx/%1.png").arg(friendrq->m_iconID) );
    }
}
//处理好友离线请求
void MyQQDialog::slot_FriendOfflineRS(char *buf, int nlen)
{
    STRU_OFFLINE_RS*rs=(STRU_OFFLINE_RS*)buf;

    if(m_mapIDToUserItem.size()>0)
    {
        if(m_mapIDToUserItem.find(rs->m_userID)!=m_mapIDToUserItem.end())
        {
            UserItem*OfflineFriend=m_mapIDToUserItem[rs->m_userID];


            OfflineFriend->setOfflineIcon(1);   //把相应的用户头像设置为灰色
        }
    }
}

//双击用户响应
void MyQQDialog::slot_UserItemClicked()
{
    qDebug()<<__func__;

    //取得响应的是哪一个
    UserItem*item=(UserItem*) QObject::sender();
    //聊天窗口显示

    if(m_mapIDToChatdlg.find(item->m_id)!=m_mapIDToChatdlg.end())
    {
        chatDialog*chat=m_mapIDToChatdlg[item->m_id];
        chat->hide();
        chat->show();
    }
}


#include<QSettings>
#include<QCoreApplication>
#include<QFileInfo>
// 加载配置文件  QSettings

void MyQQDialog::InitServerIP()
{
    ///////////////////
    //[net]
    //ip="192.168.5.31"
    ///////////////////
    //获取路径 exe路径 E:\2020fall\0401\build-MyQQ-Desktop_Qt_5_6_2_MinGW_32bit-Release\release   拼接成配置文件路径
    QString path = QCoreApplication::applicationDirPath() + "/config.ini";
    QFileInfo info(path);
    if( info.exists() )
    {// 如果存在 读取设置 ip

        QSettings setting( path , QSettings::IniFormat , NULL ); //相当于打开配置文件 存在读取不存在创建
        setting.beginGroup("net");
        QVariant var =  setting.value("ip");
        QString ip = var.toString();
        if( !ip.isEmpty() )  m_serverIP = ip;
        setting.endGroup();

        qDebug()<< m_serverIP;
    }else
    {
        // 如果不存在创建 并写默认
        QSettings setting( path , QSettings::IniFormat , NULL ); //相当于打开配置文件 存在读取不存在创建
        setting.beginGroup("net");
        setting.setValue("ip", m_serverIP);  //将默认写入文件
        setting.endGroup();
    }
}


//用户退出
void MyQQDialog::on_pb_close_clicked()
{
    if( QMessageBox::question( this, "提示", "是否退出程序") == QMessageBox::Yes)
    {
        //发送离线请求
        STRU_OFFLINE_RQ rq;
        rq.m_userID = m_id;
        m_tcpClient->SendData( (char*)&rq , sizeof(rq) );
        this->close(); // 进入关闭事件
       // m_wolfRoom->close();


    }
}

void MyQQDialog::closeEvent(QCloseEvent *event)
{
    //回收资源
    this->slot_Delete();

    this->accept();

}
//发送聊天信息给服务器
void MyQQDialog::slot_SendChatRq(int id, QString content)
{
    STRU_CHAT_RQ rq;
    rq.m_userID=m_id;
    rq.m_friendID=id;
    std::string strContent=content.toStdString();
    strcpy_s(rq.m_ChatContent,MAX_CONTENT_LEN,strContent.c_str());

    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}
//创建房间
void MyQQDialog::slot_createRoom()
{
    STRU_CREATEROOM_RQ rq;
    rq.m_UserID=m_id;

    m_tcpClient->SendData((char*)&rq,sizeof(rq));

}
//加入房间
void MyQQDialog::slot_joinRoom(QString roomid)
{
    int id=roomid.toInt();

    STRU_JOINROOM_RQ rq;

    rq.m_RoomID=id;
    rq.m_UserID=m_id;

    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}
//离开房间
void MyQQDialog::slot_leaveRoom(int roomID)
{


    STRU_LEAVEROOM_RQ rq;
    rq.m_nUserId=m_id;
    rq.m_RoomId=m_room_id;

    m_tcpClient->SendData((char*)&rq,sizeof(rq));


    //回收显示
    for(auto ite=m_mapIDToVideoItemList.begin();ite!=m_mapIDToVideoItemList.end();++ite)
    {
        VideoItem*item=*ite;
        m_roomdlg->slot_removeVideoItem(item);     //删除右侧小窗口视频框

        delete item;
        item=NULL;
    }

    m_mapIDToVideoItemList.clear();

    //关闭视频  音频
    //关闭 音频收集对象
    if(m_pAudioRead)
    {
        m_pAudioRead->PauseAudio();
    }

    //回收所有声音播放的item
    for(auto ite=m_mapIDToAudioWrite.begin();ite!=m_mapIDToAudioWrite.end();++ite)
    {
        Audio_Write*item=*ite;

        delete item;
        item=NULL;
    }

    m_mapIDToAudioWrite.clear();


     m_room_id=0;

}
//处理鼠标点击右侧小窗口 事件  点击然后实现在左边放大
void MyQQDialog::slot_videoItemClicked(int id)
{
    //这样写可以拿到点击这个小窗口 的地址  找到点击了那个小窗口
    VideoItem*item=(VideoItem*)QObject::sender();

    m_roomdlg->slot_setBigImageID(id,item->m_name);


}
#include<QBuffer>
//发送视频帧(压缩视频)
void MyQQDialog::slot_sendVideoFrame(QImage &img)
{
    //刷新ui
    slot_refreshImage(m_id,img);

    //将image图片转换成  缓冲区
    QByteArray ba;
    QBuffer qbuf(&ba);  //QBuffer 与 QByteArray 字节数据建立联系

    //把图片内容保存在缓冲区中
    img.save(&qbuf,"JPEG");
    //发送给服务器


    ///视频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// QByteArray videoFrame;
    char *buf=new char[12+ba.size()];
    char *temp=buf;
    int type=DEF_PACK_VIDEO_FRAME;
    int userId=m_id;
    int roomId=m_room_id;

    *(int*)temp=type;
    temp+=sizeof(int);  //*(int*)  按照四个字节去写
    *(int*)temp=userId;
    temp+=sizeof(int);  //*(int*)  按照四个字节去写
    *(int*)temp=roomId;
    temp+=sizeof(int);  //*(int*)  按照四个字节去写


    memcpy(temp,ba.data(),ba.size());

    m_tcpClient->SendData(buf,(12+ba.size()));


    delete []buf;

}
//音频处理并发送
void MyQQDialog::slot_sendAudioFrame(QByteArray byte)
{

    ///音频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// QByteArray audioFrame;

    int type=DEF_PACK_AUDIO_FRAME;
    int userId=m_id;
    int roomId=m_room_id;

    char *buf=new char[12+byte.size()];
    char *tmp=buf;
    *(int*)tmp=type;
    tmp+=sizeof(int);
    *(int*)tmp=userId;
    tmp+=sizeof(int);
    *(int*)tmp=roomId;
    tmp+=sizeof(int);

    memcpy(buf,byte.data(),12+byte.size());

    m_tcpClient->SendData(buf,12+byte.size());


    delete []buf;

}
//刷新界面图片显示
void MyQQDialog::slot_refreshImage(int id,QImage &img)
{
    //更新大图
    if(m_roomdlg->getUi()->wdg_video->m_id==id)
    {
        m_roomdlg->getUi()->wdg_video->slot_setOneImage(img);
    }
    //更新小图
    if(m_mapIDToVideoItemList.find(id)!=m_mapIDToVideoItemList.end())
    {
        VideoItem*item=m_mapIDToVideoItemList[id];
        item->slot_setOneImage(img);
    }
}
//处理服务器发来的视频帧(解析视频帧)(解码视屏)
void MyQQDialog::slot_VideoFrame(char *buf, int nlen)
{

    ///视频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// QByteArray videoFrame;
    char *tmp=buf;
    int type=*(int*)tmp;  //每次读四位
    tmp+=sizeof(int);

    int userId=*(int*)tmp;
    tmp+=sizeof(int);

    int roomId=*(int*)tmp;
    tmp+=sizeof(int);

    QByteArray ba(tmp,nlen-12);   //减12的目的就是前面拿了三个int*类型的数据 一次拿四个
    QImage img;

    //把缓冲区的内容加载到图片中
    img.loadFromData(ba);

    this->slot_refreshImage(userId,img);

}
//解析服务器转发来的音频  并播放
void MyQQDialog::slot_AudioFrame(char *buf, int nlen)
{
    ///音频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// QByteArray audioFrame;

    char *tmp=buf;
    int type=*(int*)tmp;
    tmp+=sizeof(int);
    int userId=*(int*)tmp;
    tmp+=sizeof(int);
    int roomId=*(int*)tmp;
    tmp+=sizeof(int);


    if(m_mapIDToAudioWrite.find(userId)!=m_mapIDToAudioWrite.end())
    {
        QByteArray byte(tmp,nlen-12);
        Audio_Write *item=m_mapIDToAudioWrite[userId];
        item->slot_net_rx(byte);
    }

}
//处理好友离线请求  离线时弹出对应的谁离线的对话框
void MyQQDialog::slot_friendOfflineMessage(QString name)
{

    m_friendoffline->SetInfo(QString("好友%1下线").arg(name));

    m_friendoffline->show();
}
//处理服务器发来的聊天请求
void MyQQDialog::slot_ChatRq(char *buf, int nlen)
{
    STRU_CHAT_RQ *rq=(STRU_CHAT_RQ*)buf;
    //对方用户  rq.m_userID;
    if(m_mapIDToChatdlg.find(rq->m_userID)!=m_mapIDToChatdlg.end())
    {
        chatDialog*chat=m_mapIDToChatdlg[rq->m_userID];
        std::string ChatContent=rq->m_ChatContent;

        chat->hide();
        chat->show();
        chat->slot_recvChatMsg(QString::fromStdString(ChatContent));
    }
}

//处理服务器发来的聊天信息回复包   主要处理好友不在线的状态
void MyQQDialog::slot_ChatRs(char *buf, int nlen)
{
    STRU_CHAT_RS *rs = (STRU_CHAT_RS *)buf;

    // 对方用户 rs->m_friendID
    if( rs->m_result == user_is_offline )
    {
        if( m_mapIDToChatdlg.find( rs->m_friendID ) != m_mapIDToChatdlg.end() )
        {
            chatDialog*chat =  m_mapIDToChatdlg[rs->m_friendID];
            chat->slot_showOffline();
        }
    }
}
//处理创建房间回复
void MyQQDialog::slot_CreateRoomRs(char *buf, int nlen)
{
    STRU_CREATEROOM_RS *rs=(STRU_CREATEROOM_RS*)buf;
    if(rs->m_lResult)
    {

        //成员设置
        m_room_id=rs->m_RoomId;
        //UI
        m_roomdlg->slot_setInfo(rs->m_RoomId);

        m_roomdlg->show();

        //添加对自己Video的显示
        if(m_mapIDToVideoItemList.find(m_id)==m_mapIDToVideoItemList.end())
        {
            VideoItem*item=new VideoItem;
            item->setInfo(m_id,m_UserName);

            //绑定每个右边的小窗口video 使点击时实现右边放大显示
            connect(item,SIGNAL(SIG_itemClicked(int)),
                    this,SLOT(slot_videoItemClicked(int)));
            m_roomdlg->slot_addVideoItem(item);
            m_mapIDToVideoItemList[m_id]=item;

        }

        //音频和视频
    }
}
//处理加入房间回复
void MyQQDialog::slot_JoinRoomRs(char *buf, int nlen)
{
    STRU_JOINROOM_RS*rs=(STRU_JOINROOM_RS*)buf;

    if(rs->m_lResult)
    {
        m_room_id=rs->m_RoomID;

        m_roomdlg->slot_setInfo(rs->m_RoomID);

        m_roomdlg->show();

        //添加对自己Video的显示

        if(m_mapIDToVideoItemList.find(m_id)==m_mapIDToVideoItemList.end())
        {
            VideoItem*item=new VideoItem;
            item->setInfo(m_id,m_UserName);

            //绑定每个右边的小窗口video 使点击时实现右边放大显示
            connect(item,SIGNAL(SIG_itemClicked(int)),
                    this,SLOT(slot_videoItemClicked(int)));
            m_roomdlg->slot_addVideoItem(item);
            m_mapIDToVideoItemList[m_id]=item;

        }

        //音频和视频

    }
    else
    {
        QMessageBox::about(this,"提示","加入房间失败");
    }
}
//处理服务器发来的房间成员信息  好友列表
void MyQQDialog::slot_RoomMember(char *buf, int nlen)
{
    //拆包
    STRU_ROOM_MEMBER_RQ *rq=(STRU_ROOM_MEMBER_RQ*)buf;


    if(m_mapIDToVideoItemList.find(rq->m_UserID)==m_mapIDToVideoItemList.end())
    {
        VideoItem*item=new VideoItem;
        item->setInfo(rq->m_UserID,rq->m_szUser);

        //绑定每个右边的小窗口video 使点击时实现右边放大显示
        connect(item,SIGNAL(SIG_itemClicked(int)),
                this,SLOT(slot_videoItemClicked(int)));
        m_roomdlg->slot_addVideoItem(item);
        m_mapIDToVideoItemList[rq->m_UserID]=item;



    }


     //音频

    //把音频绑定到map中  让每个用户拥有一个音频播放对象
    if(m_mapIDToAudioWrite.find(rq->m_UserID)==m_mapIDToAudioWrite.end())
    {
        Audio_Write *item=new Audio_Write;

        m_mapIDToAudioWrite[rq->m_UserID]=item;
    }
}
//处理服务器发来的房间内某人离开
void MyQQDialog::slot_LeaveRoomRs(char *buf, int nlen)
{

    //拆包

    STRU_LEAVEROOM_RS *rs=(STRU_LEAVEROOM_RS*)buf;

    //map中有这个人就删掉  显示也要回收

    auto ite=m_mapIDToVideoItemList.find(rs->m_UserID);

    if(ite!=m_mapIDToVideoItemList.end())
    {
        VideoItem*item=*ite;

        //调用对应类中的  (房间类中的删除函数  删除视频显示模块的部分  即VieoItem 部分)  删除右侧小窗口中的显示
        m_roomdlg->slot_removeVideoItem(item);

        //重绘
        m_roomdlg->repaint();

        m_mapIDToVideoItemList.erase(ite);  //删除映射节点的关系


        //删除里面的内容
        delete item;
        item=NULL;
    }


    //回收这个人的音频
    auto iteAudio=m_mapIDToAudioWrite.find(rs->m_UserID);
    if(iteAudio!=m_mapIDToAudioWrite.end())
    {
        Audio_Write *item=m_mapIDToAudioWrite[rs->m_UserID];
        m_mapIDToAudioWrite.erase(iteAudio);
        delete item;
        item=NULL;
    }
}

//缩小
void MyQQDialog::on_pb_min_clicked()
{
    this->slot_showMin();
}
//============================================狼人杀====================================================
//创建狼人杀房间
void MyQQDialog::on_pb_test3_clicked()
{
    //m_wolfRoom->show();
    Q_EMIT SIG_CREATEWOLFROOM();

}
//加入狼人杀房间
void MyQQDialog::on_pb_test2_clicked()
{
    qDebug()<< "加入房间";
    if(m_wolfroom_id!=0)
    {
        QMessageBox::about(this,"提示","已经在房间里了");
        return ;
    }
    QString strRoom = QInputDialog::getText( this , "加入房间" , "请输入房间号");
    QRegExp reg("[0-9]{1,10}");
    bool res = reg.exactMatch( strRoom );
    if( res )
    {
        //加入房间  把房间号传入
        slot_WolfjoinRoom(strRoom);

    }else
    {
        QMessageBox::about(this, "提示" , "房间号非法\n输入8位以内的数字");
    }
}
#include<QDebug>
//给服务器发送创建狼人杀房间的请求
void MyQQDialog::slot_createwolfroomrq()
{
    qDebug()<<__func__;
    STRU_CREATEWOLFROOM_RQ rq;
    rq.m_UserID=m_id;

    m_wolfRoom->getUi()->pb_landlord->setText(QString("当前房主：我自己"));

    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}
//处理服务器发来的创建游戏房间回复
void MyQQDialog::slot_CreateWolfRoomRs(char *buf, int nlen)
{
    //拆包
    STRU_CREATEWOLFROOM_RS *rs=(STRU_CREATEWOLFROOM_RS*)buf;

    if(rs->m_lResult)
    {

        if(m_mapPlayerIDToPlayerInfo.find(m_id)==m_mapPlayerIDToPlayerInfo.end())
        {
            m_wolfRoom->setInfo(rs->m_RoomId,m_id);
            m_wolfRoom->SetGameDays(0); //创建房间游戏天数默认为0;
            m_wolfRoom->SetIdentity(HOLLOWMAN);   //创建房间初始身份设置为透明人

            WOLFPLAYERINFO*playerInfo=new WOLFPLAYERINFO;
            playerInfo->m_IsHouseOwner=ISHOUSEOWNER;   //设为房间的主人
            playerInfo->m_nType=DEF_PACK_WOLFROOM_PLAYER_INFO;
            playerInfo->m_Playerfd=0;
            playerInfo->m_PlayerIconID=m_wolfRoom->m_playerIconID;
            playerInfo->m_PlayerIdentity=HOLLOWMAN;
            playerInfo->m_PlayerSeat=m_wolfRoom->m_playerSeatID;
            playerInfo->m_PlayID=m_id;
            playerInfo->m_RoomID=m_wolfroom_id;
            std::string  strUserName =  m_UserName.toStdString();
            strcpy_s( playerInfo->szUserName , MAX_SIZE, strUserName.c_str() );

            //记录狼人杀房间内的玩家信息
            m_mapPlayerIDToPlayerInfo[m_id]=playerInfo;


        }
    }

    m_wolfroom_id=rs->m_RoomId;

    m_wolfRoom->show();

}


//当狼人杀房间内的人入座的时候  把入座人的信息发送给服务器  做缓存记录


//PlayerID  玩家的ID
//PlayerIconID 玩家头像的ID
//PlayerSeatID  玩家加入座位的ID
//PlayerWolfRoomID   玩家所在的狼人杀房间号
void MyQQDialog::slot_playerSeatInfo(int PlayerID,int PlayerIconID,int PlayerSeatID,int PlayerWolfRoomID)
{
    //定义协议包  待会发送给服务器  然后服务器用MAP映射进行登记
    WOLFPLAYERINFO rq;

    rq.m_PlayID=PlayerID;

    rq.m_PlayerIconID=PlayerIconID;

    rq.m_PlayerSeat=PlayerSeatID;

    rq.m_RoomID=PlayerWolfRoomID;

    std::string  strUserName =  m_UserName.toStdString();
    strcpy_s( rq.szUserName, MAX_SIZE, strUserName.c_str() );



    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}
//给服务器发送加入狼人杀房间请求
void MyQQDialog::slot_WolfjoinRoom(QString roomid)
{
    int id=roomid.toInt();

    STRU_JOINWOLFROOM_RQ rq;

    rq.m_RoomID=id;
    rq.m_UserID=m_id;

    m_tcpClient->SendData((char*)&rq,sizeof(rq));

}
//处理服务器发来的加入狼人杀房间回复
void MyQQDialog::slot_JoinWolfRoomRs(char *buf, int nlen)
{
    //拆包
    STRU_JOINWOLFROOM_RS*rs=(STRU_JOINWOLFROOM_RS*)buf;

    if(rs->m_lResult)
    {

        if(m_mapPlayerIDToPlayerInfo.find(m_id)==m_mapPlayerIDToPlayerInfo.end())
        {
            m_wolfRoom->setInfo(rs->m_RoomID,m_id);
            m_wolfRoom->SetGameDays(0); //加入房间游戏天数默认为0;
            m_wolfRoom->SetIdentity(HOLLOWMAN);   //加入房间初始身份设置为透明人

            WOLFPLAYERINFO*playerInfo=new WOLFPLAYERINFO;
            playerInfo->m_IsHouseOwner=NOHOUSEOWNER;   //加入房间的人都默认为不是房主
            playerInfo->m_nType=DEF_PACK_WOLFROOM_PLAYER_INFO;
            playerInfo->m_Playerfd=0;
            playerInfo->m_PlayerIconID=m_wolfRoom->m_playerIconID;
            playerInfo->m_PlayerIdentity=HOLLOWMAN;                      //设置身份为透明人的身份
            playerInfo->m_PlayerSeat=m_wolfRoom->m_playerSeatID;
            playerInfo->m_PlayID=m_id;
            playerInfo->m_RoomID=m_wolfroom_id;
            std::string  strUserName =  m_UserName.toStdString();
            strcpy_s( playerInfo->szUserName , MAX_SIZE, strUserName.c_str() );
            //记录狼人杀房间内的玩家信息
            m_mapPlayerIDToPlayerInfo[m_id]=playerInfo;


        }
    }

    m_wolfroom_id=rs->m_RoomID;

    m_wolfRoom->show();

}
//处理服务器发来的房间成员信息
void MyQQDialog::slot_WolfRoomMember(char *buf, int nlen)
{

    //拆包
    WOLFPLAYERINFO *rq=(WOLFPLAYERINFO*)buf;

    //记录身份
    m_mapPlayerSeatIDIdentityID[rq->m_PlayerSeat]=rq->m_PlayerIdentity;

    //拿玩家座位ID和玩家ID进行绑定
    m_mapPlayerSeatIDToPlayerID[rq->m_PlayerSeat]=rq->m_PlayID;

    //当判断到是房主的时候 设置显示房主是谁
    if(rq->m_IsHouseOwner==ISHOUSEOWNER)
    {
        m_wolfRoom->SetLandlord(rq->m_PlayerSeat);
    }



    //当ID为自己的时候不用设置显示  只需要重新添加映射关系就行
    if(rq->m_PlayID!=m_id)
    {
        //房间成员设置显示
        m_wolfRoom->SetRoomMemberInfo(rq->m_PlayID,rq->m_PlayerIconID,rq->m_PlayerSeat);
    }

    //添加新的映射关系  方便管理
    WOLFPLAYERINFO*playerInfo=new WOLFPLAYERINFO;
    playerInfo->m_IsHouseOwner=rq->m_IsHouseOwner;
    playerInfo->m_nType=DEF_PACK_WOLFROOM_PLAYER_INFO;
    playerInfo->m_Playerfd=rq->m_Playerfd;
    playerInfo->m_PlayerIconID=rq->m_PlayerIconID;
    playerInfo->m_PlayerIdentity=rq->m_PlayerIdentity;                      //设置身份为透明人的身份
    playerInfo->m_PlayerSeat=rq->m_PlayerSeat;
    playerInfo->m_PlayID=rq->m_PlayID;
    playerInfo->m_RoomID=rq->m_RoomID;
    strcpy(playerInfo->szUserName,rq->szUserName);


    m_mapPlayerIDToPlayerInfo[rq->m_PlayID]=playerInfo;

    //把音频绑定到map中  让每个用户拥有一个音频播放对象
    if(m_mapIDToAudioWriteWolf.find(rq->m_PlayID)==m_mapIDToAudioWriteWolf.end())
    {
        Audio_Write *item=new Audio_Write;

        m_mapIDToAudioWriteWolf[rq->m_PlayID]=item;
    }
}
//给服务器发送离开狼人房间请求
void MyQQDialog::slot_leaveWolfRoomRq(int roomID)
{
    STRU_LEAVEWOLFROOM_RQ rq;
    rq.m_RoomId=roomID;
    rq.m_nUserId=m_id;

    auto ite=m_mapPlayerIDToPlayerInfo.begin();

    while(ite!=m_mapPlayerIDToPlayerInfo.end())
    {
        WOLFPLAYERINFO*leaver=*ite;
        if(leaver->m_PlayID==m_id)
        {

            //记录离开房间前的身份
            //（有可能告诉开游戏前离开  或者是开游戏后离开 都不一定  所以要记录身份 好等游戏结束的时候显示  在游戏的时候也方便处理）
            m_mapPlayerSeatIDIdentityID[leaver->m_PlayerSeat]=leaver->m_PlayerIdentity;

            delete leaver;
            leaver=NULL;

            m_mapPlayerIDToPlayerInfo.erase(ite);

            break;
        }
        ++ite;

    }
    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}
//离开狼人杀房间回复
void MyQQDialog::slot_leaveWolfRoomRs(char *buf, int nlen)
{
    //拆包
    STRU_LEAVEWOLFROOM_RS*rs=(STRU_LEAVEWOLFROOM_RS*)buf;

    //把离开的好友的座位头像设置为离开状态

    m_wolfRoom->m_mapIDToButton[rs->m_UserID]->setIcon(QIcon(QString(":/images/leave.png")));

    this->repaint();  //重绘

    //回收这个人的音频
    auto iteAudio=m_mapIDToAudioWriteWolf.find(rs->m_UserID);
    if(iteAudio!=m_mapIDToAudioWriteWolf.end())
    {
        Audio_Write *item=m_mapIDToAudioWriteWolf[rs->m_UserID];
        m_mapIDToAudioWriteWolf.erase(iteAudio);
        delete item;
        item=NULL;
    }


}
//向服务器发送准备请求
void MyQQDialog::slot_prepare(int playerID, int playerSeatID, int wolfRoomID)
{
    //写包
    STRU_PREPARE_RQ rq;
    rq.playerID=playerID;
    rq.playerSeat=playerSeatID;
    rq.wolfRoomID=wolfRoomID;


    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}
//处理服务器发来的准备请求
void MyQQDialog::slot_PrapreRs(char *buf, int nlen)
{
    //拆包
    STRU_PREPARE_RQ*rs=(STRU_PREPARE_RQ*)buf;

    m_wolfRoom->prepare[rs->playerSeat]->setText(QString("已准备"));
}
//处理准备玩家的信息
void MyQQDialog::slot_PrapreInfo(char *buf, int nlen)
{
    //拆包
    STRU_praprePlayerID*rq=(STRU_praprePlayerID*)buf;

    m_wolfRoom->prepare[rq->playerSeat]->setText(QString("已准备"));

}
//发送聊天信息给房间内的所有成员
void MyQQDialog::slot_SendChatMsgWolf(int playerID,int playerSeatID,QString content)
{
    //写包
    STRU_WOLFROOM_CHAT_RQ rq;
    rq.m_playerID=playerID;
    rq.m_playerSeatID=playerSeatID;
    rq.m_wolfRoomID=m_wolfroom_id;

    std::string strContent=content.toStdString();
    strcpy_s(rq.m_ChatContent,MAX_CONTENT_LEN,strContent.c_str());

    m_tcpClient->SendData((char*)&rq,sizeof(rq));

}
//处理房间内成员发来的聊天请求
void MyQQDialog::slot_wolfRoomChatQq(char *buf, int nlen)
{
    //拆包
    STRU_WOLFROOM_CHAT_RQ*rs=(STRU_WOLFROOM_CHAT_RQ*)buf;

     std::string ChatContent=rs->m_ChatContent;
     m_wolfRoom->RecvChatMsg(QString::fromStdString(ChatContent),rs->m_playerSeatID);
}
//向狼人杀房间内的成员发送音频
void MyQQDialog::slot_sendAudioFrameWolf(QByteArray byte)
{

    ///音频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// QByteArray audioFrame;

    int type=DEF_PACK_AUDIO_FRAME_WOLF;
    int userId=m_id;
    int roomId=m_wolfroom_id;

    char *buf=new char[12+byte.size()];
    char *tmp=buf;
    *(int*)tmp=type;
    tmp+=sizeof(int);
    *(int*)tmp=userId;
    tmp+=sizeof(int);
    *(int*)tmp=roomId;
    tmp+=sizeof(int);

    memcpy(buf,byte.data(),12+byte.size());

    m_tcpClient->SendData(buf,12+byte.size());


    delete []buf;

}
//处理服务器发来房间内的成员音频  并播放
void MyQQDialog::slot_WolfAudioFrameQq(char *buf, int nlen)
{
    ///音频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// QByteArray audioFrame;

    char *tmp=buf;
    int type=*(int*)tmp;
    tmp+=sizeof(int);
    int userId=*(int*)tmp;
    tmp+=sizeof(int);
    int roomId=*(int*)tmp;
    tmp+=sizeof(int);


    if(m_mapIDToAudioWriteWolf.find(userId)!=m_mapIDToAudioWriteWolf.end())
    {
        QByteArray byte(tmp,nlen-12);
        Audio_Write *item=m_mapIDToAudioWriteWolf[userId];
        item->slot_net_rx(byte);
    }
}
//CIVILIAN=2021,  //平民

//SEER,   //预言家

//HUNTER,  //猎人

//WITCH, //女巫

//WEREWOLF, //狼人

//DEADPERSON, //死人

//HOLLOWMAN, //透明人(指没有分配身份的人)

//处理服务器发来的开始游戏请求
void MyQQDialog::slot_StartGameQq(char *buf, int nlen)
{
    //拆包
    STRU_STARTGAME_INFO *rq=(STRU_STARTGAME_INFO*)buf;

    //拿玩家座位ID 和身份牌进行绑定  用来记录身份
   m_mapPlayerSeatIDIdentityID[rq->m_playerSeat]=rq->m_playerIdentityID;

   //更新房间内玩家的信息
   WOLFPLAYERINFO*info=m_mapPlayerIDToPlayerInfo[rq->m_playerID];
   WOLFPLAYERINFO*playerInfo=new WOLFPLAYERINFO;
   playerInfo->m_IsHouseOwner=info->m_IsHouseOwner;
   playerInfo->m_nType=info->m_nType;
   playerInfo->m_Playerfd=info->m_Playerfd;
   playerInfo->m_PlayerIconID=info->m_PlayerIconID;
   playerInfo->m_PlayerIdentity=rq->m_playerIdentityID;
   playerInfo->m_PlayerSeat=info->m_PlayerSeat;
   playerInfo->m_PlayID=info->m_PlayID;
   playerInfo->m_RoomID=info->m_RoomID;
   strcpy(playerInfo->szUserName,info->szUserName);

   m_mapPlayerIDToPlayerInfo[rq->m_playerID]=playerInfo;


    //设置成员信息
    m_wolfRoom->setInfo(rq->m_wolfRoomID,rq->m_playerID);

    //设置天数
    m_wolfRoom->SetGameDays(rq->m_gamedays);

    //设置玩家身份
    m_wolfRoom->SetIdentity(rq->m_playerIdentityID);

    //m_IdentityDolg->setPlayerIdentity(rq->m_playerIdentityID);

    //m_IdentityDolg->show();

    //发布公告  游戏开始的公告
    m_wolfRoom->RecvAnnunciateMsg(QString("游戏正式开始！！！！！"));

    //设置为天黑的状态
    m_wolfRoom->RecvAnnunciateMsg(QString("天黑请闭眼！！！！"));

    //开启天黑自动定时器  操作时间设置为60秒
    m_wolfRoom->false_DarkOver=1;
    m_wolfRoom->SetTimerStart();
}
//=======================================================================================================================
//服务器发来的平民请求
void MyQQDialog::slot_CIVILIANQq(char *buf, int nlen)
{
    //拆包
    STRU_CIVILIAN_RQ*rq=(STRU_CIVILIAN_RQ*)buf;



    m_wolfRoom->RecvAnnunciateMsg(QString("狼人请选择要杀的人！！！"));

    m_wolfRoom->RecvAnnunciateMsg(QString("预言家请选择要查验的人！！！"));

    m_wolfRoom->RecvAnnunciateMsg(QString("女巫请选择要救的人，或者选择是否选择使用毒药！！！"));

    m_wolfRoom->RecvAnnunciateMsg(QString("猎人选择是否要开枪带走人！！！！"));
}
//服务器发来的狼人请求
void MyQQDialog::slot_WEREWOLFQq(char *buf, int nlen)
{
    //拆包
    STRU_WEREWOLF_RQ *rq=(STRU_WEREWOLF_RQ*)buf;

    m_wolfRoom->RecvAnnunciateMsg(QString("狼人请选择要杀的人！！！"));

    //狼人操作写出要杀的玩家
    QString strRoom = QInputDialog::getText( this , "狼人请操作" , "请输入要杀死的玩家 （例如玩家一号为：1）！！不杀人请输入0！！");

    int KillSeatID=strRoom.toInt();

    int KillplayerID;

    //没有杀人的情况
    if(KillSeatID==0)
    {
        KillplayerID=0;
    }
    else
    {//杀人的情况

        //查找映射表  得到玩家ID
        KillplayerID=m_mapPlayerSeatIDToPlayerID[KillSeatID-1];
    }
    //写回复包
    STRU_WEREWOLF_RS rs;

    rs.m_playerID=m_id;
    rs.wolfRoom=m_wolfroom_id;
    rs.m_KillPlayerID=KillplayerID;


    m_tcpClient->SendData((char*)&rs,sizeof(rs));
}
//服务器发来的请求 女巫的
void MyQQDialog::slot_WITCHQq(char *buf, int nlen)
{

    //拆包
    STRU_WITCH_RQ *rq=(STRU_WITCH_RQ*)buf;
    //写包
    STRU_WITCH_RS rs;

     m_wolfRoom->RecvAnnunciateMsg(QString("女巫请操作！！！"));
     QString KillPlayerName;

     //狼人杀人的情况
     if(rq->KillPlayerID!=0)
     {

         //当有解药在手时就能救人
         if(witchSave!=0)
         {

             int KillPlayerSeatID;

             //找到被杀死的玩家的相关信息
             if(m_mapPlayerIDToPlayerInfo.find(rq->KillPlayerID)!=m_mapPlayerIDToPlayerInfo.end())
             {
                 WOLFPLAYERINFO*info=m_mapPlayerIDToPlayerInfo[rq->KillPlayerID];
                 KillPlayerSeatID=info->m_PlayerSeat;
             }
             KillPlayerName=m_wolfRoom->GetPlayerName(KillPlayerSeatID);

             if(QMessageBox::question( this, "提示", QString("%1被杀！！你要救他吗！！").arg(KillPlayerName)) == QMessageBox::Yes)
             {
                 //解药数量减为0
                 witchSave=0;
                 rs.IsSavePlayer=ISSAVEPLAYER;  //使用了解药
                 m_wolfRoom->RecvAnnunciateMsg(QString("你成功救了%1").arg(KillPlayerName));
             }
             else
             {
                 rs.IsSavePlayer=NOSAVEPLAYER;  //没有使用解药
                 m_wolfRoom->RecvAnnunciateMsg(QString("没有使用解药!!!"));
             }
         }
         else
         {//没有解药
             m_wolfRoom->RecvAnnunciateMsg(QString("%1被杀死").arg(KillPlayerName));
             m_wolfRoom->RecvAnnunciateMsg(QString("当前你的解药已经用完了，不能救人了"));
         }
     }
     else
     {//狼人没有杀人的 情况

         m_wolfRoom->RecvAnnunciateMsg(QString("狼人没有杀人"));
     }

     QString strRoom = QInputDialog::getText( this , "女巫请操作" , "用药的话请输入要毒的玩家（例如玩家一号为：1）！！否则输入0！！ ");

     int PoisonSeatID=strRoom.toInt();


     int PoisonPlayerID;
     if(PoisonSeatID==0)
     {
         PoisonPlayerID=0;
     }
     else
     {
         //查找映射表  得到玩家ID
         PoisonPlayerID=m_mapPlayerSeatIDToPlayerID[PoisonSeatID-1];
     }
     rs.m_playerID=m_id;
     rs.wolfRoom=m_wolfroom_id;
     rs.posionPlayerID=PoisonPlayerID;

     //发送回复包

     m_tcpClient->SendData((char*)&rs,sizeof(rs));


}
//处理服务器发来的请求 预言家的
void MyQQDialog::slot_SEERQq(char *buf, int nlen)
{
    //拆包
    STRU_SEER_RQ*rq=(STRU_SEER_RQ*)buf;

    //写回复包
    STRU_SEER_RS rs;
    rs.wolfRoom=m_wolfroom_id;

    m_wolfRoom->RecvAnnunciateMsg(QString("预言家请验人！！！"));

    QString strRoom = QInputDialog::getText( this , "预言家请操作" , "验人的话请输入要查验的玩家（例如玩家一号为：1）！！否则输入0！！ ");

    int CheckSeatID=strRoom.toInt();
    int CheckPlayerID;
    //没有查验人
    if(CheckSeatID==0)
    {
        CheckPlayerID=0;
    }
    else
    {//查验人的情况
        //查找映射表  得到玩家ID
        CheckPlayerID=m_mapPlayerSeatIDToPlayerID[CheckSeatID-1];
    }
    rs.m_playerID=m_id;
    rs.CheckPlayerID=CheckPlayerID;


    m_tcpClient->SendData((char*)&rs,sizeof(rs));

}
//处理服务器发来的查验结果
void MyQQDialog::slot_CheckInfo(char *buf, int nlen)
{
    //拆包
    CHECKPLAYERINFO *rq=(CHECKPLAYERINFO*)buf;

    switch(rq->checkplayerIdentity)
    {
    case 2021:
        m_wolfRoom->RecvAnnunciateMsg(QString("查验该玩家身份为平民！！！"));
        break;
    case 2022:
        m_wolfRoom->RecvAnnunciateMsg(QString("查验该玩家身份为预言家！！！"));
        break;
    case 2023:
        m_wolfRoom->RecvAnnunciateMsg(QString("查验该玩家身份为猎人！！！"));
        break;
    case 2024:
        m_wolfRoom->RecvAnnunciateMsg(QString("查验该玩家身份为女巫！！！"));
        break;
    case 2025:
        m_wolfRoom->RecvAnnunciateMsg(QString("查验该玩家身份为狼人！！！"));
        break;
    case 2026:
        m_wolfRoom->RecvAnnunciateMsg(QString("查验该玩家身份为死人！！！"));
        break;
    case 2027:
        m_wolfRoom->RecvAnnunciateMsg(QString("查验该玩家身份为透明人！！！"));
        break;
    default:break;
    }
}
//处理服务器发来的请求 猎人的
void MyQQDialog::slot_HunterRq(char *buf, int nlen)
{

    //拆包
    STRU_HUNTER_RQ *rq=(STRU_HUNTER_RQ*)buf;

    //写包
    STRU_HUNTER_RS rs;

     m_wolfRoom->RecvAnnunciateMsg(QString("猎人请操作！！！"));

     QString strRoom = QInputDialog::getText( this , "猎人请操作" , "带人的话请输入要带走的玩家（例如玩家一号为：1）！！否则输入0！！ ");

     int TakeSeatID=strRoom.toInt();
     int TakePlayerID;
     //没有带人
     if(TakeSeatID==0)
     {
         TakePlayerID=0;
     }
     else
     {//带人的情况
         //查找映射表  得到玩家ID
         TakePlayerID=m_mapPlayerSeatIDToPlayerID[TakeSeatID-1];
     }

     rs.m_playerID=m_id;

     rs.wolfRoom=m_wolfroom_id;

     rs.TakeAwayPlayerID=TakePlayerID;

     m_tcpClient->SendData((char*)&rs,sizeof(rs));

}
//处理服务器发来的天亮请求
void MyQQDialog::slot_DayBreaksRq(char *buf, int nlen)
{
    m_wolfRoom->RecvAnnunciateMsg(QString("天亮了！！！"));
    //拆包
    STRU_DayBreaks *rq=(STRU_DayBreaks*)buf;


    QString KillPlayerName;
    QString PosionPlayerName;
    QString TakePlayerName;

    //对于被杀死人的相关操作

    //狼人杀死
    if(rq->m_KillPlayerID!=0)
    {

        //找到被杀人的相关信息
        if(m_mapPlayerIDToPlayerInfo.find(rq->m_KillPlayerID)!=m_mapPlayerIDToPlayerInfo.end())
        {
            WOLFPLAYERINFO *info=m_mapPlayerIDToPlayerInfo[rq->m_KillPlayerID];

            int killplayerSeat=info->m_PlayerSeat;
            KillPlayerName=m_wolfRoom->GetPlayerName(killplayerSeat);
        }
        m_wolfRoom->RecvAnnunciateMsg(QString("%1昨晚被杀死！！！").arg(KillPlayerName));
        //设置对应玩家头像为死亡状态
        if(rq->m_KillPlayerID!=m_id)
        {
            m_wolfRoom->SetDEADPERSONIcon(rq->m_KillPlayerID);
        }
    }

    //女巫毒死的
    if(rq->m_PosionPlayerID!=0)
    {

        //找到被杀人的相关信息
        if(m_mapPlayerIDToPlayerInfo.find(rq->m_PosionPlayerID)!=m_mapPlayerIDToPlayerInfo.end())
        {
            WOLFPLAYERINFO *info=m_mapPlayerIDToPlayerInfo[rq->m_PosionPlayerID];

            int PosionplayerSeat=info->m_PlayerSeat;
            PosionPlayerName=m_wolfRoom->GetPlayerName(PosionplayerSeat);
        }
        m_wolfRoom->RecvAnnunciateMsg(QString("%1昨晚被杀死！！！").arg(PosionPlayerName));
        //设置对应玩家头像为死亡状态
        if(rq->m_PosionPlayerID!=m_id)
        {
            m_wolfRoom->SetDEADPERSONIcon(rq->m_PosionPlayerID);
        }
    }
    //猎人带走的
    if(rq->m_TakePlayrID!=0)
    {

        //找到被杀人的相关信息
        if(m_mapPlayerIDToPlayerInfo.find(rq->m_TakePlayrID)!=m_mapPlayerIDToPlayerInfo.end())
        {
            WOLFPLAYERINFO *info=m_mapPlayerIDToPlayerInfo[rq->m_TakePlayrID];

            int TakeplayerSeat=info->m_PlayerSeat;
            TakePlayerName=m_wolfRoom->GetPlayerName(TakeplayerSeat);
        }
        m_wolfRoom->RecvAnnunciateMsg(QString("%1昨晚被杀死！！！").arg(TakePlayerName));
        //设置对应玩家头像为死亡状态
        if(rq->m_TakePlayrID!=m_id)
        {
            m_wolfRoom->SetDEADPERSONIcon(rq->m_TakePlayrID);
        }
    }

    m_wolfRoom->RecvAnnunciateMsg(QString("请各位玩家进行讨论 讨论时间为十分钟"));


    //启动定时器
    m_wolfRoom->SetTimerStart();
    //判断游戏是否结束
    if(rq->m_isGameOver)
    {
        m_wolfRoom->false_dicussion=0;
    }
    else
    {
        m_wolfRoom->false_dicussion=1;
    }


}
//当时间到的时候 进行投票然后 给服务器发送讨论结束 进入晚上
void MyQQDialog::slot_DicussionTimeOver()
{
    //TO  DO
    m_wolfRoom->RecvAnnunciateMsg(QString("讨论时间到！！！"));
    //标志位设为0
    m_wolfRoom->false_dicussion=0;

    //写包
    STRU_Vote_RQ rq;

    //投票
    QString strRoom = QInputDialog::getText( this , "请选着要投票的玩家" , "请输入要投票的玩家（例如玩家一号为：1）！！ ");

    int VoteSeatID=strRoom.toInt();
    int VotePlayerID;
    if(VoteSeatID!=0)
    {//带人的情况
        //查找映射表  得到玩家ID
        VotePlayerID=m_mapPlayerSeatIDToPlayerID[VoteSeatID-1];
    }

    rq.VotePlayerID=VotePlayerID;
    rq.wolfRoom=m_wolfroom_id;

    m_tcpClient->SendData((char*)&rq,sizeof(rq));

}
//处理服务器发来的请求  对于死者的
void MyQQDialog::slot_DeathPlayerRq(char *buf, int nlen)
{
    //拆包
    STRU_DeathPlayer *rq=(STRU_DeathPlayer*)buf;

    //设置为死亡头像
    m_wolfRoom->SetDEADPERSONIcon(m_id);


}
//天黑时间到
void MyQQDialog::slot_GetDarkOver()
{
    //天亮信息包
    m_wolfRoom->RecvAnnunciateMsg(QString("天黑时间到！！！"));
    m_wolfRoom->false_DarkOver=0;
    STRU_DayBreaks rq;
    rq.m_wolfRoom=m_wolfroom_id;

    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}
//投票回复
void MyQQDialog::slot_VoteRS(char *buf, int nlen)
{
    //拆包
    STRU_Vote_RS *rs=(STRU_Vote_RS*)buf;
    int VoteSeatID;
    if(m_mapPlayerIDToPlayerInfo.find(rs->WhereVotePlayerID)!=m_mapPlayerIDToPlayerInfo.end())
    {
        WOLFPLAYERINFO*inner=m_mapPlayerIDToPlayerInfo[rs->WhereVotePlayerID];
        VoteSeatID=inner->m_PlayerSeat;
    }
    //获得玩家名字
    QString VoteName=m_wolfRoom->GetPlayerName(VoteSeatID);
    m_wolfRoom->RecvAnnunciateMsg(QString("%1被票出局").arg(VoteName));
    m_wolfRoom->SetDEADPERSONIcon(rs->WhereVotePlayerID);
    if(rs->WhereVotePlayerID==m_id)
    {
        //启动定时器
        m_wolfRoom->SetTimerStart();

        m_wolfRoom->false_death=1;
    }
}
//狼人要杀的那个人的决定 请求
void MyQQDialog::slot_WolfDecideRq(char *buf, int nlen)
{
    //拆包
    WolfDecide *rq=(WolfDecide*)buf;

    int killplayerSeatID=0;
    if(m_mapPlayerIDToPlayerInfo.find(rq->m_wolfkillplayerID)!=m_mapPlayerIDToPlayerInfo.end())
    {
        WOLFPLAYERINFO*info=m_mapPlayerIDToPlayerInfo[rq->m_wolfkillplayerID];

        killplayerSeatID=info->m_PlayerSeat;
    }
    QString KillplayerName;

    KillplayerName=m_wolfRoom->GetPlayerName(killplayerSeatID);

    m_wolfRoom->RecvAnnunciateMsg(QString("两个狼人队友已经决定杀死%1").arg(KillplayerName));
}
//遗言时间到
void MyQQDialog::slot_DeathTimeOver()
{
    m_wolfRoom->RecvAnnunciateMsg(QString("遗言时间到！！！"));
    m_wolfRoom->false_death=0;
    //禁用所有按钮组件
    m_wolfRoom->SetDEADPERSONToDo();

    //发送天黑信息包
    InToNight rq;

    rq.wolfRoom=m_wolfroom_id;

    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}
//更新游戏天数
void MyQQDialog::slot_ChangeDadyRq(char *buf, int nlen)
{
    //拆包
    ChangeDady *rq=(ChangeDady*)buf;

    //设置游戏天数
    m_wolfRoom->SetGameDays(rq->GameDays);
}
//游戏结束包
void MyQQDialog::slot_GameOverRq(char *buf, int nlen)
{
    //拆包
    GameOver *rq=(GameOver*)buf;
    if(rq->m_GameResult==GOODIESVICTORY)
    {
        m_wolfRoom->RecvAnnunciateMsg(QString("好人获得胜利！！！"));
    }
    if(rq->m_GameResult==WOLFVICTORY)
    {
        m_wolfRoom->RecvAnnunciateMsg(QString("狼人获得胜利！！！"));
    }
}
//心跳
void MyQQDialog::slot_heartConnect()
{
    //发送心跳包
    STRU_HEART rq;
    rq.m_nUserId = m_id;
    if( m_tcpClient->IsConnected() )
        m_tcpClient->SendData( (char*)&rq , sizeof(rq) );
}
//提醒断线重登
void MyQQDialog::slot_disConnect()
{
    QMessageBox::information( m_loginDlg ,"警告" ,"与服务器失去连接,重新登录" );
}

