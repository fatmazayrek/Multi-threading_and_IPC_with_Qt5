#ifndef MYWORKER_H
#define MYWORKER_H

#include <QObject>
#include <QThread>
#include <QString>
#include "myclass.h"
#include "mymetatype.h"

class MyWorker : public QThread
{
    Q_OBJECT
public:
    explicit MyWorker(QString name, MyClass *myClass ,QObject *parent = nullptr);

signals:
    void sendSignal(myMetaType mt);

    void sendName(QString name);
    void sendCounter(int counter);

private:
    MyClass *m_myClass;
    QString m_name;

    // QThread interface
protected:
    void run();
};

#endif // MYWORKER_H
