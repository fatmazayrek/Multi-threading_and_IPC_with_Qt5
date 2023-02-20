#ifndef MYPRODUCER_H
#define MYPRODUCER_H

#include <QObject>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include <QRandomGenerator>

class myProducer : public QThread
{
    Q_OBJECT
public:
    explicit myProducer(QString threadId, int *buffer, int BUFFER_SIZE, int *usedSlots,
                        int totalData, QMutex *mutex, QWaitCondition *buffer_Full,
                        QWaitCondition *buffer_empty, QObject *parent = nullptr);

signals:
    void sendTexEdit(QString);

private:
    QString m_threadId;
    QMutex *mutex;
    int *m_buffer;
    int m_BUFFER_SIZE;
    int *m_usedSlots;
    int totalData;
    QWaitCondition *m_buffer_Full;
    QWaitCondition *m_buffer_empty;

    // QThread interface
protected:
    void run();
};

#endif // MYPRODUCER_H
