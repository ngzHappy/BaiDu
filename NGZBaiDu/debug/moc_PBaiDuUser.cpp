/****************************************************************************
** Meta object code from reading C++ file 'PBaiDuUser.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../private/PBaiDuUser.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PBaiDuUser.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BaiDuUserLoginNetworkAccessManager_t {
    QByteArrayData data[1];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaiDuUserLoginNetworkAccessManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaiDuUserLoginNetworkAccessManager_t qt_meta_stringdata_BaiDuUserLoginNetworkAccessManager = {
    {
QT_MOC_LITERAL(0, 0, 34) // "BaiDuUserLoginNetworkAccessMa..."

    },
    "BaiDuUserLoginNetworkAccessManager"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaiDuUserLoginNetworkAccessManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void BaiDuUserLoginNetworkAccessManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject BaiDuUserLoginNetworkAccessManager::staticMetaObject = {
    { &QNetworkAccessManager::staticMetaObject, qt_meta_stringdata_BaiDuUserLoginNetworkAccessManager.data,
      qt_meta_data_BaiDuUserLoginNetworkAccessManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BaiDuUserLoginNetworkAccessManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaiDuUserLoginNetworkAccessManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BaiDuUserLoginNetworkAccessManager.stringdata0))
        return static_cast<void*>(const_cast< BaiDuUserLoginNetworkAccessManager*>(this));
    return QNetworkAccessManager::qt_metacast(_clname);
}

int BaiDuUserLoginNetworkAccessManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNetworkAccessManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_BaiDuUserLoginPack_t {
    QByteArrayData data[3];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaiDuUserLoginPack_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaiDuUserLoginPack_t qt_meta_stringdata_BaiDuUserLoginPack = {
    {
QT_MOC_LITERAL(0, 0, 18), // "BaiDuUserLoginPack"
QT_MOC_LITERAL(1, 19, 13), // "loginFinished"
QT_MOC_LITERAL(2, 33, 0) // ""

    },
    "BaiDuUserLoginPack\0loginFinished\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaiDuUserLoginPack[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,

       0        // eod
};

void BaiDuUserLoginPack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BaiDuUserLoginPack *_t = static_cast<BaiDuUserLoginPack *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loginFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BaiDuUserLoginPack::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BaiDuUserLoginPack::loginFinished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject BaiDuUserLoginPack::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BaiDuUserLoginPack.data,
      qt_meta_data_BaiDuUserLoginPack,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BaiDuUserLoginPack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaiDuUserLoginPack::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BaiDuUserLoginPack.stringdata0))
        return static_cast<void*>(const_cast< BaiDuUserLoginPack*>(this));
    if (!strcmp(_clname, "BaiDuFinishedCallBack"))
        return static_cast< BaiDuFinishedCallBack*>(const_cast< BaiDuUserLoginPack*>(this));
    return QObject::qt_metacast(_clname);
}

int BaiDuUserLoginPack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void BaiDuUserLoginPack::loginFinished(bool _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_BaiDuUser__BaiDuUserPrivate_t {
    QByteArrayData data[8];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaiDuUser__BaiDuUserPrivate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaiDuUser__BaiDuUserPrivate_t qt_meta_stringdata_BaiDuUser__BaiDuUserPrivate = {
    {
QT_MOC_LITERAL(0, 0, 27), // "BaiDuUser::BaiDuUserPrivate"
QT_MOC_LITERAL(1, 28, 13), // "loginFinished"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 5), // "login"
QT_MOC_LITERAL(4, 49, 8), // "userName"
QT_MOC_LITERAL(5, 58, 8), // "passWord"
QT_MOC_LITERAL(6, 67, 16), // "BaiDuVertifyCode"
QT_MOC_LITERAL(7, 84, 11) // "vertifyCode"

    },
    "BaiDuUser::BaiDuUserPrivate\0loginFinished\0"
    "\0login\0userName\0passWord\0BaiDuVertifyCode\0"
    "vertifyCode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaiDuUser__BaiDuUserPrivate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   29,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 6,    4,    5,    7,

       0        // eod
};

void BaiDuUser::BaiDuUserPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BaiDuUserPrivate *_t = static_cast<BaiDuUserPrivate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loginFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->login((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< BaiDuVertifyCode(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BaiDuUserPrivate::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BaiDuUserPrivate::loginFinished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject BaiDuUser::BaiDuUserPrivate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BaiDuUser__BaiDuUserPrivate.data,
      qt_meta_data_BaiDuUser__BaiDuUserPrivate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BaiDuUser::BaiDuUserPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaiDuUser::BaiDuUserPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BaiDuUser__BaiDuUserPrivate.stringdata0))
        return static_cast<void*>(const_cast< BaiDuUserPrivate*>(this));
    return QObject::qt_metacast(_clname);
}

int BaiDuUser::BaiDuUserPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void BaiDuUser::BaiDuUserPrivate::loginFinished(bool _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
