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
    QByteArrayData data[10];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TornadoCurve_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TornadoCurve_t qt_meta_stringdata_TornadoCurve = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TornadoCurve"
QT_MOC_LITERAL(1, 13, 9), // "setHeight"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "_changeValue"
QT_MOC_LITERAL(4, 37, 18), // "setControllPoint1X"
QT_MOC_LITERAL(5, 56, 18), // "setControllPoint1Z"
QT_MOC_LITERAL(6, 75, 18), // "setControllPoint2X"
QT_MOC_LITERAL(7, 94, 18), // "setControllPoint2Z"
QT_MOC_LITERAL(8, 113, 18), // "setControllPoint3X"
QT_MOC_LITERAL(9, 132, 18) // "setControllPoint3Z"

    },
    "TornadoCurve\0setHeight\0\0_changeValue\0"
    "setControllPoint1X\0setControllPoint1Z\0"
    "setControllPoint2X\0setControllPoint2Z\0"
    "setControllPoint3X\0setControllPoint3Z"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TornadoCurve[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    1,   52,    2, 0x0a /* Public */,
       5,    1,   55,    2, 0x0a /* Public */,
       6,    1,   58,    2, 0x0a /* Public */,
       7,    1,   61,    2, 0x0a /* Public */,
       8,    1,   64,    2, 0x0a /* Public */,
       9,    1,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void TornadoCurve::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TornadoCurve *_t = static_cast<TornadoCurve *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setHeight((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->setControllPoint1X((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setControllPoint1Z((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setControllPoint2X((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setControllPoint2Z((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setControllPoint3X((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setControllPoint3Z((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
