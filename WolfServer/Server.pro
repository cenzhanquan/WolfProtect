TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS+=-lpthread
LIBS+=-lmysqlclient


INCLUDEPATH+=./include/
HEADERS += \
    include/Mysql.h \
    include/TCPKernel.h \
    include/TCPNet.h \
    include/Thread_pool.h \
    include/err_str.h \
    include/packdef.h

SOURCES += \
    src/Mysql.cpp \
    src/TCPKernel.cpp \
    src/TCPNet.cpp \
    src/Thread_pool.cpp \
    src/err_str.cpp \
    src/main.cpp


