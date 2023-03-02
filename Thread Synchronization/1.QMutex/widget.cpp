#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    flag = false;

    worker = new MyWorker(12, &mutex, &flag, this);
    worker1 = new MyWorker(23, &mutex, &flag, this);

    connect(worker, &MyWorker::writeNumber, this, &Widget::writeOntheConsol);
    connect(worker1, &MyWorker::writeNumber, this, &Widget::writeOntheConsol);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeOntheConsol(const QString text)
{
    ui->textEdit->append(text);
}

void Widget::on_start_clicked()
{
    worker->start();
    worker1->start();
}

