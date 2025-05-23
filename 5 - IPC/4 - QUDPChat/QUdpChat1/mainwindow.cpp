#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);

    connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::readData);
}

MainWindow::~MainWindow()
{
    delete ui;
    udpSocket->close();
}

void MainWindow::readData()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;

        datagram.resize(udpSocket->pendingDatagramSize());

        udpSocket->readDatagram(datagram.data(), datagram.size());

        ui->textEdit->append(QString("Alınan mesaj :: %1").arg(QString(datagram)));
    }
}


void MainWindow::on_connectButton_clicked()
{
    udpSocket->bind(QHostAddress::Any, 1234);
}


void MainWindow::on_sendButton_clicked()
{
    udpSocket->writeDatagram(ui->message->text().toUtf8(), QHostAddress::LocalHost, 1244);

    ui->message->clear();
}

