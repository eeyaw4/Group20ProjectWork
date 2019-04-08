/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[373];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "on_slideR_valueChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "position"
QT_MOC_LITERAL(4, 44, 22), // "on_slideG_valueChanged"
QT_MOC_LITERAL(5, 67, 22), // "on_slideB_valueChanged"
QT_MOC_LITERAL(6, 90, 24), // "on_loadSTLButton_clicked"
QT_MOC_LITERAL(7, 115, 26), // "on_loadModelButton_clicked"
QT_MOC_LITERAL(8, 142, 28), // "on_resetColourButton_clicked"
QT_MOC_LITERAL(9, 171, 21), // "on_spinR_valueChanged"
QT_MOC_LITERAL(10, 193, 4), // "arg1"
QT_MOC_LITERAL(11, 198, 21), // "on_spinG_valueChanged"
QT_MOC_LITERAL(12, 220, 21), // "on_spinB_valueChanged"
QT_MOC_LITERAL(13, 242, 25), // "on_btnModelColour_clicked"
QT_MOC_LITERAL(14, 268, 22), // "on_btnBGColour_clicked"
QT_MOC_LITERAL(15, 291, 23), // "on_checkCS_stateChanged"
QT_MOC_LITERAL(16, 315, 29), // "on_slideShrink_sliderReleased"
QT_MOC_LITERAL(17, 345, 27) // "on_checkShrink_stateChanged"

    },
    "MainWindow\0on_slideR_valueChanged\0\0"
    "position\0on_slideG_valueChanged\0"
    "on_slideB_valueChanged\0on_loadSTLButton_clicked\0"
    "on_loadModelButton_clicked\0"
    "on_resetColourButton_clicked\0"
    "on_spinR_valueChanged\0arg1\0"
    "on_spinG_valueChanged\0on_spinB_valueChanged\0"
    "on_btnModelColour_clicked\0"
    "on_btnBGColour_clicked\0on_checkCS_stateChanged\0"
    "on_slideShrink_sliderReleased\0"
    "on_checkShrink_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       4,    1,   87,    2, 0x08 /* Private */,
       5,    1,   90,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    1,   96,    2, 0x08 /* Private */,
      11,    1,   99,    2, 0x08 /* Private */,
      12,    1,  102,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    1,  107,    2, 0x08 /* Private */,
      16,    0,  110,    2, 0x08 /* Private */,
      17,    1,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_slideR_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_slideG_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_slideB_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_loadSTLButton_clicked(); break;
        case 4: _t->on_loadModelButton_clicked(); break;
        case 5: _t->on_resetColourButton_clicked(); break;
        case 6: _t->on_spinR_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_spinG_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_spinB_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_btnModelColour_clicked(); break;
        case 10: _t->on_btnBGColour_clicked(); break;
        case 11: _t->on_checkCS_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_slideShrink_sliderReleased(); break;
        case 13: _t->on_checkShrink_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
