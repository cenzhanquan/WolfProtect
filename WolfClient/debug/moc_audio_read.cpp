/****************************************************************************
** Meta object code from reading C++ file 'audio_read.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RecordAudio/audio_read.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audio_read.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Audio_Read_t {
    QByteArrayData data[8];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Audio_Read_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Audio_Read_t qt_meta_stringdata_Audio_Read = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Audio_Read"
QT_MOC_LITERAL(1, 11, 16), // "sig_net_tx_frame"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "frame"
QT_MOC_LITERAL(4, 35, 8), // "readMore"
QT_MOC_LITERAL(5, 44, 10), // "PauseAudio"
QT_MOC_LITERAL(6, 55, 11), // "ResumeAudio"
QT_MOC_LITERAL(7, 67, 6) // "UnInit"

    },
    "Audio_Read\0sig_net_tx_frame\0\0frame\0"
    "readMore\0PauseAudio\0ResumeAudio\0UnInit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Audio_Read[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Audio_Read::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Audio_Read *_t = static_cast<Audio_Read *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_net_tx_frame((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->readMore(); break;
        case 2: _t->PauseAudio(); break;
        case 3: _t->ResumeAudio(); break;
        case 4: _t->UnInit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Audio_Read::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Audio_Read::sig_net_tx_frame)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Audio_Read::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Audio_Read.data,
      qt_meta_data_Audio_Read,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Audio_Read::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Audio_Read::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Audio_Read.stringdata0))
        return static_cast<void*>(const_cast< Audio_Read*>(this));
    return QObject::qt_metacast(_clname);
}

int Audio_Read::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Audio_Read::sig_net_tx_frame(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
