#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QDataStream>
#include <QHostAddress>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Widget),
      myServer(this)
{
    ui->setupUi(this);

    myServer.listen(QHostAddress::LocalHost, 5050);

    connect(&myServer, &QTcpServer::newConnection, this, &Widget::newConnection);
}

Widget::~Widget()
{
    if(myClient)
    {
        myClient->close();
        myClient->deleteLater();
    }

    myServer.close();

    delete ui;
}


void Widget::on_sendButton_clicked()
{
    QDataStream dataStream(myClient);

    dataStream << ui->message->text();   //writes the data into the dataStream

    ui->allMessages->append(QString("Sending message: %1").arg(ui->message->text()));

    qDebug() << "Sending message from server: " << dataStream;
}

void Widget::newConnection()
{
    qDebug() << "There is a new Connection:)";

    myClient = myServer.nextPendingConnection();
    //connect the pending connection to server as QTcpSocket

    connect(myClient, &QTcpSocket::readyRead, this, &Widget::readData);
    //check for new data
}

void Widget::readData()
{
    QDataStream dataStream(myClient);
    dataStream.startTransaction();

    QString myMessage;

    dataStream >> myMessage;   //read the message from dataStream

    if(!dataStream.commitTransaction())   //Completes a read transaction
    {
        qDebug() << "An error has been detected..";

        return;
    }

    ui->allMessages->append(QString("Message from: %1 ==> %2").arg(myClient->socketDescriptor()).arg(myMessage));
}

