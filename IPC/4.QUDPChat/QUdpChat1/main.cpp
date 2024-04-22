#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    MainWindow w;
    w.setWindowTitle("Chat1");

    w.show();
    return a.exec();
}
