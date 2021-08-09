#include "myfacedetect.h"

#include "objdetect/objdetect.hpp"
#include<QCoreApplication>
#include<qDebug>

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
CascadeClassifier nose_cascade;

String window_name_face = "Capture - Face";

MyFaceDetect::MyFaceDetect(QObject *parent) : QObject(parent)
{


}

void MyFaceDetect::FaceDetectInit()
{
    QString face_cascade_name = QCoreApplication::applicationDirPath()+"/lbpcascade_frontalface.xml";//"haarcascade_frontalface_alt.xml";
    QString eyes_cascade_name = QCoreApplication::applicationDirPath()+"/haarcascade_eye.xml";//haarcascade_eye_tree_eyeglasses.xml,
    QString nose_cascade_name = QCoreApplication::applicationDirPath()+"/haarcascade_mcs_nose.xml";//haarcascade_mcs_mouth.xml

    qDebug() << face_cascade_name;
    //-- 1. Load the cascade
    if( !face_cascade.load( face_cascade_name.toStdString() ) )
    {
        qDebug()<< "--(!)Error loading\n" ;
        return;
    }
    if( !eyes_cascade.load( eyes_cascade_name.toStdString() ) )
    {
        qDebug()<<"--(!)Error loading\n" ;
        return;
    }
    if( !nose_cascade.load( nose_cascade_name.toStdString() ) )
    {
        qDebug()<<"--(!)Error loading\n" ;
        return;
    }
}

#include<QCoreApplication>

void MyFaceDetect::detectAndDisplay(Mat& frame ,std::vector<Rect> &faces)
{
    Mat frame_gray;

    cvtColor( frame, frame_gray, CV_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- 多尺寸检测人脸
    //第三个参数 每个图像比例下图像大小减少多少的参数。
    //第四个参数 指定每个候选矩形应该为邻居保留多少个像素。
    //第五个参数 参数与函数cvHaarDetectObjects中的旧级联具有相同的含义。是新版本还是旧版本
    //第六个参数 最小可能对象大小。小于该值的对象将被忽略。
    //第七个参数 最大可能对象大小。大于该值的对象将被忽略
    face_cascade.detectMultiScale( frame_gray, faces, 1.01, 6, 0, Size(66, 66),Size(300, 300) );

    for( auto ite = faces.begin() ; ite != faces.end() ;  )
    {
        Rect rct = *ite;

        Mat faceROI = frame_gray( rct );
        std::vector<Rect> eyes;
        std::vector<Rect> nose;
        //-- 在每张人脸上检测双眼
//        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 , Size(30, 30) );

        nose_cascade.detectMultiScale( faceROI, nose, 1.1, 2, 0 , Size(30, 30) );

        if( /*eyes.size() != 2 ||*/ nose.size() == 0 )
        {
            ite = faces.erase(ite);
        }else
        {
            //画识别的方框
//            Point center( rct.x + rct.width*0.5, rct.y + rct.height*0.5 );
//            ellipse( frame, center, Size( rct.width*0.5, rct.height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

            ++ite;
        }

    }
    //-- 显示结果图像
//    imshow( window_name_face, frame );
}

