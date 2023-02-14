#include "mythread.h"

MyThread::MyThread(QObject *parent)
    : QThread{parent}
{

}

MyThread::~MyThread()
{

}

void MyThread::run()
{
    qDebug() << "Count is Starting..";

    for(int i=0; i<101; i++)
    {
        emit currentData(i);
        QThread::msleep(100);
    }

    emit Done(QString("Counting is Done:)"));
}
