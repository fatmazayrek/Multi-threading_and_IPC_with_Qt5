#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QString>
#include "consumer.h"
#include "producer.h"

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(Producer *producer, QObject *parent = nullptr);

signals:
    void sendText(const QString &message);

    // QThread interface
protected:
    void run();

private:
    Producer *producer;
    QString myMessage;

public slots:
    void takeText(const QString &message);
};

#endif // MYTHREAD_H
