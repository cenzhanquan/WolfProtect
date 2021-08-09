/****************************************************************************
** Meta object code from reading C++ file 'videoitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../videoitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VideoItem_t {
    QByteArrayData data[13];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoItem_t qt_meta_stringdata_VideoItem = {
    {
QT_MOC_LITERAL(0, 0, 9), // "VideoItem"
QT_MOC_LITERAL(1, 10, 15), // "SIG_itemClicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 2), // "id"
QT_MOC_LITERAL(4, 30, 7), // "setInfo"
QT_MOC_LITERAL(5, 38, 4), // "name"
QT_MOC_LITERAL(6, 43, 16), // "slot_setOneImage"
QT_MOC_LITERAL(7, 60, 10), // "paintEvent"
QT_MOC_LITERAL(8, 71, 12), // "QPaintEvent*"
QT_MOC_LITERAL(9, 84, 5), // "event"
QT_MOC_LITERAL(10, 90, 15), // "mousePressEvent"
QT_MOC_LITERAL(11, 106, 12), // "QMouseEvent*"
QT_MOC_LITERAL(12, 119, 14) // "slot_checkTime"

    },
    "VideoItem\0SIG_itemClicked\0\0id\0setInfo\0"
    "name\0slot_setOneImage\0paintEvent\0"
    "QPaintEvent*\0event\0mousePressEvent\0"
    "QMouseEvent*\0slot_checkTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   47,    2, 0x0a /* Public */,
       6,    1,   52,    2, 0x0a /* Public */,
       7,    1,   55,    2, 0x0a /* Public */,
      10,    1,   58,    2, 0x0a /* Public */,
      12,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    5,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void,

       0        // eod
};

void VideoItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoItem *_t = static_cast<VideoItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_itemClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->slot_setOneImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 4: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->slot_checkTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VideoItem::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoItem::SIG_itemClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject VideoItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VideoItem.data,
      qt_meta_data_VideoItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VideoItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VideoItem.stringdata0))
        return static_cast<void*>(const_cast< VideoItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int VideoItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void VideoItem::SIG_itemClicked(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
