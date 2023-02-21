#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QString>
#include "CommonData.h"

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = nullptr);

signals:
    void sendText(const QString &message);

public slots:
    void data(const CommonData &cm);

private:
    int m_number;
};

#endif // RECEIVER_H
