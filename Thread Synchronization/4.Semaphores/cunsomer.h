#ifndef CUNSOMER_H
#define CUNSOMER_H

#include <QObject>
#include <QSemaphore>
#include <QThread>
#include <QString>
#include <QVector>

class Cunsomer : public QThread
{
    Q_OBJECT
public:
    explicit Cunsomer(int *buffer, int bufferSize, QSemaphore *freeSpace,
                      QSemaphore *availableSpace,
                      bool *atEnd,QObject *parent = nullptr);

signals:
    void readBuffer(const QString &text);

private:
    int * m_buffer;
    int m_BUFFER_SIZE;
    QSemaphore * m_free_space;       // Space where the producer can write data
    QSemaphore * m_available_space;  //Space where consumer can read data from
    bool * m_at_end;

    // QThread interface
protected:
    void run();
};

#endif // CUNSOMER_H
