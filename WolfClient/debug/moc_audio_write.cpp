/****************************************************************************
** Meta object code from reading C++ file 'audio_write.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RecordAudio/audio_write.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audio_write.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Audio_Write_t {
    QByteArrayData data[8];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Audio_Write_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Audio_Write_t qt_meta_stringdata_Audio_Write = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Audio_Write"
QT_MOC_LITERAL(1, 12, 15), // "finishedPlaying"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "QAudio::State"
QT_MOC_LITERAL(4, 43, 5), // "state"
QT_MOC_LITERAL(5, 49, 11), // "slot_net_rx"
QT_MOC_LITERAL(6, 61, 4), // "data"
QT_MOC_LITERAL(7, 66, 7) // "update2"

    },
    "Audio_Write\0finishedPlaying\0\0QAudio::State\0"
    "state\0slot_net_rx\0data\0update2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Audio_Write[] = {

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
       1,    1,   29,    2, 0x0a /* Public */,
       5,    1,   32,    2, 0x0a /* Public */,
       7,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,

       0        // eod
};

void Audio_Write::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Audio_Write *_t = static_cast<Audio_Write *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finishedPlaying((*reinterpret_cast< QAudio::State(*)>(_a[1]))); break;
        case 1: _t->slot_net_rx((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->update2(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudio::State >(); break;
            }
            break;
        }
    }
}

const QMetaObject Audio_Write::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Audio_Write.data,
      qt_meta_data_Audio_Write,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Audio_Write::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Audio_Write::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Audio_Write.stringdata0))
        return static_cast<void*>(const_cast< Audio_Write*>(this));
    return QObject::qt_metacast(_clname);
}

int Audio_Write::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
