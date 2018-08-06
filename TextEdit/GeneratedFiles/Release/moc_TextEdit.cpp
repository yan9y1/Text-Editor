/****************************************************************************
** Meta object code from reading C++ file 'TextEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TextEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TextEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TextEdit_t {
    QByteArrayData data[24];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextEdit_t qt_meta_stringdata_TextEdit = {
    {
QT_MOC_LITERAL(0, 0, 8), // "TextEdit"
QT_MOC_LITERAL(1, 9, 7), // "newFile"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "openFile"
QT_MOC_LITERAL(4, 27, 8), // "saveFile"
QT_MOC_LITERAL(5, 36, 10), // "saveAsFile"
QT_MOC_LITERAL(6, 47, 9), // "printFile"
QT_MOC_LITERAL(7, 57, 12), // "printPreview"
QT_MOC_LITERAL(8, 70, 4), // "exit"
QT_MOC_LITERAL(9, 75, 4), // "undo"
QT_MOC_LITERAL(10, 80, 4), // "redo"
QT_MOC_LITERAL(11, 85, 3), // "cut"
QT_MOC_LITERAL(12, 89, 4), // "copy"
QT_MOC_LITERAL(13, 94, 5), // "paste"
QT_MOC_LITERAL(14, 100, 4), // "bold"
QT_MOC_LITERAL(15, 105, 6), // "italic"
QT_MOC_LITERAL(16, 112, 9), // "underline"
QT_MOC_LITERAL(17, 122, 5), // "color"
QT_MOC_LITERAL(18, 128, 5), // "about"
QT_MOC_LITERAL(19, 134, 16), // "printPreviewSlot"
QT_MOC_LITERAL(20, 151, 9), // "QPrinter*"
QT_MOC_LITERAL(21, 161, 7), // "printer"
QT_MOC_LITERAL(22, 169, 10), // "textChange"
QT_MOC_LITERAL(23, 180, 12) // "selectChange"

    },
    "TextEdit\0newFile\0\0openFile\0saveFile\0"
    "saveAsFile\0printFile\0printPreview\0"
    "exit\0undo\0redo\0cut\0copy\0paste\0bold\0"
    "italic\0underline\0color\0about\0"
    "printPreviewSlot\0QPrinter*\0printer\0"
    "textChange\0selectChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x08 /* Private */,
       3,    0,  115,    2, 0x08 /* Private */,
       4,    0,  116,    2, 0x08 /* Private */,
       5,    0,  117,    2, 0x08 /* Private */,
       6,    0,  118,    2, 0x08 /* Private */,
       7,    0,  119,    2, 0x08 /* Private */,
       8,    0,  120,    2, 0x08 /* Private */,
       9,    0,  121,    2, 0x08 /* Private */,
      10,    0,  122,    2, 0x08 /* Private */,
      11,    0,  123,    2, 0x08 /* Private */,
      12,    0,  124,    2, 0x08 /* Private */,
      13,    0,  125,    2, 0x08 /* Private */,
      14,    0,  126,    2, 0x08 /* Private */,
      15,    0,  127,    2, 0x08 /* Private */,
      16,    0,  128,    2, 0x08 /* Private */,
      17,    0,  129,    2, 0x08 /* Private */,
      18,    0,  130,    2, 0x08 /* Private */,
      19,    1,  131,    2, 0x08 /* Private */,
      22,    0,  134,    2, 0x08 /* Private */,
      23,    0,  135,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TextEdit *_t = static_cast<TextEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newFile(); break;
        case 1: _t->openFile(); break;
        case 2: _t->saveFile(); break;
        case 3: _t->saveAsFile(); break;
        case 4: _t->printFile(); break;
        case 5: _t->printPreview(); break;
        case 6: { int _r = _t->exit();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: _t->undo(); break;
        case 8: _t->redo(); break;
        case 9: _t->cut(); break;
        case 10: _t->copy(); break;
        case 11: _t->paste(); break;
        case 12: _t->bold(); break;
        case 13: _t->italic(); break;
        case 14: _t->underline(); break;
        case 15: _t->color(); break;
        case 16: _t->about(); break;
        case 17: _t->printPreviewSlot((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        case 18: _t->textChange(); break;
        case 19: _t->selectChange(); break;
        default: ;
        }
    }
}

const QMetaObject TextEdit::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TextEdit.data,
      qt_meta_data_TextEdit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TextEdit.stringdata0))
        return static_cast<void*>(const_cast< TextEdit*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
