#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include <QRandomGenerator>

class Consumer : public QThread
{
    Q_OBJECT
public:
    explicit Consumer(QString threadId, QMutex *mutex,
                      int *buffer, int BUFFER_SIZE, int *usedSlots,
                      int totalData, QWaitCondition *buffer_Full,
                      QWaitCondition *buffer_empty, QObject *parent = nullptr);

signals:
    void sendTextEdit(QString);

private:
    QString threadId;
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

#endif // CONSUMER_H
