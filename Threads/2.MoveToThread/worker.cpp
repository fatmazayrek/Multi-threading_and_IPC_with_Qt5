#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{

}

Worker::~Worker()
{
    qDebug() << "Worker destroyed, destructor running in thread : " << QThread::currentThread();
}


void Worker::counting()
{
    qDebug() << " Counting is starting..";

    for(int i=0; i<101; i++)
    {
        emit currentValue(i);
    }

    emit Done(QString("Counting is done:)"));
}
