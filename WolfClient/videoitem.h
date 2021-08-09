#ifndef VIDEOITEM_H
#define VIDEOITEM_H

#include <QWidget>
#include<QImage>
#include<QPaintEvent>
#include<QPainter>
#include<QMouseEvent>
#include<QTimer>
#include<QTime>
namespace Ui {
class VideoItem;
}

class VideoItem : public QWidget
{
    Q_OBJECT

public:
    explicit VideoItem(QWidget *parent = 0);
    ~VideoItem();
signals:
    void SIG_itemClicked(int id);
public slots:
    //设置成员变量信息
    void setInfo(int id,QString name);
    //获得图片内容  设置图片
    void slot_setOneImage(QImage);

    //重绘事件
    void paintEvent(QPaintEvent *event);
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *event);


    //检查对方视频图片 有无传输
    void slot_checkTime();
private:
    Ui::VideoItem *ui;
public:

    int m_id;
    QString m_name;
    QImage m_image;


    QTimer *m_timer;
    QTime m_lastTimer;

    //默认图片
    QImage m_defauleimage;


};

#endif // VIDEOITEM_H
