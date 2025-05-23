#ifndef MYTHREAD2_H
#define MYTHREAD2_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QString>
#include "readclass.h"

class MyThread2 : public QThread
{
    Q_OBJECT
public:
    explicit MyThread2(QString id, ReadClass *m_class, QObject *parent = nullptr);

signals:

private:
    QString m_id;
    ReadClass *m_Class;

protected:
    void run();
};

#endif // MYTHREAD2_H
