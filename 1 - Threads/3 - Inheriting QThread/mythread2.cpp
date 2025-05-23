#include "mythread2.h"

MyThread2::MyThread2(QObject *parent)
    : QThread{parent}
{

}

void MyThread2::run()
{
    qDebug << "Dial is starting..";

    for(int i=0; i<201; i++)
    {
        emit currentData(i);
        QThread::msleep(100);
    }
}
