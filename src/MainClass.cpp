// error because of __attribute__((packed))
// if you remove it then error will disappear...
// error: cannot bind packed field ‘obj.my_struct::a’ to ‘quint32&’ {aka ‘unsigned int&’}

#include "MainClass.h"
#include <QFile>

typedef struct __attribute__((packed)) my_struct{
    my_struct(const quint32 my_a):a{my_a}{};
    my_struct(){};
    quint32 a{};
}my_struct_t;

void MainClass::write(){
    my_struct_t obj(32);
    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file); // we will serialize the data into the file
    out << (quint32)32; // serialize a quint32 value
}

void MainClass::read(){
    my_struct_t obj;
    QFile file("file.dat");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file); // read the data serialized from the file
    in.startTransaction();
    in >> obj.a; // extract
    if(in.commitTransaction()){
        qDebug().noquote().nospace() << "read is ok";
    }else{
        qDebug().noquote().nospace() << "unknown error";
    }
    qDebug().noquote().nospace() << "obj.a=" << obj.a;
}

MainClass::MainClass(QObject *parent)
    : QObject(parent)
{
    write();
    read();
}
