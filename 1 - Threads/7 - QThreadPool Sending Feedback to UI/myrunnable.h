#ifndef MYRUNNABLE_H
#define MYRUNNABLE_H

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QThread>

class MyRunnable : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit MyRunnable(QObject *parent);

signals:
    void sendMessage(int);

public slots:
    void run();

private:
    QObject *m_receiver;
};

#endif // MYRUNNABLE_H
