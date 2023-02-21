#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include "producer.h"
#include "consumer.h"
#include "mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    Producer *m_producer;
    Consumer *m_consumer;
    myThread *m_thread;

private slots:
    void addProducer(const QString &message);
    void addReceiver(const QString &message);

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};
#endif // WIDGET_H
