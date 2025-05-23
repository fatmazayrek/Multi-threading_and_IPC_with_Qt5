#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);
    ui->label->setText("Please click the button for progressing..");

    thread = new QThread(this);
}

Widget::~Widget()
{
    delete ui;

    thread->quit();
}


void Widget::on_start_clicked()
{
    MyWorker *worker = new MyWorker;
    worker->moveToThread(thread);

    connect(thread, &QThread::started, worker, &MyWorker::doCount);
    connect(worker, &MyWorker::currentMetaType, this, &Widget::changeProgressLabel);
    connect(thread, &QThread::finished, worker, &MyWorker::deleteLater);

    thread->start();
}

void Widget::changeProgressLabel(MyMetaType mt)
{
    ui->progressBar->setValue(mt.number());
    ui->label->setText(mt.String());
}

