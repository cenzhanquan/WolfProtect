/****************************************************************************
** Meta object code from reading C++ file 'customwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../uiapi/customwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CustomMoveWidget_t {
    QByteArrayData data[5];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomMoveWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomMoveWidget_t qt_meta_stringdata_CustomMoveWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CustomMoveWidget"
QT_MOC_LITERAL(1, 17, 12), // "slot_showMax"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "slot_showMin"
QT_MOC_LITERAL(4, 44, 10) // "slot_close"

    },
    "CustomMoveWidget\0slot_showMax\0\0"
    "slot_showMin\0slot_close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomMoveWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CustomMoveWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustomMoveWidget *_t = static_cast<CustomMoveWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_showMax(); break;
        case 1: _t->slot_showMin(); break;
        case 2: _t->slot_close(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CustomMoveWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CustomMoveWidget.data,
      qt_meta_data_CustomMoveWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CustomMoveWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomMoveWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CustomMoveWidget.stringdata0))
        return static_cast<void*>(const_cast< CustomMoveWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CustomMoveWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_CustomMoveDialog_t {
    QByteArrayData data[5];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomMoveDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomMoveDialog_t qt_meta_stringdata_CustomMoveDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CustomMoveDialog"
QT_MOC_LITERAL(1, 17, 12), // "slot_showMax"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "slot_showMin"
QT_MOC_LITERAL(4, 44, 10) // "slot_close"

    },
    "CustomMoveDialog\0slot_showMax\0\0"
    "slot_showMin\0slot_close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomMoveDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CustomMoveDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustomMoveDialog *_t = static_cast<CustomMoveDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_showMax(); break;
        case 1: _t->slot_showMin(); break;
        case 2: _t->slot_close(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CustomMoveDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CustomMoveDialog.data,
      qt_meta_data_CustomMoveDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CustomMoveDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomMoveDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CustomMoveDialog.stringdata0))
        return static_cast<void*>(const_cast< CustomMoveDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CustomMoveDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_CustomMoveMainWindow_t {
    QByteArrayData data[5];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomMoveMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomMoveMainWindow_t qt_meta_stringdata_CustomMoveMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 20), // "CustomMoveMainWindow"
QT_MOC_LITERAL(1, 21, 12), // "slot_showMax"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 12), // "slot_showMin"
QT_MOC_LITERAL(4, 48, 10) // "slot_close"

    },
    "CustomMoveMainWindow\0slot_showMax\0\0"
    "slot_showMin\0slot_close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomMoveMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CustomMoveMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustomMoveMainWindow *_t = static_cast<CustomMoveMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_showMax(); break;
        case 1: _t->slot_showMin(); break;
        case 2: _t->slot_close(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CustomMoveMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CustomMoveMainWindow.data,
      qt_meta_data_CustomMoveMainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CustomMoveMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomMoveMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CustomMoveMainWindow.stringdata0))
        return static_cast<void*>(const_cast< CustomMoveMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CustomMoveMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
