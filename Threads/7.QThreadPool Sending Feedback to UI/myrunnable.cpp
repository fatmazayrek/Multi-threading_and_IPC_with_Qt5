#include "myrunnable.h"

MyRunnable::MyRunnable(QObject *parent)
    : QObject{parent}, m_receiver(parent)
{

}

void MyRunnable::run()
{
    for(int i=20; i>0; i--)
    {
        QMetaObject::invokeMethod(m_receiver, "gotUpdate", Qt::QueuedConnection, Q_ARG(int, i));

        QThread::msleep(1000);
    }
}
