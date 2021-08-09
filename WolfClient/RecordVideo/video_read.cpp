#include "video_read.h"
#include<QDebug>
#include<QMessageBox>
#include<QImage>
#include<QImageReader>
#include<QBuffer>
#include"myfacedetect.h"
#include<QPainter>

Video_Read::Video_Read(QObject  *parent)
    : QObject(parent) , m_moji(0)
{
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT( slot_getVideoFrame())   );

    MyFaceDetect::FaceDetectInit();
}

void Video_Read::slot_openVideo()
{
    cap.open(0);
    if(!cap.isOpened()){
        QMessageBox::information(NULL,tr("提示"),tr("视频没有打开"));
        return;
    }
    timer->start(1000/FRAME_RATE);
}
void Video_Read::slot_closeVideo()
{
    timer->stop();
    if(cap.isOpened())
        cap.release();
}

void Video_Read::slot_setMoji(int type)
{
    m_moji = type;
}

void Video_Read::slot_getVideoFrame()
{
    Mat frame;

    if( !cap.read(frame) )
    {
        return;
    }
#if NOT_USE_FACE_DETECT
    cvtColor(frame,frame,CV_BGR2RGB);

    QImage image((unsigned const char*)frame.data,frame.cols,frame.rows,QImage::Format_RGB888);
    image = image.scaled( 320,240, Qt::KeepAspectRatio,Qt::FastTransformation );
    Q_EMIT SIG_sendVideoFrame(image);
    return;
#else
    std::vector<Rect> faces;

    if( m_moji != no_icon)
        MyFaceDetect::detectAndDisplay(frame , faces);

    cvtColor(frame,frame,CV_BGR2RGB);

    QImage image((unsigned const char*)frame.data,frame.cols,frame.rows,QImage::Format_RGB888);

    if( faces.size() > 0 )
        m_lastfaces = faces;

    QString imgPath;
    switch( m_moji)
    {
    case no_icon:break;
    case tuzi:
        imgPath = QString(":/images/tuer.png");
        break;
    case hat:
        imgPath = QString(":/images/hat.png");
        break;
    }
    if( !imgPath.isEmpty())
    {
        QPainter paint(&image);
        QImage tutu( imgPath );
//      tutu= tutu.scaled( QSize(150,120),Qt::KeepAspectRatio ,Qt::FastTransformation);
        for( int i = 0; i < m_lastfaces.size()  ; i++ )
        {

            Rect rct = m_lastfaces[i];

            QPoint p( rct.x + rct.width*0.5 - tutu.width()*0.5 + 20   ,
                      rct.y - tutu.height()) ;

            paint.drawImage( p , tutu  );

        }
    }
    image = image.scaled( IMAGE_WIDTH,IMAGE_HEIGHT, Qt::KeepAspectRatio,Qt::FastTransformation );

    Q_EMIT SIG_sendVideoFrame(image);
    return;
#endif
}

