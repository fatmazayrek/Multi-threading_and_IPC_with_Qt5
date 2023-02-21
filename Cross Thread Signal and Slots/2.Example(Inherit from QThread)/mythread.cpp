#include "mythread.h"

myThread::myThread(Producer *producer, QObject *parent)
    : QThread{parent},
      producer(producer),
      myMessage()
{

}

void myThread::run()
{
    Consumer consumer;
    connect(producer, &Producer::data, &consumer, &Consumer::data);
    connect(&consumer, &Consumer::sendText, this, &myThread::sendText);

    exec();   //You must create your own event loop
}

void myThread::takeText(const QString &message)
{
    emit sendText(message);
}
