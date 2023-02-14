#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{

}

Worker::~Worker()
{
    emit WriteText(QString("Timer is Stopped"));
}

void Worker::doWork()
{
    QTimer *timer = new QTimer;

    connect(timer, &QTimer::timeout, [=]()
    {
//        qDebug() << "Thread is running: " << QThread::currentThreadId();
        emit WriteText(QString("Thread is running:"));
    });

    timer->setInterval(1000);
    timer->start();
}
