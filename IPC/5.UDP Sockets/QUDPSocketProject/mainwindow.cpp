#include "mainwindow.h"
#include "ui_mainwindow.h"

// ::::::::::Qt Libs:::::::::::
#include <QHostAddress>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Send_clicked()
{
    QByteArray datagram = ui->message->text().toUtf8();

    udpSocket->writeDatagram(datagram, QHostAddress::Broadcast, ui->portNum->value());

    qDebug() << datagram;
}

