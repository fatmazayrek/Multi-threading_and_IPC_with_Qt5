#include "mythread.h"

MyThread::MyThread(QObject *parent)
    : QThread{parent}
{
    qDebug() << "Thread constructor..";
}

MyThread::~MyThread()
{
    qDebug() << "Thread deconstructor..";
}

void MyThread::run()
{
    QTimer *timer = new QTimer;

    connect(timer, &QTimer::timeout, [=]()
    {
        emit writeText(QString("Thread is Running.."));
    });

    timer->setInterval(1000);
    timer->start();

    exec();
}
