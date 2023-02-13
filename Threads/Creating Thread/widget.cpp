#include "widget.h"
#include "ui_widget.h"

void count1(int count)
{
    for(int i=0; i<count; i++)
    {
        qDebug() << " Thread id: " << QThread::currentThreadId() << ": " << i;
    }
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << " Main Thread id: " << QThread::currentThreadId();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    thread = QThread::create(count1, 14);

    connect(thread, &QThread::finished, this, &Widget::finished);

    thread->start();
}

void Widget::finished()
{
    qDebug() << "Thread is finished";
}

