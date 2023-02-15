#include "myrunnable.h"

MyRunnable::MyRunnable(QObject *parent)
    : QObject{parent}
{

}

void MyRunnable::run()
{
    for(int i=20; i>0; i--)
    {
        emit sendMessage(i);

        QThread::msleep(1000);
    }
}
