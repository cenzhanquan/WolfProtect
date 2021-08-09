#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include"customwidget.h"
namespace Ui {
class chatDialog;
}

class chatDialog : public /*QDialog*/CustomMoveDialog
{
    Q_OBJECT
signals:
    void SIG_SendChatMsg(int id,QString content);

public:
    explicit chatDialog(QWidget *parent = 0);
    ~chatDialog();

private:
    Ui::chatDialog *ui;


public:
    int m_id;
    QString m_name;
public slots:
    void on_pb_send_clicked();


    void slot_recvChatMsg(QString);

    void slot_showOffline();
    void setInfo(int id,QString name);

private slots:
    void on_pb_min_clicked();
    void on_pb_max_clicked();
    void on_pb_close_clicked();
};

#endif // CHATDIALOG_H
