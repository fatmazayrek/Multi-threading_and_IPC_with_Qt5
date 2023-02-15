#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    pool = QThreadPool::globalInstance();
}

Widget::~Widget()
{
    delete ui;
}

//If you click more than one, threads are created more than one-->
void Widget::on_start_clicked()
{
    MyRunnable *runnable = new MyRunnable(this);
    runnable->setAutoDelete(true);

    pool->start(runnable);
}

void Widget::gotUpdate(int value)
{
    ui->lcdNumber->display(value);
}


