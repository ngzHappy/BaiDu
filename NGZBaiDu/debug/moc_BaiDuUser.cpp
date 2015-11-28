/****************************************************************************
** Meta object code from reading C++ file 'BaiDuUser.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BaiDuUser.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BaiDuUser.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BaiDuUser_t {
    QByteArrayData data[8];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaiDuUser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaiDuUser_t qt_meta_stringdata_BaiDuUser = {
    {
QT_MOC_LITERAL(0, 0, 9), // "BaiDuUser"
QT_MOC_LITERAL(1, 10, 5), // "login"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 8), // "userName"
QT_MOC_LITERAL(4, 26, 8), // "passWord"
QT_MOC_LITERAL(5, 35, 16), // "BaiDuVertifyCode"
QT_MOC_LITERAL(6, 52, 11), // "vertifyCode"
QT_MOC_LITERAL(7, 64, 13) // "loginFinished"

    },
    "BaiDuUser\0login\0\0userName\0passWord\0"
    "BaiDuVertifyCode\0vertifyCode\0loginFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaiDuUser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x06 /* Public */,
       7,    2,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,

       0        // eod
};

void BaiDuUser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BaiDuUser *_t = static_cast<BaiDuUser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->login((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< BaiDuVertifyCode(*)>(_a[3]))); break;
        case 1: _t->loginFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BaiDuUser::*_t)(QString , QString , BaiDuVertifyCode );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BaiDuUser::login)) {
                *result = 0;
            }
        }
        {
            typedef void (BaiDuUser::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BaiDuUser::loginFinished)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject BaiDuUser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BaiDuUser.data,
      qt_meta_data_BaiDuUser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BaiDuUser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaiDuUser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BaiDuUser.stringdata0))
        return static_cast<void*>(const_cast< BaiDuUser*>(this));
    return QObject::qt_metacast(_clname);
}

int BaiDuUser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void BaiDuUser::login(QString _t1, QString _t2, BaiDuVertifyCode _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BaiDuUser::loginFinished(bool _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
