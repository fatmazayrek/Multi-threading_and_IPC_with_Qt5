#include "mainwindow.h"

// :::::::::Qt Libs::::::::::::
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    MainWindow w;
    w.setWindowTitle("UDP Receiver");

    w.show();
    return a.exec();
}
