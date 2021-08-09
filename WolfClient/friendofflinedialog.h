#ifndef FRIENDOFFLINEDIALOG_H
#define FRIENDOFFLINEDIALOG_H

#include <QDialog>

namespace Ui {
class FriendOfflineDialog;
}

class FriendOfflineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FriendOfflineDialog(QWidget *parent = 0);
    ~FriendOfflineDialog();

public slots:
    void SetInfo(QString name);

private:
    Ui::FriendOfflineDialog *ui;
};

#endif // FRIENDOFFLINEDIALOG_H
