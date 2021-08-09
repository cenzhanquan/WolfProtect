/****************************************************************************
** Meta object code from reading C++ file 'IMToolBox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../IMToolBox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IMToolBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IMToolList_t {
    QByteArrayData data[9];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IMToolList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IMToolList_t qt_meta_stringdata_IMToolList = {
    {
QT_MOC_LITERAL(0, 0, 10), // "IMToolList"
QT_MOC_LITERAL(1, 11, 15), // "renameBoxSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "title"
QT_MOC_LITERAL(4, 34, 15), // "removeBoxSignal"
QT_MOC_LITERAL(5, 50, 9), // "renameBox"
QT_MOC_LITERAL(6, 60, 9), // "removeBox"
QT_MOC_LITERAL(7, 70, 18), // "onClickRightButton"
QT_MOC_LITERAL(8, 89, 21) // "on_ToolButton_Clicked"

    },
    "IMToolList\0renameBoxSignal\0\0title\0"
    "removeBoxSignal\0renameBox\0removeBox\0"
    "onClickRightButton\0on_ToolButton_Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IMToolList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   50,    2, 0x08 /* Private */,
       6,    0,   51,    2, 0x08 /* Private */,
       7,    0,   52,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IMToolList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IMToolList *_t = static_cast<IMToolList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->renameBoxSignal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->removeBoxSignal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->renameBox(); break;
        case 3: _t->removeBox(); break;
        case 4: _t->onClickRightButton(); break;
        case 5: _t->on_ToolButton_Clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IMToolList::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IMToolList::renameBoxSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (IMToolList::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IMToolList::removeBoxSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject IMToolList::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IMToolList.data,
      qt_meta_data_IMToolList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IMToolList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IMToolList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IMToolList.stringdata0))
        return static_cast<void*>(const_cast< IMToolList*>(this));
    return QWidget::qt_metacast(_clname);
}

int IMToolList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void IMToolList::renameBoxSignal(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IMToolList::removeBoxSignal(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_IMToolBox_t {
    QByteArrayData data[8];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IMToolBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IMToolBox_t qt_meta_stringdata_IMToolBox = {
    {
QT_MOC_LITERAL(0, 0, 9), // "IMToolBox"
QT_MOC_LITERAL(1, 10, 15), // "mousePressEvent"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 40, 5), // "event"
QT_MOC_LITERAL(5, 46, 18), // "onClickRightButton"
QT_MOC_LITERAL(6, 65, 9), // "creatMenu"
QT_MOC_LITERAL(7, 75, 6) // "addBox"

    },
    "IMToolBox\0mousePressEvent\0\0QMouseEvent*\0"
    "event\0onClickRightButton\0creatMenu\0"
    "addBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IMToolBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,
       6,    0,   38,    2, 0x0a /* Public */,
       7,    0,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IMToolBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IMToolBox *_t = static_cast<IMToolBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->onClickRightButton(); break;
        case 2: _t->creatMenu(); break;
        case 3: _t->addBox(); break;
        default: ;
        }
    }
}

const QMetaObject IMToolBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IMToolBox.data,
      qt_meta_data_IMToolBox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IMToolBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IMToolBox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IMToolBox.stringdata0))
        return static_cast<void*>(const_cast< IMToolBox*>(this));
    return QWidget::qt_metacast(_clname);
}

int IMToolBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
