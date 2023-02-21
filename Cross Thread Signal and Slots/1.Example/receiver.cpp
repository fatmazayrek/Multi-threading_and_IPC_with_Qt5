#include "receiver.h"

Receiver::Receiver(QObject *parent)
    : QObject{parent}
{
    m_number = 0;
}

void Receiver::data(const CommonData &cm)
{
    QString message("Datas are: %1 , %2, %3 and they are read from: %4");
    message = message.arg(cm.m_name).arg(cm.m_number).arg(*cm.m_pointer).arg((int)QThread::currentThreadId());

    emit sendText(message);

    if(++m_number > 8)   //If button is clicked more than 15, thread is killed.
    {
        qDebug() << "Thread is killed";

        emit sendText("Thread is killed");

        QThread::currentThread()->quit();
    }
}
