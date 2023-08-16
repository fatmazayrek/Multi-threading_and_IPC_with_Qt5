#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);
    ui->progressBar->setTextVisible(false);

    threadProg = new MyProgressClass(this);
    connect(threadProg, &MyProgressClass::sendValue, this, &Widget::setProgressBar);
    connect(threadProg, &MyProgressClass::finished, this, &Widget::setProgressCheckBox);

    threadLcd = new MyLCDClass(this);
    connect(threadLcd, &MyLCDClass::sendValue, this, &Widget::setLCDSecreen);
    connect(threadLcd, &MyLCDClass::startSignal, this, &Widget::startSecondThread);
    connect(threadLcd, &MyLCDClass::finished, this, &Widget::setLcdCheckBox);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setLCDSecreen(const int &value)
{
    ui->lcdNumber->display(value);
}

void Widget::setLcdCheckBox()
{
    ui->lcd->setChecked(true);
    ui->lcd->setEnabled(false);
}

void Widget::setProgressCheckBox()
{
    ui->progress->setChecked(true);
    ui->progress->setEnabled(false);
}

void Widget::on_pushButton_clicked()
{
    threadLcd->start();
}

void Widget::setProgressBar(const int &value)
{
    ui->progressBar->setValue(value);
}

void Widget::startSecondThread()
{
    threadProg->start();
}

