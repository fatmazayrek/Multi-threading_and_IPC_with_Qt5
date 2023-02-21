#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QDebug>

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = nullptr);

signals:
    void sendData(int value);
    void openWindow();

    // QThread interface
protected:
    void run();

public slots:
    void increment();

private:
    QTimer *m_timer;
    int m_counter;
};

#endif // MYTHREAD_H
