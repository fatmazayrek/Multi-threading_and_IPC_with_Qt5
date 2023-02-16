#include "mythread2.h"

MyThread2::MyThread2(QString id, ReadClass *m_class, QObject *parent):
    m_id(id), m_Class(m_class), QThread(parent)
{

}

void MyThread2::run()
{
    for(int i=0; i<10; i++)
    {
        m_Class->increment();
        msleep(1500);
    }
}
