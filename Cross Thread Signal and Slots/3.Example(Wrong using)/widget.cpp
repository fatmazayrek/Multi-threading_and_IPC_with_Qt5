#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);
    ui->progressBar->setTextVisible(false);

    thread = new myThread(this);

    connect(thread, &myThread::sendData, this, &Widget::setData);
    connect(thread, &myThread::openWindow, this, &Widget::openWindow);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setData(int value)
{
    ui->progressBar->setValue(value);
}

void Widget::openWindow()
{

}


void Widget::on_pushButton_clicked()
{
    thread->start();
}

