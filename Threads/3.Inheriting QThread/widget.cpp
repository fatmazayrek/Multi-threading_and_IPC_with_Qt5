#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);

    connect(ui->start, &QPushButton::clicked, this, &Widget::startClicked);
    connect(ui->info, &QPushButton::clicked, this, &Widget::infoClicked);

    thread = new MyThread(this);
    connect(thread, &MyThread::currentData, this, &Widget::currentData);
    connect(thread, &MyThread::Done, this, &Widget::Done);
    connect(thread, &MyThread::finished, this, &Widget::finishedThread);
}

Widget::~Widget()
{
    delete ui;

    thread->quit();
    thread->wait(1000);
    if(!thread->isFinished())
    {
        thread->terminate();
    }
}

void Widget::currentData(int value)
{
    ui->progressBar->setValue(value);
    ui->lcdNumber->display(value);
}

void Widget::finishedThread()
{
    qDebug() << "Thread is Finished. " << thread;
}

void Widget::Done(QString text)
{
    QMessageBox msg;
    msg.setStyleSheet("QLabel{min-width: 700px;}");
    msg.setInformativeText(text);
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}

void Widget::startClicked()
{
    thread->start();
}

void Widget::infoClicked()
{
    qDebug() << thread->isRunning();
}

