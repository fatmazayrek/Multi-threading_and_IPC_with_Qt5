#ifndef MYLCDCLASS_H
#define MYLCDCLASS_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QDebug>

class myLCDClass : public QThread
{
    Q_OBJECT
public:
    explicit myLCDClass(QObject *parent = nullptr);

signals:
    void setLCD(int value);
    void startSignal();

public slots:

    // QThread interface
protected:
    void run();
};

#endif // MYLCDCLASS_H
