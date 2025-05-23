#ifndef MYTHREAD2_H
#define MYTHREAD2_H

#include <QThread>

class MyThread2 : public QThread
{
    Q_OBJECT
public:
    explicit MyThread2(QObject *parent = nullptr);

signals:
    void currentData(int);

    // QThread interface
protected:
    void run();
};

#endif // MYTHREAD2_H
