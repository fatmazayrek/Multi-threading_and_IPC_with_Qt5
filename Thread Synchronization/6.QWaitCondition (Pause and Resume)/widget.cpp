#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);
    ui->progressBar->setTextVisible(false);

    myLCD = new myLCDClass(this);
    connect(myLCD, &myLCDClass::setLCD, this, &Widget::setLCD);

    myProgress = new myThread(this);
    connect(myProgress, &myThread::setProgressbar, this, &Widget::setProgressBar);
    connect(myLCD, &myLCDClass::startSignal, myProgress, &myThread::resume);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setLCD(const int &value)
{
    ui->lcdNumber->display(value);
}

void Widget::setProgressBar(const int &value)
{
    ui->progressBar->setValue(value);
}


void Widget::on_pushButton_clicked()
{
    myLCD->start();
    myProgress->start();
}


void Widget::on_pause_clicked()
{
    myProgress->pause();
}


void Widget::on_resume_clicked()
{
    myProgress->resume();
}

