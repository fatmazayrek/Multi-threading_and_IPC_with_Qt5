#include "myproducer.h"

myProducer::myProducer(QString threadId, int *buffer, int BUFFER_SIZE,
                       int *usedSlots, int totalData, QMutex *mutex,
                       QWaitCondition *buffer_Full,
                       QWaitCondition *buffer_empty, QObject *parent)
    : m_threadId(threadId),
      mutex(mutex),
      m_buffer(buffer),
      m_BUFFER_SIZE(BUFFER_SIZE),
      m_usedSlots(usedSlots),
      totalData(totalData),
      m_buffer_Full(buffer_Full),
      m_buffer_empty(buffer_empty),
      QThread(parent)
{

}

void myProducer::run()
{
    for(int i=0; i<totalData; i++)
    {
        mutex->lock();

        if((*m_usedSlots) == m_BUFFER_SIZE)
        {
            m_buffer_Full->wait(mutex);   //this thread wait(block) until wake conditions come.
        }

        mutex->unlock();

        m_buffer[i % m_BUFFER_SIZE] = QRandomGenerator::global()->bounded(100);

        mutex->lock();

        ++(*m_usedSlots);

        m_buffer_empty->wakeAll();

        emit sendTexEdit(QString("Data : %2 from: %1 ").arg(m_threadId).arg(m_buffer[i % m_BUFFER_SIZE]));

        mutex->unlock();

        msleep(100);
    }
}
