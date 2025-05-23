#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyClass *myClass = new MyClass();

    worker1 = new MyWorker("Thread1", myClass, this);
    worker2 = new MyWorker("Thread2", myClass, this);

    connect(worker1, &MyWorker::sendSignal, this, &Widget::changeLineEdit1);
    connect(worker2, &MyWorker::sendSignal, this, &Widget::changeLineEdit2);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_start_clicked()
{
    worker1->start();
    worker2->start();
}

void Widget::changeLineEdit1(myMetaType message)
{
    QString msg = message.getId() + ": " + QString::number(message.counter());

    ui->lineEdit->setText(msg);
}

void Widget::changeLineEdit2(myMetaType message)
{
    QString msg = message.getId() + ": " + QString::number(message.counter());

    ui->lineEdit_2->setText(msg);
}

