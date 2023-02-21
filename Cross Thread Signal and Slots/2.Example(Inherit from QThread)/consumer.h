#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QDebug>
#include "customdata.h"

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject *parent = nullptr);
    QString *m_text;

signals:
    void sendText(const QString &message);

public slots:
    void data(const CustomData &data);

private:
    int m_number;
    QString *m_message;
};

#endif // CONSUMER_H
