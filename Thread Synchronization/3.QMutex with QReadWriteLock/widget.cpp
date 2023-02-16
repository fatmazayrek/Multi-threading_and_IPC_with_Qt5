#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ReadClass *readClass = new ReadClass;

    r_thread = new MyThread("Thread1", readClass, this);
    r_thread2 = new MyThread("Thread2", readClass, this);
    w_thread = new MyThread2("Writer", readClass, this);

    connect(r_thread, &MyThread::sendMessage, this, &Widget::changeTextEdit);
    connect(r_thread2, &MyThread::sendMessage, this, &Widget::changeTextEdit);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_start_clicked()
{
    r_thread->start();
    w_thread->start();
    r_thread2->start();
}

void Widget::changeTextEdit(const QString &message)
{
    ui->textEdit->append(QString(">> %1").arg(message));
}

