#ifndef MYWORKER_H
#define MYWORKER_H

#include <QObject>
#include <QThread>
#include <QMutex>

class MyWorker : public QThread
{
    Q_OBJECT
public:
    explicit MyWorker(int number, QMutex *mutex, bool *stop, QObject *parent = nullptr);

signals:
    void emitNumber(QString number);

    // QThread interface
protected:
    void run();

private:
    int m_number;
    bool *m_stop;
    QMutex *m_mutex;
};

#endif // MYWORKER_H
