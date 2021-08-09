/****************************************************************************
** Meta object code from reading C++ file 'qmytcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../netapi/qmytcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmytcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMyTcpClient_t {
    QByteArrayData data[17];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMyTcpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMyTcpClient_t qt_meta_stringdata_QMyTcpClient = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QMyTcpClient"
QT_MOC_LITERAL(1, 13, 13), // "SIG_ReadyData"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "char*"
QT_MOC_LITERAL(4, 34, 5), // "szbuf"
QT_MOC_LITERAL(5, 40, 4), // "nLen"
QT_MOC_LITERAL(6, 45, 14), // "SIG_disConnect"
QT_MOC_LITERAL(7, 60, 11), // "InitNetWork"
QT_MOC_LITERAL(8, 72, 7), // "szBufIP"
QT_MOC_LITERAL(9, 80, 4), // "port"
QT_MOC_LITERAL(10, 85, 12), // "setIpAndPort"
QT_MOC_LITERAL(11, 98, 13), // "UnInitNetWork"
QT_MOC_LITERAL(12, 112, 8), // "SendData"
QT_MOC_LITERAL(13, 121, 15), // "ConnectToServer"
QT_MOC_LITERAL(14, 137, 8), // "DealData"
QT_MOC_LITERAL(15, 146, 10), // "disConnect"
QT_MOC_LITERAL(16, 157, 11) // "IsConnected"

    },
    "QMyTcpClient\0SIG_ReadyData\0\0char*\0"
    "szbuf\0nLen\0SIG_disConnect\0InitNetWork\0"
    "szBufIP\0port\0setIpAndPort\0UnInitNetWork\0"
    "SendData\0ConnectToServer\0DealData\0"
    "disConnect\0IsConnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMyTcpClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,
       6,    0,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   95,    2, 0x0a /* Public */,
       7,    1,  100,    2, 0x2a /* Public | MethodCloned */,
       7,    0,  103,    2, 0x2a /* Public | MethodCloned */,
      10,    2,  104,    2, 0x0a /* Public */,
      10,    1,  109,    2, 0x2a /* Public | MethodCloned */,
      10,    0,  112,    2, 0x2a /* Public | MethodCloned */,
      11,    0,  113,    2, 0x0a /* Public */,
      12,    2,  114,    2, 0x0a /* Public */,
      13,    1,  119,    2, 0x0a /* Public */,
      13,    0,  122,    2, 0x2a /* Public | MethodCloned */,
      14,    2,  123,    2, 0x0a /* Public */,
      15,    0,  128,    2, 0x0a /* Public */,
      16,    0,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 3, QMetaType::UShort,    8,    9,
    QMetaType::Bool, 0x80000000 | 3,    8,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort,    8,    9,
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Int, 0x80000000 | 3,    8,
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Int,

       0        // eod
};

void QMyTcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMyTcpClient *_t = static_cast<QMyTcpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_ReadyData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->SIG_disConnect(); break;
        case 2: { bool _r = _t->InitNetWork((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< unsigned short(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->InitNetWork((*reinterpret_cast< char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->InitNetWork();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->setIpAndPort((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< unsigned short(*)>(_a[2]))); break;
        case 6: _t->setIpAndPort((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 7: _t->setIpAndPort(); break;
        case 8: _t->UnInitNetWork(); break;
        case 9: { int _r = _t->SendData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->ConnectToServer((*reinterpret_cast< char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { int _r = _t->ConnectToServer();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: _t->DealData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->disConnect(); break;
        case 14: { int _r = _t->IsConnected();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QMyTcpClient::*_t)(char * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMyTcpClient::SIG_ReadyData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QMyTcpClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMyTcpClient::SIG_disConnect)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QMyTcpClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QMyTcpClient.data,
      qt_meta_data_QMyTcpClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QMyTcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMyTcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QMyTcpClient.stringdata0))
        return static_cast<void*>(const_cast< QMyTcpClient*>(this));
    if (!strcmp(_clname, "ITcpMediator"))
        return static_cast< ITcpMediator*>(const_cast< QMyTcpClient*>(this));
    return QObject::qt_metacast(_clname);
}

int QMyTcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void QMyTcpClient::SIG_ReadyData(char * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QMyTcpClient::SIG_disConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
