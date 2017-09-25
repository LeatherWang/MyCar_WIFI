/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[39];
    char stringdata0[733];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "readTCPMessage"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 29), // "on_pushButton_linkTCP_clicked"
QT_MOC_LITERAL(4, 57, 29), // "on_pushButton_sendTCP_clicked"
QT_MOC_LITERAL(5, 87, 31), // "on_pushButton_showScope_clicked"
QT_MOC_LITERAL(6, 119, 15), // "displayTCPError"
QT_MOC_LITERAL(7, 135, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(8, 164, 13), // "connectFinish"
QT_MOC_LITERAL(9, 178, 9), // "readMyCom"
QT_MOC_LITERAL(10, 188, 16), // "hasComDiscovered"
QT_MOC_LITERAL(11, 205, 12), // "QextPortInfo"
QT_MOC_LITERAL(12, 218, 4), // "info"
QT_MOC_LITERAL(13, 223, 13), // "hasComRemoved"
QT_MOC_LITERAL(14, 237, 38), // "on_pushButton_serialClearCoun..."
QT_MOC_LITERAL(15, 276, 40), // "on_pushButton_serialClearRece..."
QT_MOC_LITERAL(16, 317, 32), // "on_pushButton_serialSend_clicked"
QT_MOC_LITERAL(17, 350, 32), // "on_pushButton_serialOpen_clicked"
QT_MOC_LITERAL(18, 383, 37), // "on_pushButton_serialClearSend..."
QT_MOC_LITERAL(19, 421, 16), // "portName_changed"
QT_MOC_LITERAL(20, 438, 4), // "name"
QT_MOC_LITERAL(21, 443, 34), // "on_textEdit_serialSend_textCh..."
QT_MOC_LITERAL(22, 478, 33), // "on_checkBox_serialSendHex_cli..."
QT_MOC_LITERAL(23, 512, 29), // "on_pushButton_openMap_clicked"
QT_MOC_LITERAL(24, 542, 16), // "MyCarClickedSlot"
QT_MOC_LITERAL(25, 559, 1), // "x"
QT_MOC_LITERAL(26, 561, 1), // "y"
QT_MOC_LITERAL(27, 563, 1), // "z"
QT_MOC_LITERAL(28, 565, 34), // "on_pushButton_databaseOpen_cl..."
QT_MOC_LITERAL(29, 600, 35), // "on_pushButton_TCPClearCount_c..."
QT_MOC_LITERAL(30, 636, 12), // "RSSISaveSlot"
QT_MOC_LITERAL(31, 649, 5), // "index"
QT_MOC_LITERAL(32, 655, 13), // "ComputeP_S_Ri"
QT_MOC_LITERAL(33, 669, 2), // "id"
QT_MOC_LITERAL(34, 672, 6), // "float*"
QT_MOC_LITERAL(35, 679, 9), // "rssiValue"
QT_MOC_LITERAL(36, 689, 13), // "ComputeP_S_Rn"
QT_MOC_LITERAL(37, 703, 13), // "rssiValueTemp"
QT_MOC_LITERAL(38, 717, 15) // "TimerUpdateSlot"

    },
    "MainWindow\0readTCPMessage\0\0"
    "on_pushButton_linkTCP_clicked\0"
    "on_pushButton_sendTCP_clicked\0"
    "on_pushButton_showScope_clicked\0"
    "displayTCPError\0QAbstractSocket::SocketError\0"
    "connectFinish\0readMyCom\0hasComDiscovered\0"
    "QextPortInfo\0info\0hasComRemoved\0"
    "on_pushButton_serialClearCount_clicked\0"
    "on_pushButton_serialClearReceive_clicked\0"
    "on_pushButton_serialSend_clicked\0"
    "on_pushButton_serialOpen_clicked\0"
    "on_pushButton_serialClearSend_clicked\0"
    "portName_changed\0name\0"
    "on_textEdit_serialSend_textChanged\0"
    "on_checkBox_serialSendHex_clicked\0"
    "on_pushButton_openMap_clicked\0"
    "MyCarClickedSlot\0x\0y\0z\0"
    "on_pushButton_databaseOpen_clicked\0"
    "on_pushButton_TCPClearCount_clicked\0"
    "RSSISaveSlot\0index\0ComputeP_S_Ri\0id\0"
    "float*\0rssiValue\0ComputeP_S_Rn\0"
    "rssiValueTemp\0TimerUpdateSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  139,    2, 0x08 /* Private */,
       3,    0,  140,    2, 0x08 /* Private */,
       4,    0,  141,    2, 0x08 /* Private */,
       5,    0,  142,    2, 0x08 /* Private */,
       6,    1,  143,    2, 0x08 /* Private */,
       8,    0,  146,    2, 0x08 /* Private */,
       9,    0,  147,    2, 0x08 /* Private */,
      10,    1,  148,    2, 0x08 /* Private */,
      13,    1,  151,    2, 0x08 /* Private */,
      14,    0,  154,    2, 0x08 /* Private */,
      15,    0,  155,    2, 0x08 /* Private */,
      16,    0,  156,    2, 0x08 /* Private */,
      17,    0,  157,    2, 0x08 /* Private */,
      18,    0,  158,    2, 0x08 /* Private */,
      19,    1,  159,    2, 0x08 /* Private */,
      21,    0,  162,    2, 0x08 /* Private */,
      22,    0,  163,    2, 0x08 /* Private */,
      23,    0,  164,    2, 0x08 /* Private */,
      24,    3,  165,    2, 0x08 /* Private */,
      28,    0,  172,    2, 0x08 /* Private */,
      29,    0,  173,    2, 0x08 /* Private */,
      30,    1,  174,    2, 0x08 /* Private */,
      32,    2,  177,    2, 0x08 /* Private */,
      36,    1,  182,    2, 0x08 /* Private */,
      38,    0,  185,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Short, QMetaType::Short, QMetaType::Float,   25,   26,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,   31,
    QMetaType::Double, QMetaType::UShort, 0x80000000 | 34,   33,   35,
    QMetaType::Void, 0x80000000 | 34,   37,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readTCPMessage(); break;
        case 1: _t->on_pushButton_linkTCP_clicked(); break;
        case 2: _t->on_pushButton_sendTCP_clicked(); break;
        case 3: _t->on_pushButton_showScope_clicked(); break;
        case 4: _t->displayTCPError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->connectFinish(); break;
        case 6: _t->readMyCom(); break;
        case 7: _t->hasComDiscovered((*reinterpret_cast< const QextPortInfo(*)>(_a[1]))); break;
        case 8: _t->hasComRemoved((*reinterpret_cast< const QextPortInfo(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_serialClearCount_clicked(); break;
        case 10: _t->on_pushButton_serialClearReceive_clicked(); break;
        case 11: _t->on_pushButton_serialSend_clicked(); break;
        case 12: _t->on_pushButton_serialOpen_clicked(); break;
        case 13: _t->on_pushButton_serialClearSend_clicked(); break;
        case 14: _t->portName_changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->on_textEdit_serialSend_textChanged(); break;
        case 16: _t->on_checkBox_serialSendHex_clicked(); break;
        case 17: _t->on_pushButton_openMap_clicked(); break;
        case 18: _t->MyCarClickedSlot((*reinterpret_cast< qint16(*)>(_a[1])),(*reinterpret_cast< qint16(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 19: _t->on_pushButton_databaseOpen_clicked(); break;
        case 20: _t->on_pushButton_TCPClearCount_clicked(); break;
        case 21: _t->RSSISaveSlot((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 22: { double _r = _t->ComputeP_S_Ri((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< float*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 23: _t->ComputeP_S_Rn((*reinterpret_cast< float*(*)>(_a[1]))); break;
        case 24: _t->TimerUpdateSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
