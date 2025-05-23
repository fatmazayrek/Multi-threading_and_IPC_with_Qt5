#include "widget.h"
#include "ui_widget.h"

#include <QHostAddress>
#include <QDataStream>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Widget),
      myClient(new QTcpSocket(this)),
      isClientReady(false)
{
    ui->setupUi(this);

    myTimer = new QTimer(this);

    connect(myClient, &QTcpSocket::connected, this, &Widget::socketReady);
    connect(myClient, &QTcpSocket::readyRead, this, &Widget::readyRead);
    connect(myClient, &QTcpSocket::stateChanged, this, &Widget::stateChanged);

    connect(myTimer, &QTimer::timeout, this, &Widget::waitCondition);

    myTimer->setInterval(5000);
    myTimer->start();
}

Widget::~Widget()
{
    delete ui;

    myTimer->deleteLater();
    myClient->close();
    myClient->deleteLater();
}

void Widget::on_sendButton_clicked()
{
    if(myClient)
    {
        QDataStream dataStream(myClient);
        dataStream << ui->message->text();  //write message into the dataStream.
    }

}

void Widget::socketReady()
{
    isClientReady = true;

    qDebug() << "Client Widget:: Client connected to Server succesfully..";
}

void Widget::readyRead()
{
    QDataStream dataStream(myClient);
    dataStream.startTransaction();   //You must write it. Starts the reading.

    QString message;

    dataStream >> message;    //read data from dataStream

    if(!dataStream.commitTransaction())   //Completes a read transaction. You should use.
    {
        qDebug() << "Client Widget:: An error has been detected..";

        return;
    }

    ui->allMessages->append(QString("Message from Server ==> %1").arg(message));
}

void Widget::stateChanged(QAbstractSocket::SocketState socketState)
{
    qDebug() << "Client Widget:: Client status: " << socketState;
}

void Widget::waitCondition()
{
    myClient->connectToHost(QHostAddress::LocalHost, 5050);
    /* If you write this into the constructor, it tries just once. But when you write into
the this function, it will try every second you determined */

    if(myClient->waitForConnected())
    {
        ui->message->setPlaceholderText("Client connected to server");
        myTimer->stop();
    }

    else
    {
        QMessageBox msg;
        msg.setInformativeText("Please check the Server..");
        msg.setIcon(QMessageBox::Warning);
        msg.exec();
    }
}
