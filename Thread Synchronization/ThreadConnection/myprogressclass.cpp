#include "myprogressclass.h"

MyProgressClass::MyProgressClass(QObject *parent)
    : QThread{parent}
{

}

void MyProgressClass::run()
{
    for(int i=0; i<101; i++)
    {
        emit sendValue(i);

        msleep(100);

    }
}
