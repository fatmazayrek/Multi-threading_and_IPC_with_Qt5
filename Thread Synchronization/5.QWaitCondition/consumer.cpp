#include "consumer.h"

Consumer::Consumer(QString threadId, QMutex *mutex, int *buffer,
                   int BUFFER_SIZE, int *usedSlots, int totalData,
                   QWaitCondition *buffer_Full, QWaitCondition *buffer_empty,
                   QObject *parent)
    : threadId(threadId),
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

void Consumer::run()
{
    for (int i = 0; i < totalData; ++i)
    {
        mutex->lock();

        if((*m_usedSlots) == 0)
        {
            m_buffer_empty->wait(mutex);
        }

        mutex->unlock();

        QString message = QString("Data: %1 read from %2").arg(m_buffer[i % m_BUFFER_SIZE]).arg(threadId);

        mutex->lock();

        --(*m_usedSlots);

        m_buffer_Full->wakeAll();

        emit sendTextEdit(message);

        mutex->unlock();

        msleep(100);
    }
}
