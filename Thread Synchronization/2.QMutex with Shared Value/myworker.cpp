#include "myworker.h"


MyWorker::MyWorker(QString name, MyClass *myClass, QObject *parent):
    m_name(name), m_myClass(myClass) , QThread(parent)
{

}

void MyWorker::run()
{
    for(int i=0; i<10; i++)
    {
        m_myClass->doWork(m_name);

        sleep(1);
    }
}
