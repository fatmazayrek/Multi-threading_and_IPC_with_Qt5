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

