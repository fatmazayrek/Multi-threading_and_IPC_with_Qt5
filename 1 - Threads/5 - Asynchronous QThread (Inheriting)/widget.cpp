#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    thread = new MyThread(this);

    connect(thread, &MyThread::writeText, this, &Widget::writeontheConsol);
    connect(thread, &MyThread::finished, this, &Widget::threadFinished);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_start_clicked()
{
    thread->start();
}

void Widget::on_stop_clicked()
{
    thread->exit();
}

void Widget::writeontheConsol(QString text)
{
    ui->textEdit->append(text);
}

void Widget::threadFinished()
{
    ui->textEdit->append(QString("Thread is finished"));
}

