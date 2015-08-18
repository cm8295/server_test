/****************************************************************************
** Meta object code from reading C++ file 'tcpthread.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tcpthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   11,   10,   10, 0x05,
      57,   54,   10,   10, 0x05,
      89,   10,   10,   10, 0x05,
     108,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     132,   10,   10,   10, 0x0a,
     155,  146,   10,   10, 0x0a,
     184,   11,   10,   10, 0x0a,
     227,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TcpThread[] = {
    "TcpThread\0\0socketError\0"
    "error(QTcpSocket::SocketError)\0,,\0"
    "bytesArrived(qint64,qint32,int)\0"
    "sendtransferinfo()\0disconnectedSignal(int)\0"
    "receiveData()\0numBytes\0"
    "updateClientProgress(qint64)\0"
    "displayError(QAbstractSocket::SocketError)\0"
    "connectError()\0"
};

void TcpThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TcpThread *_t = static_cast<TcpThread *>(_o);
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->bytesArrived((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint32(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->sendtransferinfo(); break;
        case 3: _t->disconnectedSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->receiveData(); break;
        case 5: _t->updateClientProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: _t->connectError(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TcpThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TcpThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_TcpThread,
      qt_meta_data_TcpThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpThread))
        return static_cast<void*>(const_cast< TcpThread*>(this));
    return QThread::qt_metacast(_clname);
}

int TcpThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TcpThread::error(QTcpSocket::SocketError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpThread::bytesArrived(qint64 _t1, qint32 _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpThread::sendtransferinfo()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void TcpThread::disconnectedSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
