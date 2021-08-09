#ifndef QTCPCLIENT_H
#define QTCPCLIENT_H

#include <QObject>
#include"TCPNet.h"

#define DEF_SERVER_IP  "192.168.1.104"
#define DEF_TCP_PORT   8000
class QMyTcpClient : public QObject,public ITcpMediator
{
    Q_OBJECT
public:
    explicit QMyTcpClient(QObject *parent = 0);
    ~QMyTcpClient();
signals:
    void SIG_ReadyData( char* szbuf , int nLen );
     void SIG_disConnect();
public slots:
    bool InitNetWork(char* szBufIP = DEF_SERVER_IP, unsigned short port = DEF_TCP_PORT);
    void setIpAndPort(char* szBufIP = DEF_SERVER_IP, unsigned short port = DEF_TCP_PORT);
    void UnInitNetWork();
    int SendData(char* szbuf,int nLen);
    int ConnectToServer( char* szBufIP= DEF_SERVER_IP);
    void DealData(char* szbuf , int nLen);
     void disConnect();
    int IsConnected();
public:
    TCPNet *m_pTcp;
    char  m_szBufIP[50];
    unsigned short m_port ;
};

#endif // QTCPCLIENT_H
