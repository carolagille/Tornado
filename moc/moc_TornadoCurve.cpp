/****************************************************************************
** Meta object code from reading C++ file 'TornadoCurve.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/TornadoCurve.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TornadoCurve.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TornadoCurve_t {
    QByteArrayData data[16];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TornadoCurve_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TornadoCurve_t qt_meta_stringdata_TornadoCurve = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TornadoCurve"
QT_MOC_LITERAL(1, 13, 13), // "disableCurve2"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "_state"
QT_MOC_LITERAL(4, 35, 13), // "disableCurve3"
QT_MOC_LITERAL(5, 49, 9), // "setHeight"
QT_MOC_LITERAL(6, 59, 12), // "_changeValue"
QT_MOC_LITERAL(7, 72, 18), // "setControllPoint1X"
QT_MOC_LITERAL(8, 91, 18), // "setControllPoint1Z"
QT_MOC_LITERAL(9, 110, 18), // "setControllPoint2X"
QT_MOC_LITERAL(10, 129, 18), // "setControllPoint2Z"
QT_MOC_LITERAL(11, 148, 18), // "setControllPoint3X"
QT_MOC_LITERAL(12, 167, 18), // "setControllPoint3Z"
QT_MOC_LITERAL(13, 186, 13), // "setCurveCount"
QT_MOC_LITERAL(14, 200, 15), // "setPickUpRadius"
QT_MOC_LITERAL(15, 216, 13) // "setPickUpTime"

    },
    "TornadoCurve\0disableCurve2\0\0_state\0"
    "disableCurve3\0setHeight\0_changeValue\0"
    "setControllPoint1X\0setControllPoint1Z\0"
    "setControllPoint2X\0setControllPoint2Z\0"
    "setControllPoint3X\0setControllPoint3Z\0"
    "setCurveCount\0setPickUpRadius\0"
    "setPickUpTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TornadoCurve[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   80,    2, 0x0a /* Public */,
       7,    1,   83,    2, 0x0a /* Public */,
       8,    1,   86,    2, 0x0a /* Public */,
       9,    1,   89,    2, 0x0a /* Public */,
      10,    1,   92,    2, 0x0a /* Public */,
      11,    1,   95,    2, 0x0a /* Public */,
      12,    1,   98,    2, 0x0a /* Public */,
      13,    1,  101,    2, 0x0a /* Public */,
      14,    1,  104,    2, 0x0a /* Public */,
      15,    1,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void TornadoCurve::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TornadoCurve *_t = static_cast<TornadoCurve *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disableCurve2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->disableCurve3((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setHeight((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->setControllPoint1X((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setControllPoint1Z((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setControllPoint2X((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setControllPoint2Z((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setControllPoint3X((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setControllPoint3Z((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setCurveCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setPickUpRadius((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->setPickUpTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TornadoCurve::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TornadoCurve::disableCurve2)) {
                *result = 0;
            }
        }
        {
            typedef void (TornadoCurve::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TornadoCurve::disableCurve3)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject TornadoCurve::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TornadoCurve.data,
      qt_meta_data_TornadoCurve,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TornadoCurve::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TornadoCurve::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TornadoCurve.stringdata0))
        return static_cast<void*>(const_cast< TornadoCurve*>(this));
    return QObject::qt_metacast(_clname);
}

int TornadoCurve::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void TornadoCurve::disableCurve2(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TornadoCurve::disableCurve3(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
