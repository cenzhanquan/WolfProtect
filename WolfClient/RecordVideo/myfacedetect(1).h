#ifndef MYFACEDETECT_H
#define MYFACEDETECT_H

#include <QObject>
#include"common.h"

class MyFaceDetect : public QObject
{
    Q_OBJECT
public:
    explicit MyFaceDetect(QObject *parent = 0);

signals:

public slots:

   static void detectAndDisplay(Mat &frame , std::vector<Rect> &faces);

   static void FaceDetectInit();
};

#endif // MYFACEDETECT_H
