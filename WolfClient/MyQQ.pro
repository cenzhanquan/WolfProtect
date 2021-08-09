#-------------------------------------------------
#
# Project created by QtCreator 2021-04-01T20:23:19
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyQQ
TEMPLATE = app


include(./netapi/netapi.pri)

INCLUDEPATH += ./netapi/



include(./RecordVideo/RecordVideo.pri)

INCLUDEPATH += ./RecordVideo/




include(./RecordAudio/RecordAudio.pri)

INCLUDEPATH += ./RecordAudio/


include(./uiapi/uiapi.pri)

INCLUDEPATH += ./uiapi/


INCLUDEPATH+=G:\opencv\OpenCV\include\opencv\
 G:\opencv\OpenCV\include\opencv2\
 G:\opencv\OpenCV\include
LIBS+=G:\opencv\OpenCV\lib\libopencv_calib3d2410.dll.a\
 G:\opencv\OpenCV\lib\libopencv_contrib2410.dll.a\
 G:\opencv\OpenCV\lib\libopencv_core2410.dll.a\
 G:\opencv\OpenCV\lib\libopencv_features2d2410.dll.a\
 G:\opencv\OpenCV\lib\libopencv_flann2410.dll.a\
 G:\opencv\OpenCV\lib\libopencv_gpu2410.dll.a\
 G:\opencv\OpenCV\lib\libopencv_highgui2410.dll.a\
 G:\opencv\OpenCV\lib\libopencv_imgproc2410.dll.a\
 G:\opencv\OpenCV\lib\libopencv_legacy2410.dll.a\
 G:\opencv\OpenCV\lib\libopencv_ml2410.dll.a\
 G:\opencv\OpenCV\lib\libopencv_objdetect2410.dll.a\
 G:\opencv\OpenCV\lib\libopencv_video2410.dll.a


SOURCES += main.cpp\
        myqqdialog.cpp \
    logindialog.cpp \
    useritem.cpp \
    IMToolBox.cpp \
    chatdialog.cpp \
    roomdialog.cpp \
    videoitem.cpp \
    werewolfdialog.cpp \
    gameruledialog.cpp \
    friendofflinedialog.cpp \
    playeridentitydialog.cpp

HEADERS  += myqqdialog.h \
    logindialog.h \
    useritem.h \
    IMToolBox.h \
    chatdialog.h \
    roomdialog.h \
    videoitem.h \
    werewolfdialog.h \
    gameruledialog.h \
    wolfpackdf.h \
    friendofflinedialog.h \
    playeridentitydialog.h

FORMS    += myqqdialog.ui \
    logindialog.ui \
    useritem.ui \
    chatdialog.ui \
    roomdialog.ui \
    videoitem.ui \
    werewolfdialog.ui \
    gameruledialog.ui \
    friendofflinedialog.ui \
    playeridentitydialog.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    bq/000.png \
    bq/0.png \
    bq/001.png \
    bq/1.png \
    bq/002.png \
    bq/2.png \
    bq/003.png \
    bq/3.png \
    bq/004.png \
    bq/4.png \
    bq/005.png \
    bq/5.png \
    bq/006.png \
    bq/6.png \
    bq/007.png \
    bq/7.png \
    bq/008.png \
    bq/8.png \
    bq/009.png \
    bq/9.png \
    bq/010.png \
    bq/10.png \
    bq/011.png \
    bq/11.png \
    bq/012.png \
    bq/12.png \
    bq/013.png
