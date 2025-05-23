#include "myclass.h"

MyClass::MyClass()
{
    counter = 0;
}

void MyClass::doWork(QString text)
{
    QMutexLocker locker(&mutex);

    qDebug() << text << ": " << counter++ ;
}

int MyClass::getCounter() const
{
    return counter;
}
