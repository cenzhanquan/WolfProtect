#ifndef PLAYERIDENTITYDIALOG_H
#define PLAYERIDENTITYDIALOG_H

#include <QDialog>
#include"wolfpackdf.h"
#include"customwidget.h"

#include"werewolfdialog.h"

namespace Ui {
class PlayerIdentityDialog;
}

class PlayerIdentityDialog : public /*QDialog*/CustomMoveDialog
{
    Q_OBJECT

public:
    explicit PlayerIdentityDialog(QWidget *parent = 0);
    ~PlayerIdentityDialog();

private:
    Ui::PlayerIdentityDialog *ui;

public:
    void setPlayerIdentity(int Identity);
private slots:
    void on_pushButton_clicked();
};

#endif // PLAYERIDENTITYDIALOG_H
