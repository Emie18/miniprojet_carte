/****************************************************************************
** Meta object code from reading C++ file 'GrandeVue.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GrandeVue.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GrandeVue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GrandeVue_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GrandeVue_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GrandeVue_t qt_meta_stringdata_GrandeVue = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GrandeVue"
QT_MOC_LITERAL(1, 10, 14), // "coord_viewport"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8) // "position"

    },
    "GrandeVue\0coord_viewport\0\0position"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GrandeVue[] = {

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
       1,    1,   24,    2, 0x06 /* Public */,
       3,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QRectF,    2,
    QMetaType::Void, QMetaType::QPointF,    2,

       0        // eod
};

void GrandeVue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GrandeVue *_t = static_cast<GrandeVue *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->coord_viewport((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 1: _t->position((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GrandeVue::*_t)(QRectF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GrandeVue::coord_viewport)) {
                *result = 0;
            }
        }
        {
            typedef void (GrandeVue::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GrandeVue::position)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject GrandeVue::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_GrandeVue.data,
      qt_meta_data_GrandeVue,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GrandeVue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GrandeVue::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GrandeVue.stringdata0))
        return static_cast<void*>(const_cast< GrandeVue*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int GrandeVue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
void GrandeVue::coord_viewport(QRectF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GrandeVue::position(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
