#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QDebug>
#include <QWaitCondition>
#include <QMutex>

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = nullptr);

signals:
    void setProgressbar(int value);
    void openMessageBox();

public slots:
    void pause();
    void resume();

    // QThread interface
protected:
    void run();

private:
    QMutex m_mutex;
    QWaitCondition w_condition;
    bool m_pause;
};

#endif // MYTHREAD_H
