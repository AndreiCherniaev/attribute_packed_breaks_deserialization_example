#include <QCoreApplication>
#include "MainClass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MainClass mainClass(QCoreApplication::instance());
    QMetaObject::invokeMethod(&a, "quit", Qt::QueuedConnection);

    int ret= QCoreApplication::exec();
    return ret;
}
