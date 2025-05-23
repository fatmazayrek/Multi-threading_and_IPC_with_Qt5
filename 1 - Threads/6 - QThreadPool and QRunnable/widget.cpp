#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->timeEdit->setDisplayFormat("HH:mm:ss");
    ui->stop->setEnabled(false);

    pool = QThreadPool::globalInstance();
}

Widget::~Widget()
{
    delete ui;
}

//If you click more than one, threads are created more than one-->
void Widget::on_start_clicked()
{
    ui->stop->setEnabled(true);

    MyRunnable *runnable = new MyRunnable;
    runnable->setAutoDelete(true);

    connect(runnable, &MyRunnable::sendMessage, this, &Widget::setLcd);

    pool->start(runnable);
}

//If you click more than one, threads are created more than one-->
void Widget::on_progress_clicked()
{
    MyTime *mytime = new MyTime;
    mytime->setAutoDelete(true);

    connect(mytime, &MyTime::sendTime, this, &Widget::setTime);

    pool->start(mytime);
}

void Widget::setLcd(int value)
{
    ui->lcdNumber->display(value);
}

void Widget::setTime(QTime time)
{
    ui->timeEdit->setTime(time);
}


