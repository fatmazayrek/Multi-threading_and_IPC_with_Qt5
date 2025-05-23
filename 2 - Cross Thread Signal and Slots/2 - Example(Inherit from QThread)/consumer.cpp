#include "consumer.h"

Consumer::Consumer(QObject *parent)
    : QObject{parent}
{
    m_number = 0;
}

void Consumer::data(const CustomData &data)
{
    QString message("Datas are: %1 , %2, %3 and they are read from: %4");
    message = message.arg(data.m_name).arg(data.m_number).arg(*data.m_pointer).arg((int)QThread::currentThreadId());

    emit sendText(message);

    qDebug() << message;

    if(++m_number > 8)   //If button is clicked more than 15, thread is killed.
    {
        qDebug() << "Thread is killed";

        message = "Thread is killed";

        emit sendText(message);

        QThread::currentThread()->quit();
    }
}
