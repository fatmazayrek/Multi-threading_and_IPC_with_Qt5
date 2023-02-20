#include "mylcdclass.h"

myLCDClass::myLCDClass(QObject *parent)
    : QThread{parent}
{

}

void myLCDClass::run()
{
    qDebug() << "myLCDClass Thread: " << QThread::currentThread();

    for(int i=0; i<101; i++)
    {
        if(i == 15)
        {
            emit startSignal();
        }

        emit setLCD(i);

        msleep(100);
    }
}
