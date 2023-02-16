#include "myworker.h"

MyWorker::MyWorker(int number, QMutex *mutex, bool *stop, QObject *parent):
    m_number(number), mutex(mutex), m_stop(stop), QThread(parent)
{

}

MyWorker::~MyWorker()
{

}

void MyWorker::run()
{
    QMutexLocker locker(mutex); //When you put this mutex, you block other threads.

    for(int i=0; i<10; i++)
    {
        m_number++;

        emit writeNumber(QString::number(m_number));

        QThread::msleep(1000);
    }
}
