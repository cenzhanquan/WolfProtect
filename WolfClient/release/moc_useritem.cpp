/****************************************************************************
** Meta object code from reading C++ file 'useritem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../useritem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'useritem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserItem_t {
    QByteArrayData data[8];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserItem_t qt_meta_stringdata_UserItem = {
    {
QT_MOC_LITERAL(0, 0, 8), // "UserItem"
QT_MOC_LITERAL(1, 9, 15), // "SIG_ItemClicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "SIG_Offline"
QT_MOC_LITERAL(4, 38, 21), // "mouseDoubleClickEvent"
QT_MOC_LITERAL(5, 60, 12), // "QMouseEvent*"
QT_MOC_LITERAL(6, 73, 5), // "event"
QT_MOC_LITERAL(7, 79, 18) // "on_pb_icon_clicked"

    },
    "UserItem\0SIG_ItemClicked\0\0SIG_Offline\0"
    "mouseDoubleClickEvent\0QMouseEvent*\0"
    "event\0on_pb_icon_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   38,    2, 0x0a /* Public */,
       7,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void UserItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserItem *_t = static_cast<UserItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_ItemClicked(); break;
        case 1: _t->SIG_Offline((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->mouseDoubleClickEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->on_pb_icon_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UserItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserItem::SIG_ItemClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UserItem::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserItem::SIG_Offline)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject UserItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserItem.data,
      qt_meta_data_UserItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserItem.stringdata0))
        return static_cast<void*>(const_cast< UserItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void UserItem::SIG_ItemClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void UserItem::SIG_Offline(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
