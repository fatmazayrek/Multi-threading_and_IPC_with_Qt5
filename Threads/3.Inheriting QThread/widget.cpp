#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);
    ui->dial->setSingleStep(1);
    ui->dial->setNotchesVisible(true);

    connect(ui->start, &QPushButton::clicked, this, &Widget::startClicked);
    connect(ui->info, &QPushButton::clicked, this, &Widget::infoClicked);

    thread = new MyThread(this);
    thread2 = new MyThread2(this);

    connect(thread, &MyThread::currentData, this, &Widget::currentData);
    connect(thread, &MyThread::Done, this, &Widget::Done);
    connect(thread, &MyThread::finished, this, &Widget::finishedThread);

    connect(thread2, &MyThread2::finished, this, &Widget::finishedThread2);
    connect(thread2, &MyThread2::currentData, this, &Widget::setDial);
}

Widget::~Widget()
{
    delete ui;

    thread->quit();
    thread2->quit();
    thread->wait(1000);

    if(!thread->isFinished())
    {
        thread->terminate();
    }

    thread2->wait(1000);

    if(!thread2->isFinished())
    {
        thread2->terminate();
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

void Widget::finishedThread2()
{
    qDebug() << "Thread2 is Finished. " << thread;
}

void Widget::Done(QString text)
{
    QMessageBox msg;
    msg.setStyleSheet("QLabel{min-width: 700px;}");
    msg.setInformativeText(text);
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}

void Widget::setDial(int value)
{
    ui->dial->setValue(value);
}

void Widget::startClicked()
{
    thread->start();
}

void Widget::infoClicked()
{
    thread2->start();
}

