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
    QByteArrayData data[16];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NGL_Context_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NGL_Context_t qt_meta_stringdata_NGL_Context = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NGL_Context"
QT_MOC_LITERAL(1, 12, 11), // "renderOnOff"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 18), // "changeParticleSize"
QT_MOC_LITERAL(4, 44, 5), // "value"
QT_MOC_LITERAL(5, 50, 20), // "changeParticleSubSys"
QT_MOC_LITERAL(6, 71, 9), // "setTexure"
QT_MOC_LITERAL(7, 81, 11), // "_texureName"
QT_MOC_LITERAL(8, 93, 8), // "rotateUp"
QT_MOC_LITERAL(9, 102, 10), // "rotateDown"
QT_MOC_LITERAL(10, 113, 4), // "left"
QT_MOC_LITERAL(11, 118, 5), // "right"
QT_MOC_LITERAL(12, 124, 2), // "up"
QT_MOC_LITERAL(13, 127, 4), // "down"
QT_MOC_LITERAL(14, 132, 6), // "zoomIn"
QT_MOC_LITERAL(15, 139, 7) // "zoomOut"

    },
    "NGL_Context\0renderOnOff\0\0changeParticleSize\0"
    "value\0changeParticleSubSys\0setTexure\0"
    "_texureName\0rotateUp\0rotateDown\0left\0"
    "right\0up\0down\0zoomIn\0zoomOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NGL_Context[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    1,   75,    2, 0x0a /* Public */,
       5,    1,   78,    2, 0x0a /* Public */,
       6,    1,   81,    2, 0x0a /* Public */,
       8,    0,   84,    2, 0x0a /* Public */,
       9,    0,   85,    2, 0x0a /* Public */,
      10,    0,   86,    2, 0x0a /* Public */,
      11,    0,   87,    2, 0x0a /* Public */,
      12,    0,   88,    2, 0x0a /* Public */,
      13,    0,   89,    2, 0x0a /* Public */,
      14,    0,   90,    2, 0x0a /* Public */,
      15,    0,   91,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QString,    7,
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
        case 0: _t->renderOnOff(); break;
        case 1: _t->changeParticleSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeParticleSubSys((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setTexure((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->rotateUp(); break;
        case 5: _t->rotateDown(); break;
        case 6: _t->left(); break;
        case 7: _t->right(); break;
        case 8: _t->up(); break;
        case 9: _t->down(); break;
        case 10: _t->zoomIn(); break;
        case 11: _t->zoomOut(); break;
        default: ;
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
QT_END_MOC_NAMESPACE
