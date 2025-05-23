#ifndef MYLCDCLASS_H
#define MYLCDCLASS_H

#include <QObject>
#include <QThread>
#include <QDebug>

class MyLCDClass : public QThread
{
    Q_OBJECT
public:
    explicit MyLCDClass(QObject *parent = nullptr);

signals:
    void startSignal();
    void sendValue(int);

    // QThread interface
protected:
    void run();
};

#endif // MYLCDCLASS_H
