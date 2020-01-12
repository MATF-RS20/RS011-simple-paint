/****************************************************************************
** Meta object code from reading C++ file 'image.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SimplePaint/headers/image.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'image.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_image_t {
    QByteArrayData data[21];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_image_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_image_t qt_meta_stringdata_image = {
    {
QT_MOC_LITERAL(0, 0, 5), // "image"
QT_MOC_LITERAL(1, 6, 13), // "activatedUndo"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "clearImage"
QT_MOC_LITERAL(4, 32, 12), // "setToolColor"
QT_MOC_LITERAL(5, 45, 13), // "setBrushWidth"
QT_MOC_LITERAL(6, 59, 7), // "setTool"
QT_MOC_LITERAL(7, 67, 10), // "nameOfTool"
QT_MOC_LITERAL(8, 78, 9), // "openImage"
QT_MOC_LITERAL(9, 88, 8), // "fileName"
QT_MOC_LITERAL(10, 97, 11), // "saveAsImage"
QT_MOC_LITERAL(11, 109, 8), // "filename"
QT_MOC_LITERAL(12, 118, 11), // "const char*"
QT_MOC_LITERAL(13, 130, 10), // "fileFormat"
QT_MOC_LITERAL(14, 141, 10), // "needToCrop"
QT_MOC_LITERAL(15, 152, 16), // "scaleImageZoomIn"
QT_MOC_LITERAL(16, 169, 17), // "scaleImageZoomOut"
QT_MOC_LITERAL(17, 187, 8), // "undoFunc"
QT_MOC_LITERAL(18, 196, 8), // "redoFunc"
QT_MOC_LITERAL(19, 205, 8), // "newSheet"
QT_MOC_LITERAL(20, 214, 16) // "resizeCurrentImg"

    },
    "image\0activatedUndo\0\0clearImage\0"
    "setToolColor\0setBrushWidth\0setTool\0"
    "nameOfTool\0openImage\0fileName\0saveAsImage\0"
    "filename\0const char*\0fileFormat\0"
    "needToCrop\0scaleImageZoomIn\0"
    "scaleImageZoomOut\0undoFunc\0redoFunc\0"
    "newSheet\0resizeCurrentImg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_image[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    1,   88,    2, 0x0a /* Public */,
       8,    1,   91,    2, 0x0a /* Public */,
      10,    2,   94,    2, 0x0a /* Public */,
      14,    0,   99,    2, 0x0a /* Public */,
      15,    0,  100,    2, 0x0a /* Public */,
      16,    0,  101,    2, 0x0a /* Public */,
      17,    0,  102,    2, 0x0a /* Public */,
      18,    0,  103,    2, 0x0a /* Public */,
      19,    0,  104,    2, 0x0a /* Public */,
      20,    0,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Bool, QMetaType::QString,    9,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 12,   11,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void image::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<image *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activatedUndo(); break;
        case 1: _t->clearImage(); break;
        case 2: _t->setToolColor(); break;
        case 3: _t->setBrushWidth(); break;
        case 4: _t->setTool((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: { bool _r = _t->openImage((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->saveAsImage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->needToCrop(); break;
        case 8: _t->scaleImageZoomIn(); break;
        case 9: _t->scaleImageZoomOut(); break;
        case 10: _t->undoFunc(); break;
        case 11: _t->redoFunc(); break;
        case 12: _t->newSheet(); break;
        case 13: _t->resizeCurrentImg(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (image::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&image::activatedUndo)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject image::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_image.data,
    qt_meta_data_image,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *image::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *image::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_image.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int image::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void image::activatedUndo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
