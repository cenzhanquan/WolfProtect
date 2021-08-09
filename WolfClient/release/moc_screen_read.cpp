/****************************************************************************
** Meta object code from reading C++ file 'screen_read.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RecordVideo/screen_read.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screen_read.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Screen_Read_t {
    QByteArrayData data[8];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Screen_Read_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Screen_Read_t qt_meta_stringdata_Screen_Read = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Screen_Read"
QT_MOC_LITERAL(1, 12, 19), // "SIG_sendScreenFrame"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "QImage&"
QT_MOC_LITERAL(4, 41, 3), // "img"
QT_MOC_LITERAL(5, 45, 19), // "slot_getScreenFrame"
QT_MOC_LITERAL(6, 65, 15), // "slot_openScreen"
QT_MOC_LITERAL(7, 81, 16) // "slot_closeScreen"

    },
    "Screen_Read\0SIG_sendScreenFrame\0\0"
    "QImage&\0img\0slot_getScreenFrame\0"
    "slot_openScreen\0slot_closeScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Screen_Read[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   37,    2, 0x0a /* Public */,
       6,    0,   38,    2, 0x0a /* Public */,
       7,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Screen_Read::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Screen_Read *_t = static_cast<Screen_Read *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_sendScreenFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->slot_getScreenFrame(); break;
        case 2: _t->slot_openScreen(); break;
        case 3: _t->slot_closeScreen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Screen_Read::*_t)(QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Screen_Read::SIG_sendScreenFrame)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Screen_Read::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Screen_Read.data,
      qt_meta_data_Screen_Read,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Screen_Read::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Screen_Read::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Screen_Read.stringdata0))
        return static_cast<void*>(const_cast< Screen_Read*>(this));
    return QObject::qt_metacast(_clname);
}

int Screen_Read::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Screen_Read::SIG_sendScreenFrame(QImage & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
