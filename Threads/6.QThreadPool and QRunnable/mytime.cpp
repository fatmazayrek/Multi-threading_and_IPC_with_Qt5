#include "mytime.h"

MyTime::MyTime(QObject *parent)
    : QObject{parent}
{

}

void MyTime::run()
{
    for(int i=0; i<10; i++)
    {
        QDateTime currentTime = QDateTime::currentDateTime();

        emit sendTime(currentTime.time());

        qDebug() << currentTime.time();

        QThread::msleep(1000);
    }

    qDebug() << "MyTime thread is finsihed";
}
