#include "myqqdialog.h"
#include <QApplication>
#include<QFile>
#include"qDebug"
#include<QCoreApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QString path=QString("%1/%2").arg(QCoreApplication::applicationDirPath())
            .arg("qq.css");


    qDebug()<<path;


    //设置风格样式
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    qApp->setStyleSheet(file.readAll());
    file.close();



    MyQQDialog w;
    //w.show();

    return a.exec();
}
