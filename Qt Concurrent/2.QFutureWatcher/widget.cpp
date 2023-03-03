#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "Ui Thread is: " << QThread::currentThread();

    connect(&watcher, &QFutureWatcher<void>::finished, this, &Widget::finished);
}

Widget::~Widget()
{
    delete ui;
}

QFuture<QVector<int> > Widget::doWork()
{
    return QtConcurrent::run(doInterWork);
}

QVector<int> Widget::doInterWork()
{
    qDebug() << "doInterWork is running this thread: " << QThread::currentThread();

    QVector<int> vector;

    for(int i=0; i<101; i++)
    {
        qDebug() << "InterWork value: " << i;

        vector.push_back(i);

        QThread::currentThread()->msleep(100);
    }

    return vector;
}

void Widget::finished()
{
    if(!watcher.isCanceled())
    {
        QVector<int> resultVector = watcher.result();

        for(int i=0; i<resultVector.count(); i++)
        {
            qDebug() << "[ " << i << "] : " << resultVector[i];
        }
    }

    else
    {
        qDebug() << "Watcher is already canceled";
    }

    qDebug() << "----------- Function is Done -----------";
}


void Widget::on_start_clicked()
{
    future = doWork();

    watcher.setFuture(future);
}


void Widget::on_cancel_clicked()
{
    watcher.cancel();
}


void Widget::on_pause_clicked()
{
    watcher.pause();
}


void Widget::on_resume_clicked()
{
    watcher.resume();
}

