#pragma once

#include <QCoreApplication>
#include <QObject>
#include <QDebug>

class MainClass : public QObject
{
    Q_OBJECT
public:
    MainClass(QObject *parent);
private:
    void write();
    void read();
};
