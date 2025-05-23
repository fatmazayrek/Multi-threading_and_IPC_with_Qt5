#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->textEdit->setFontFamily("Georgia");
    ui->textEdit->setFontPointSize(10);

    thread = new QThread(this);
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

    connect(thread, &QThread::started, worker, &Worker::doWork);
    connect(thread, &QThread::finished, worker, &Worker::deleteLater);

    connect(worker, &Worker::WriteText, this, &Widget::writeOntheEdit);

    thread->start();
}

void Widget::writeOntheEdit(QString text)
{
    ui->textEdit->append(text);
}

void Widget::finishedThread(QString text)
{
    ui->textEdit->append(text);
}


void Widget::on_stop_clicked()
{
    thread->exit();
    qDebug() << "Thread is finished..";
}

