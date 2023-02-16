#include "mythread.h"

MyThread::MyThread(QString id, ReadClass *m_class, QObject *parent):
    m_id(id), m_Class(m_class), QThread(parent)
{

}

void MyThread::run()
{
    for(int i=0; i<6; i++)
    {
        emit sendMessage(m_Class->print(m_id));

        msleep(1000);
    }
}
