#include "myworker.h"

MyWorker::MyWorker(int number, QMutex *mutex, bool *stop, QObject *parent)
    : m_number(number), m_mutex(mutex), m_stop(stop)
{

}

void MyWorker::run()
{
    QMutexLocker locker(m_mutex);

    for(int i=0; i<10; i++)
    {
        m_number++;

        emit emitNumber(QString::number(m_number));

        QThread::msleep(100);
    }
}
