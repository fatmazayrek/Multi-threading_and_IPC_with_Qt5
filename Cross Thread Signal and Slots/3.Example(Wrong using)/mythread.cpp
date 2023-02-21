#include "mythread.h"

myThread::myThread(QObject *parent)
    : QThread{parent},
      m_counter(0)
{
    qDebug() << "This is Thread Constructor: " << QThread::currentThread();
}

void myThread::run()
{
    qDebug() << "Run thread is: " << QThread::currentThread();

    m_timer = new QTimer();

    connect(m_timer, &QTimer::timeout, this, &myThread::increment);

    m_timer->setInterval(1000);

    m_timer->start();

    exec();   //You must write it.
}

void myThread::increment()
{
    qDebug() << "Increment thread is: " << QThread::currentThread();

    m_counter++;

    if(m_counter == 7)
    {
        m_timer->stop();   //This is so wrong. Because you try stop the timer from another thread
        thread()->quit();
    }

    emit sendData(m_counter);
    emit openWindow();
}
