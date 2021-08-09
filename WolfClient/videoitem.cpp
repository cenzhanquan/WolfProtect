#include "videoitem.h"
#include "ui_videoitem.h"
#include <QPixmap>
VideoItem::VideoItem(QWidget *parent) :
    QWidget(parent),m_defauleimage(":/tx/12.png"),
    ui(new Ui::VideoItem)
{
    ui->setupUi(this);

//----------------------------------------------------------------------------------
    //定时器
    m_timer=new QTimer;

    connect(m_timer,SIGNAL(timeout()),this,SLOT(slot_checkTime()));

    //启动定时器
    m_timer->start(500);

    //获得当前时间  及获得上一次的时间
    m_lastTimer=QTime::currentTime();

//------------------------------------------------------------------------------------
}

VideoItem::~VideoItem()
{
    delete ui;


    if(m_timer)
    {
        //暂停定时器 并且回收
        m_timer->stop();
        delete m_timer;
    }
}
//设置信息
void VideoItem::setInfo(int id, QString name)
{
    m_id=id;
    m_name=name;

    ui->lb_name->setText(QString("用户名:%1").arg(m_name));
}
//更新 设置图片
void VideoItem::slot_setOneImage(QImage image)
{
    m_image=image;

    //获得当前时间  及获得上一次的时间
    m_lastTimer=QTime::currentTime();


    this->repaint();   //直接重绘  ---->转到重绘事件
}
//重绘事件
void VideoItem::paintEvent(QPaintEvent *event)
{
    //画背景
    QPainter painter(this);
    //获得黑色的画刷
    painter.setBrush(Qt::black);
    //画正方形
    painter.drawRect(0,0,this->width(),this->height());

    //画图片

    //检查图片的完整性  正确性
    if(m_image.size().height()<=0)return ;

    //加载图片 QImage 画图使用QPixmap
    //图片缩放  scaled

    QPixmap pixmap=QPixmap::fromImage(m_image.scaled(QSize(this->width(),this->height()-ui->lb_name->height())
                                                     ,Qt::KeepAspectRatio,Qt::FastTransformation));

    //画的位置
    int x = this->width() - pixmap.width();
    int y = this->height() - pixmap.height() - ui->lb_name->height();
    x = x /2;
    y = ui->lb_name->height() + y/2;

    //开始画
    painter.drawPixmap(QPoint(x,y),pixmap);
}

void VideoItem::mousePressEvent(QMouseEvent *event)
{
    Q_EMIT SIG_itemClicked(m_id);
}

//检查对方视频图片 有无传输   超过特定的时间要进行相应的处理
void VideoItem::slot_checkTime()
{
    //判读当前时间和上一次时间作比较  当超过三秒的时候 则证明 视频图片没有传输 设置成默认图片即可
    if(m_lastTimer.secsTo(QTime::currentTime())>3)
    {
        m_lastTimer=QTime::currentTime();
        m_image=m_defauleimage;
        this->repaint();
    }
}
