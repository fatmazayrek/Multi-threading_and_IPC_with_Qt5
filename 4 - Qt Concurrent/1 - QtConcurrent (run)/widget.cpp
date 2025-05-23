#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "Ui Thread is: " << QThread::currentThread();

    ui->progressBar->setValue(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::doWork(int counter)
{
    for(int i=0; i<counter; i++)
    {
        qDebug() << "This number is: " << i << " and This thread is:"
                 << QThread::currentThread();
        QThread::msleep(100);
    }
}


void Widget::on_start_clicked()
{
    future = QtConcurrent::run(doWork, 101);

    future.waitForFinished();
/* If you write qDebug() without waiting finished, "Done" is written
 at the top, under the Ui Thread */

    qDebug() << "Done";
}

//Currently, these methods are useless ---->
void Widget::on_stop_clicked()
{
    future.pause();
}

void Widget::on_cancel_clicked()
{
    future.cancel();
}

void Widget::on_resume_clicked()
{
    future.resume();
}

