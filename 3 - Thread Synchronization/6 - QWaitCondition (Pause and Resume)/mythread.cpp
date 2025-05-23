#include "mythread.h"

myThread::myThread(QObject *parent)
    : QThread{parent}
{
    m_pause = true;
}

void myThread::pause()
{
    qDebug() << "Pause method running in: " << QThread::currentThread();

    emit openMessageBox();

    m_mutex.lock();

    m_pause = true;

    m_mutex.unlock();
}

void myThread::resume()
{
    qDebug() << "Resume method running in: " << QThread::currentThread();

    m_mutex.lock();

    m_pause = false;

    m_mutex.unlock();

    w_condition.wakeAll();
}

void myThread::run()
{
    qDebug() << "Thread is: " << QThread::currentThread();

    for(int i=0; i<101; i++)
    {
        m_mutex.lock();

        if(m_pause)
        {
            w_condition.wait(&m_mutex);
        }

        m_mutex.unlock();

        emit setProgressbar(i);

        msleep(100);
    }
}
