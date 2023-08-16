#ifndef MYPROGRESSCLASS_H
#define MYPROGRESSCLASS_H

#include <QObject>
#include <QThread>

class MyProgressClass : public QThread
{
    Q_OBJECT
public:
    explicit MyProgressClass(QObject *parent = nullptr);

signals:
    void sendValue(int);

protected:
    void run();
};

#endif // MYPROGRESSCLASS_H
