#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);

    thread = new QThread(this);
    connect(thread, &QThread::finished, this, &Widget::threadFinished);
}

Widget::~Widget()
{
    delete ui;

    thread->quit();
    if(!thread->isFinished())
    {
        thread->terminate();
    }
}


void Widget::on_start_clicked()
{
    Worker *worker = new Worker;
    worker->moveToThread(thread);

    connect(thread, &QThread::started, worker, &Worker::counting);
    connect(thread, &QThread::finished, worker, &Worker::deleteLater);

    connect(worker, &Worker::currentValue, this, &Widget::currentCount);
    connect(worker, &Worker::Done, this, &Widget::countDone);

    thread->start();
}


void Widget::on_Info_clicked()
{
    qDebug() << "Thread is Running: " << thread->isRunning();
}

void Widget::countDone(QString text)
{
    QMessageBox msg;
    msg.setStyleSheet("QLabel{min-width: 700px;}");
    msg.setInformativeText(text);
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();

    thread->exit();
}

void Widget::currentCount(int value)
{
    ui->progressBar->setValue(value);
    ui->lcdNumber->display(value);
}

void Widget::threadFinished()
{
    qDebug() << "Thread is Finished..";
}

