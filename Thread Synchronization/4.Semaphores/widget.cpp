#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    dataSource << 12 <<23 << 1 << 45 << 67 << 8907 << 4 << 11 << 865 << 456 << 123 <<
                  654 << 345 << 987;

    atEnd = false;


    freeSpace = new QSemaphore(BUFFER_SIZE);

    avSpace = new QSemaphore(0);

    producer = new Producer(dataSource,bufferArray,BUFFER_SIZE,freeSpace,avSpace,&atEnd);
    consumer = new Cunsomer(bufferArray,BUFFER_SIZE,freeSpace,avSpace,&atEnd);

    connect(consumer, &Cunsomer::readBuffer, this, &Widget::addTextEdit);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    producer->start();
    consumer->start();

    producer->wait();
    consumer->wait();

    atEnd = false;
}

void Widget::addTextEdit(const QString &text)
{
    ui->textEdit->append(text);
}

