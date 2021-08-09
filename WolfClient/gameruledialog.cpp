#include "gameruledialog.h"
#include "ui_gameruledialog.h"
#include<QPalette>
GameRuleDialog::GameRuleDialog(QWidget *parent) :
    /*QDialog*/CustomMoveDialog(parent),
    ui(new Ui::GameRuleDialog)
{
    ui->setupUi(this);

    //设置背景
    QPalette pal=this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/images/GameShow.jpg")));
    setPalette(pal);

    this->repaint();  //直接调用重绘事件
}

GameRuleDialog::~GameRuleDialog()
{
    delete ui;
}
//重绘事件
void GameRuleDialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/images/GameShow.jpg"),QRect());
}

void GameRuleDialog::on_pushButton_clicked()
{
    this->close();
}
