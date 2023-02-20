#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    totalData = 20;
    usedSlots = 0;

    producer = new myProducer("Producer1 ", buffer, m_BUFFER_SIZE, &usedSlots,
                              totalData, &mutex, &bufferFull, &bufferEmpty, this);
    connect(producer, &myProducer::sendTexEdit, this, &Widget::addProducer);

    consumer = new Consumer("Consumer1", &mutex, buffer, m_BUFFER_SIZE,
                            &usedSlots, totalData, &bufferFull, &bufferEmpty, this);
    connect(consumer, &Consumer::sendTextEdit, this, &Widget::addConsumer);

    consumer2 = new Consumer("Consumer2 ", &mutex, buffer, m_BUFFER_SIZE,
                            &usedSlots, totalData, &bufferFull, &bufferEmpty, this);
    connect(consumer2, &Consumer::sendTextEdit, this, &Widget::addConsumer);
}

Widget::~Widget()
{
    delete ui;

    producer->quit();
    consumer->quit();
    consumer2->quit();
}


void Widget::on_pushButton_clicked()
{
    producer->start();
    consumer->start();
    consumer2->start();
}

void Widget::addProducer(const QString &message)
{
    ui->producer->append(message);
}

void Widget::addConsumer(const QString &message)
{
    ui->consumer->append(message);
}
