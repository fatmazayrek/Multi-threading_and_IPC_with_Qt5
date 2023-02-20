#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include "consumer.h"
#include "myproducer.h"

const int m_BUFFER_SIZE = 10;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void addProducer(const QString &message);
    void addConsumer(const QString &message);

private:
    Ui::Widget *ui;

    int totalData;
    int buffer[m_BUFFER_SIZE];
    QWaitCondition bufferFull;
    QWaitCondition bufferEmpty;
    QMutex mutex;
    int usedSlots;

    myProducer *producer;
    Consumer *consumer;
    Consumer *consumer2;
};
#endif // WIDGET_H
