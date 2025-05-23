#ifndef MYCLASS_H
#define MYCLASS_H

#include <QMutex>
#include <QDebug>
#include <QString>
#include <QMutexLocker>

class MyClass
{
public:
    MyClass();

public:
    void doWork(QString text);

    int getCounter() const;

private:
    QMutex mutex;
    int counter;
};

#endif // MYCLASS_H
