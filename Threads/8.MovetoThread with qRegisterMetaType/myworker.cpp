#include "myworker.h"

MyWorker::MyWorker(QObject *parent)
    : QObject{parent}
{

}

void MyWorker::doCount()
{
    for(int i=0; i<101; i++)
    {
        QString text = QString::number(i);

        MyMetaType mt(i, "Hello: " + text);

        emit currentMetaType(mt);

        QThread::msleep(10);
    }
}
