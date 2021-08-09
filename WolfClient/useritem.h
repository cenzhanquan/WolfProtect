#ifndef USERITEM_H
#define USERITEM_H

#include <QWidget>
#include<QMouseEvent>
namespace Ui {
class UserItem;
}

class UserItem : public QWidget
{
    Q_OBJECT

public:
    explicit UserItem(QWidget *parent = 0);
    ~UserItem();

    Ui::UserItem *getUi() const;

    void setInfo( int id,int state,QString name,
                  QString icon = QString(":/tx/11.png"),QString feeling = QString("比较懒,什么也没写"));


    void setOfflineIcon(int state);
signals:
    void SIG_ItemClicked();

    void SIG_Offline(QString);
public slots:
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    Ui::UserItem *ui;
public:
    int m_id;
    int m_state;
    QString m_name;
    QString m_icon;
    QString m_feeling;

private slots:
    void on_pb_icon_clicked();
};

#endif // USERITEM_H
