#ifndef VIDEO_READ_H
#define VIDEO_READ_H


#include <QObject>
#include<QTimer>
#include<QImage>
#include"common.h"

using namespace cv;

#define FRAME_RATE (10)
#define IMAGE_WIDTH (320)
#define IMAGE_HEIGHT (240)

class Video_Read : public QObject
{
    Q_OBJECT

public:
    explicit Video_Read(QObject *parent = 0);

    enum MojiType{
        no_icon,
        tuzi,
        hat
    };

signals:
    void SIG_sendVideoFrame( QImage& img);
public slots:
    void slot_getVideoFrame();
    void slot_openVideo();
    void slot_closeVideo();
    void slot_setMoji( int type = MojiType::no_icon);

private:

    VideoCapture cap;

    QTimer * timer;

    std::vector<Rect> m_lastfaces;

public:
    int m_moji;
};

#endif // VIDEO_READ_H
