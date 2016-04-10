/****************************************************************************
** Meta object code from reading C++ file 'NGL_Context.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/NGL_Context.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NGL_Context.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NGL_Context_t {
    QByteArrayData data[20];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NGL_Context_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NGL_Context_t qt_meta_stringdata_NGL_Context = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NGL_Context"
QT_MOC_LITERAL(1, 12, 17), // "resetParticleSize"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "_newValue"
QT_MOC_LITERAL(4, 41, 20), // "resetParticleSysSize"
QT_MOC_LITERAL(5, 62, 11), // "resetTexure"
QT_MOC_LITERAL(6, 74, 11), // "renderOnOff"
QT_MOC_LITERAL(7, 86, 18), // "changeParticleSize"
QT_MOC_LITERAL(8, 105, 5), // "value"
QT_MOC_LITERAL(9, 111, 20), // "changeParticleSubSys"
QT_MOC_LITERAL(10, 132, 9), // "setTexure"
QT_MOC_LITERAL(11, 142, 11), // "_texureName"
QT_MOC_LITERAL(12, 154, 8), // "rotateUp"
QT_MOC_LITERAL(13, 163, 10), // "rotateDown"
QT_MOC_LITERAL(14, 174, 4), // "left"
QT_MOC_LITERAL(15, 179, 5), // "right"
QT_MOC_LITERAL(16, 185, 2), // "up"
QT_MOC_LITERAL(17, 188, 4), // "down"
QT_MOC_LITERAL(18, 193, 6), // "zoomIn"
QT_MOC_LITERAL(19, 200, 7) // "zoomOut"

    },
    "NGL_Context\0resetParticleSize\0\0_newValue\0"
    "resetParticleSysSize\0resetTexure\0"
    "renderOnOff\0changeParticleSize\0value\0"
    "changeParticleSubSys\0setTexure\0"
    "_texureName\0rotateUp\0rotateDown\0left\0"
    "right\0up\0down\0zoomIn\0zoomOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NGL_Context[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       5,    1,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   98,    2, 0x0a /* Public */,
       7,    1,   99,    2, 0x0a /* Public */,
       9,    1,  102,    2, 0x0a /* Public */,
      10,    1,  105,    2, 0x0a /* Public */,
      12,    0,  108,    2, 0x0a /* Public */,
      13,    0,  109,    2, 0x0a /* Public */,
      14,    0,  110,    2, 0x0a /* Public */,
      15,    0,  111,    2, 0x0a /* Public */,
      16,    0,  112,    2, 0x0a /* Public */,
      17,    0,  113,    2, 0x0a /* Public */,
      18,    0,  114,    2, 0x0a /* Public */,
      19,    0,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NGL_Context::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NGL_Context *_t = static_cast<NGL_Context *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resetParticleSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->resetParticleSysSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->resetTexure((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->renderOnOff(); break;
        case 4: _t->changeParticleSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->changeParticleSubSys((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setTexure((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->rotateUp(); break;
        case 8: _t->rotateDown(); break;
        case 9: _t->left(); break;
        case 10: _t->right(); break;
        case 11: _t->up(); break;
        case 12: _t->down(); break;
        case 13: _t->zoomIn(); break;
        case 14: _t->zoomOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NGL_Context::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NGL_Context::resetParticleSize)) {
                *result = 0;
            }
        }
        {
            typedef void (NGL_Context::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NGL_Context::resetParticleSysSize)) {
                *result = 1;
            }
        }
        {
            typedef void (NGL_Context::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NGL_Context::resetTexure)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject NGL_Context::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_NGL_Context.data,
      qt_meta_data_NGL_Context,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NGL_Context::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NGL_Context::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NGL_Context.stringdata0))
        return static_cast<void*>(const_cast< NGL_Context*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int NGL_Context::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void NGL_Context::resetParticleSize(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NGL_Context::resetParticleSysSize(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NGL_Context::resetTexure(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
