/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Indi-Cosmos/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[36];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 27), // "on_boolpanelderecho_changed"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 24), // "on_actionSalir_triggered"
QT_MOC_LITERAL(65, 28), // "on_boolpanelsuperior_changed"
QT_MOC_LITERAL(94, 24), // "on_Nobjetos_valueChanged"
QT_MOC_LITERAL(119, 4), // "arg1"
QT_MOC_LITERAL(124, 15), // "botones_clicked"
QT_MOC_LITERAL(140, 7), // "limpiar"
QT_MOC_LITERAL(148, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(173, 8), // "repintar"
QT_MOC_LITERAL(182, 18), // "MostrarPropiedades"
QT_MOC_LITERAL(201, 11), // "resizeEvent"
QT_MOC_LITERAL(213, 13), // "QResizeEvent*"
QT_MOC_LITERAL(227, 13), // "indexofdevice"
QT_MOC_LITERAL(241, 6), // "string"
QT_MOC_LITERAL(248, 2), // "id"
QT_MOC_LITERAL(251, 19) // "on_Conectar_clicked"

    },
    "MainWindow\0on_boolpanelderecho_changed\0"
    "\0on_actionSalir_triggered\0"
    "on_boolpanelsuperior_changed\0"
    "on_Nobjetos_valueChanged\0arg1\0"
    "botones_clicked\0limpiar\0"
    "on_checkBox_stateChanged\0repintar\0"
    "MostrarPropiedades\0resizeEvent\0"
    "QResizeEvent*\0indexofdevice\0string\0"
    "id\0on_Conectar_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    0,   88,    2, 0x08,    3 /* Private */,
       5,    1,   89,    2, 0x08,    4 /* Private */,
       7,    0,   92,    2, 0x08,    6 /* Private */,
       8,    0,   93,    2, 0x08,    7 /* Private */,
       9,    1,   94,    2, 0x08,    8 /* Private */,
      10,    0,   97,    2, 0x08,   10 /* Private */,
      11,    0,   98,    2, 0x08,   11 /* Private */,
      12,    1,   99,    2, 0x08,   12 /* Private */,
      14,    1,  102,    2, 0x08,   14 /* Private */,
      17,    0,  105,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Int, 0x80000000 | 15,   16,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_boolpanelderecho_changed(); break;
        case 1: _t->on_actionSalir_triggered(); break;
        case 2: _t->on_boolpanelsuperior_changed(); break;
        case 3: _t->on_Nobjetos_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->botones_clicked(); break;
        case 5: _t->limpiar(); break;
        case 6: _t->on_checkBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->repintar(); break;
        case 8: _t->MostrarPropiedades(); break;
        case 9: _t->resizeEvent((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        case 10: { int _r = _t->indexofdevice((*reinterpret_cast< std::add_pointer_t<string>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->on_Conectar_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
