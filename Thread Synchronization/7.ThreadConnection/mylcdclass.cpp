#include "mylcdclass.h"

MyLCDClass::MyLCDClass(QObject *parent)
    : QThread{parent}
{

}

void MyLCDClass::run()
{
    for(int i=0; i<11; i++)
    {
        if(i == 5)
        {
            emit startSignal();
            emit sendValue(i);
            sleep(1);

            continue;
        }

        emit sendValue(i);

        sleep(1);
    }
}
