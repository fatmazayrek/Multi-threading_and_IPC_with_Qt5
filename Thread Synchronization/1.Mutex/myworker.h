#ifndef MYWORKER_H
#define MYWORKER_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>

class MyWorker : public QThread
{
    Q_OBJECT
public:
    explicit MyWorker(int number, QMutex *mutex, bool *stop,
                      QObject *parent = nullptr);
    ~MyWorker();

signals:
    void writeNumber(QString);
    // QThread interface
protected:
    void run();

private:
    int m_number;
    bool *m_stop;
    QMutex *mutex;
};

#endif // MYWORKER_H
