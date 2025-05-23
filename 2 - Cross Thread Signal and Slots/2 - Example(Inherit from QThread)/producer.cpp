#include "producer.h"

Producer::Producer(QWidget *parent)
    : QPushButton{parent}
{
    connect(this, &Producer::clicked, this, &Producer::sendData);

    stop = false;

    m_number = 150;

    setText("Please Click to Send Data");

    timer = new QTimer(this);
}

void Producer::sendData()
{
    connect(timer, &QTimer::timeout, this, &Producer::startProduct);
    timer->setInterval(1000);
    timer->start();

}

void Producer::startProduct()
{
    if(stop)
    {
        return;
    }
    else
    {
        CustomData cd("Produced Data", &m_number, 355);

        QString message("Produced data from: %1 Thread");
        message = message.arg((int)QThread::currentThreadId());

        emit data(cd);
        emit sendText(message);
    }
}

void Producer::setStop()
{
    stop = true;
}
