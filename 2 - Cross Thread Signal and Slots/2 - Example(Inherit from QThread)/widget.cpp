#include "widget.h"
#include "ui_widget.h"
#include <QCloseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "Ui Thread is:"  << (int)QThread::currentThreadId();

    m_producer = new Producer();
    ui->verticalLayout->addWidget(m_producer);

    m_thread = new myThread(m_producer, this);

    connect(m_producer, &Producer::sendText, this, &Widget::addProducer);
    connect(m_thread, &myThread::sendText, this, &Widget::addReceiver);
    connect(m_thread, &myThread::finished, m_producer, &Producer::setStop);

    m_thread->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addProducer(const QString &message)
{
    ui->producer->append(message);
}

void Widget::addReceiver(const QString &message)
{
    ui->receiver->append(message);
}

void Widget::closeEvent(QCloseEvent *event)
{
    m_thread->quit();

    event->accept();
}

