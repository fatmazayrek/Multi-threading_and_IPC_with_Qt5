#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QString>
#include <QThread>
#include <QDebug>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();

signals:
    void Done(QString);
    void currentValue(int);

public slots:
    void counting();
};

#endif // WORKER_H
