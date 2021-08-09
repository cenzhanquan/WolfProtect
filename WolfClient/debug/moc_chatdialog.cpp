/****************************************************************************
** Meta object code from reading C++ file 'chatdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chatdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_chatDialog_t {
    QByteArrayData data[13];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chatDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chatDialog_t qt_meta_stringdata_chatDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "chatDialog"
QT_MOC_LITERAL(1, 11, 15), // "SIG_SendChatMsg"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "id"
QT_MOC_LITERAL(4, 31, 7), // "content"
QT_MOC_LITERAL(5, 39, 18), // "on_pb_send_clicked"
QT_MOC_LITERAL(6, 58, 16), // "slot_recvChatMsg"
QT_MOC_LITERAL(7, 75, 16), // "slot_showOffline"
QT_MOC_LITERAL(8, 92, 7), // "setInfo"
QT_MOC_LITERAL(9, 100, 4), // "name"
QT_MOC_LITERAL(10, 105, 17), // "on_pb_min_clicked"
QT_MOC_LITERAL(11, 123, 17), // "on_pb_max_clicked"
QT_MOC_LITERAL(12, 141, 19) // "on_pb_close_clicked"

    },
    "chatDialog\0SIG_SendChatMsg\0\0id\0content\0"
    "on_pb_send_clicked\0slot_recvChatMsg\0"
    "slot_showOffline\0setInfo\0name\0"
    "on_pb_min_clicked\0on_pb_max_clicked\0"
    "on_pb_close_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chatDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   59,    2, 0x0a /* Public */,
       6,    1,   60,    2, 0x0a /* Public */,
       7,    0,   63,    2, 0x0a /* Public */,
       8,    2,   64,    2, 0x0a /* Public */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void chatDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chatDialog *_t = static_cast<chatDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_SendChatMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->on_pb_send_clicked(); break;
        case 2: _t->slot_recvChatMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slot_showOffline(); break;
        case 4: _t->setInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->on_pb_min_clicked(); break;
        case 6: _t->on_pb_max_clicked(); break;
        case 7: _t->on_pb_close_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (chatDialog::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chatDialog::SIG_SendChatMsg)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject chatDialog::staticMetaObject = {
    { &CustomMoveDialog::staticMetaObject, qt_meta_stringdata_chatDialog.data,
      qt_meta_data_chatDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *chatDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_chatDialog.stringdata0))
        return static_cast<void*>(const_cast< chatDialog*>(this));
    return CustomMoveDialog::qt_metacast(_clname);
}

int chatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomMoveDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void chatDialog::SIG_SendChatMsg(int _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
