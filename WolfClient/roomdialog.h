#ifndef ROOMDIALOG_H
#define ROOMDIALOG_H

#include <QDialog>
#include"videoitem.h"
#include"IMToolBox.h"
#include"customwidget.h"
namespace Ui {
class RoomDialog;
}

class RoomDialog : public /*QDialog*/CustomMoveDialog
{
    Q_OBJECT

public:
    explicit RoomDialog(QWidget *parent = 0);
    ~RoomDialog();
    Ui::RoomDialog *getUi() const;

signals:
    void SIG_quitRoom(int);

    void SIG_openAudioDev();
    void SIG_closeAudioDev();
    void SIG_openVideoDev();
    void SIG_closeVideoDev();
    void SIG_setMoji(int type);
public slots:
    void on_pb_quit_clicked();
    void slot_setInfo(int id);
    void clear();
    void on_pb_Video_clicked();

    void on_pb_Audio_clicked();

    void on_cbx_tuzi_currentIndexChanged(const QString &arg1);

    void on_pb_close_clicked();

    void slot_addVideoItem(VideoItem*);

    void slot_removeVideoItem(VideoItem*);
    void slot_setBigImageID(int id,QString name);
    int  slot_getBigImageID();

private:
    Ui::RoomDialog *ui;

    int m_roomid;

    IMToolList *m_videoList;

};

#endif // ROOMDIALOG_H
