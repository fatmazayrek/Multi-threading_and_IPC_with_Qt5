#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QVariant>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    ~MyThread();

signals:
    void currentData(int);
    void Done(QString);

    // QThread interface
protected:
    void run();
};

#endif // MYTHREAD_H
