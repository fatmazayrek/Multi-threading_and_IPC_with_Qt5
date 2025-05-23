#ifndef PRODUCER_H
#define PRODUCER_H

#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QTimer>
#include <QThread>
#include "customdata.h"

class Producer : public QPushButton
{
    Q_OBJECT
public:
    explicit Producer(QWidget *parent = nullptr);

signals:
    void data(const CustomData &data);
    void sendText(const QString &message);

public slots:
    void sendData();
    void startProduct();
    void setStop();

private:
    bool stop;
    QTimer *timer;
    int m_number;
};

#endif // PRODUCER_H
