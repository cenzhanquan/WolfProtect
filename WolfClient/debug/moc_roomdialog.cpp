/****************************************************************************
** Meta object code from reading C++ file 'roomdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../roomdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roomdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RoomDialog_t {
    QByteArrayData data[24];
    char stringdata0[343];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoomDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoomDialog_t qt_meta_stringdata_RoomDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RoomDialog"
QT_MOC_LITERAL(1, 11, 12), // "SIG_quitRoom"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "SIG_openAudioDev"
QT_MOC_LITERAL(4, 42, 17), // "SIG_closeAudioDev"
QT_MOC_LITERAL(5, 60, 16), // "SIG_openVideoDev"
QT_MOC_LITERAL(6, 77, 17), // "SIG_closeVideoDev"
QT_MOC_LITERAL(7, 95, 11), // "SIG_setMoji"
QT_MOC_LITERAL(8, 107, 4), // "type"
QT_MOC_LITERAL(9, 112, 18), // "on_pb_quit_clicked"
QT_MOC_LITERAL(10, 131, 12), // "slot_setInfo"
QT_MOC_LITERAL(11, 144, 2), // "id"
QT_MOC_LITERAL(12, 147, 5), // "clear"
QT_MOC_LITERAL(13, 153, 19), // "on_pb_Video_clicked"
QT_MOC_LITERAL(14, 173, 19), // "on_pb_Audio_clicked"
QT_MOC_LITERAL(15, 193, 31), // "on_cbx_tuzi_currentIndexChanged"
QT_MOC_LITERAL(16, 225, 4), // "arg1"
QT_MOC_LITERAL(17, 230, 19), // "on_pb_close_clicked"
QT_MOC_LITERAL(18, 250, 17), // "slot_addVideoItem"
QT_MOC_LITERAL(19, 268, 10), // "VideoItem*"
QT_MOC_LITERAL(20, 279, 20), // "slot_removeVideoItem"
QT_MOC_LITERAL(21, 300, 18), // "slot_setBigImageID"
QT_MOC_LITERAL(22, 319, 4), // "name"
QT_MOC_LITERAL(23, 324, 18) // "slot_getBigImageID"

    },
    "RoomDialog\0SIG_quitRoom\0\0SIG_openAudioDev\0"
    "SIG_closeAudioDev\0SIG_openVideoDev\0"
    "SIG_closeVideoDev\0SIG_setMoji\0type\0"
    "on_pb_quit_clicked\0slot_setInfo\0id\0"
    "clear\0on_pb_Video_clicked\0on_pb_Audio_clicked\0"
    "on_cbx_tuzi_currentIndexChanged\0arg1\0"
    "on_pb_close_clicked\0slot_addVideoItem\0"
    "VideoItem*\0slot_removeVideoItem\0"
    "slot_setBigImageID\0name\0slot_getBigImageID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoomDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       3,    0,  102,    2, 0x06 /* Public */,
       4,    0,  103,    2, 0x06 /* Public */,
       5,    0,  104,    2, 0x06 /* Public */,
       6,    0,  105,    2, 0x06 /* Public */,
       7,    1,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  109,    2, 0x0a /* Public */,
      10,    1,  110,    2, 0x0a /* Public */,
      12,    0,  113,    2, 0x0a /* Public */,
      13,    0,  114,    2, 0x0a /* Public */,
      14,    0,  115,    2, 0x0a /* Public */,
      15,    1,  116,    2, 0x0a /* Public */,
      17,    0,  119,    2, 0x0a /* Public */,
      18,    1,  120,    2, 0x0a /* Public */,
      20,    1,  123,    2, 0x0a /* Public */,
      21,    2,  126,    2, 0x0a /* Public */,
      23,    0,  131,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   22,
    QMetaType::Int,

       0        // eod
};

void RoomDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoomDialog *_t = static_cast<RoomDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_quitRoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SIG_openAudioDev(); break;
        case 2: _t->SIG_closeAudioDev(); break;
        case 3: _t->SIG_openVideoDev(); break;
        case 4: _t->SIG_closeVideoDev(); break;
        case 5: _t->SIG_setMoji((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pb_quit_clicked(); break;
        case 7: _t->slot_setInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->clear(); break;
        case 9: _t->on_pb_Video_clicked(); break;
        case 10: _t->on_pb_Audio_clicked(); break;
        case 11: _t->on_cbx_tuzi_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_pb_close_clicked(); break;
        case 13: _t->slot_addVideoItem((*reinterpret_cast< VideoItem*(*)>(_a[1]))); break;
        case 14: _t->slot_removeVideoItem((*reinterpret_cast< VideoItem*(*)>(_a[1]))); break;
        case 15: _t->slot_setBigImageID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 16: { int _r = _t->slot_getBigImageID();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VideoItem* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VideoItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RoomDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomDialog::SIG_quitRoom)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RoomDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomDialog::SIG_openAudioDev)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RoomDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomDialog::SIG_closeAudioDev)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RoomDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomDialog::SIG_openVideoDev)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (RoomDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomDialog::SIG_closeVideoDev)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (RoomDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomDialog::SIG_setMoji)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject RoomDialog::staticMetaObject = {
    { &CustomMoveDialog::staticMetaObject, qt_meta_stringdata_RoomDialog.data,
      qt_meta_data_RoomDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RoomDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoomDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RoomDialog.stringdata0))
        return static_cast<void*>(const_cast< RoomDialog*>(this));
    return CustomMoveDialog::qt_metacast(_clname);
}

int RoomDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomMoveDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void RoomDialog::SIG_quitRoom(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RoomDialog::SIG_openAudioDev()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void RoomDialog::SIG_closeAudioDev()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void RoomDialog::SIG_openVideoDev()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void RoomDialog::SIG_closeVideoDev()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void RoomDialog::SIG_setMoji(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
