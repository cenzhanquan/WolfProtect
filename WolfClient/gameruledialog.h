#ifndef GAMERULEDIALOG_H
#define GAMERULEDIALOG_H

#include <QDialog>
#include"customwidget.h"
#include<QPixmap>
#include<QPainter>
#include<QRect>
namespace Ui {
class GameRuleDialog;
}

class GameRuleDialog : public /*QDialog*/CustomMoveDialog
{
    Q_OBJECT

public:
    explicit GameRuleDialog(QWidget *parent = 0);
    ~GameRuleDialog();

private:
    Ui::GameRuleDialog *ui;
public:
    void paintEvent(QPaintEvent*event);  //重绘
private slots:
    void on_pushButton_clicked();
};

#endif // GAMERULEDIALOG_H
