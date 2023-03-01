#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include <QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myProcess = new QProcess(this);

    connect(myProcess, &QProcess::started, this, &Widget::started);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_choose_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Select a File"), "C:/", tr("Programs (*.exe)"));

    if(!fileName.isNull())
    {
        ui->lineEdit->setText(fileName);
    }
}


void Widget::on_start_clicked()
{
    if(!fileName.isNull())
    {
        myProcess->start(fileName);
    }

    else
    {
        QPixmap myPixmap("://myImages/attach file.png");

        QMessageBox msg;
        msg.setInformativeText("You must select one file");
        msg.setIconPixmap(myPixmap);
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        int result = msg.exec();

        if(result == QMessageBox::Cancel)
        {
            QApplication::closeAllWindows();
        }
    }
}

void Widget::on_stop_clicked()
{
    myProcess->close();
}

void Widget::started()
{
    qDebug() << "Process started..." ;
}

