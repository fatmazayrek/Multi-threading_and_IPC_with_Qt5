#ifndef MYWORKER_H
#define MYWORKER_H

#include <QObject>
#include <QMetaType>
#include <QDebug>
#include <QString>
#include <QThread>
#include "mymetatype.h"

class MyWorker : public QObject
{
    Q_OBJECT
public:
    explicit MyWorker(QObject *parent = nullptr);

signals:
    void currentData(int);

    void currentMetaType(MyMetaType mt);

public slots:
    void doCount();

};

#endif // MYWORKER_H
