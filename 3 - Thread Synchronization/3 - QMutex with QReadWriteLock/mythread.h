#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include "readclass.h"

//Thread for Reading--->
class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QString id, ReadClass *m_class, QObject *parent = nullptr);

signals:
    void sendMessage(const QString &message);

private:
    QString m_id;
    ReadClass *m_Class;

    // QThread interface
protected:
    void run();
};

#endif // MYTHREAD_H
