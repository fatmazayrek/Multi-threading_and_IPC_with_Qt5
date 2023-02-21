#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "Ui Thread is: " << QThread::currentThread();

    producer = new myButton(this);
    ui->verticalLayout->addWidget(producer);

    myReceiver = new Receiver();       //if you put "this" into the paranthesis you get an error.

    myThread = new QThread(this);

    myReceiver->moveToThread(myThread);

    connect(producer, &myButton::sendText, this, &Widget::addText);
    connect(producer, &myButton::data, myReceiver, &Receiver::data);
    connect(myReceiver, &Receiver::sendText, this, &Widget::addText);
    connect(myThread, &QThread::finished, myReceiver, &Receiver::deleteLater);

    myThread->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addText(const QString &message)
{
    ui->textEdit->append(message);
}

