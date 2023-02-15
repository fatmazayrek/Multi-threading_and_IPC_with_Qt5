#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    flag = false;

    worker1 = new MyWorker(10, mutex, &flag, this);
    worker2 = new MyWorker(20, mutex, &flag, this);

    connect(worker1, &MyWorker::emitNumber, this, &Widget::addfromThread);
    connect(worker2, &MyWorker::emitNumber, this, &Widget::addfromThread);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addfromThread(QString text)
{
    ui->textEdit->append(text);
}


void Widget::on_startButton_clicked()
{
    worker1->start();
    worker2->start();
}

