#include "mybutton.h"

myButton::myButton(QWidget *parent)
    : QPushButton{parent}
{
    connect(this, &myButton::clicked, this, &myButton::sendData);

    m_number = 200;

    setText("Please Click to Send Data");
}

void myButton::sendData()
{
    CommonData cm("Produced Data", &m_number, 355);

    QString message("Produced data from: %1 Thread");
    message = message.arg((int)QThread::currentThreadId());

    emit data(cm);
    emit sendText(message);
}
