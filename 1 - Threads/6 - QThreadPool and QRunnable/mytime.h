#ifndef MYTIME_H
#define MYTIME_H

#include <QObject>
#include <QRunnable>
#include <QDateTime>
#include <QTime>
#include <QDateTime>
#include <QDebug>
#include <QThread>

class MyTime : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit MyTime(QObject *parent = nullptr);

signals:
    void sendTime(QTime);

    // QRunnable interface
public:
    void run();
};

#endif // MYTIME_H
