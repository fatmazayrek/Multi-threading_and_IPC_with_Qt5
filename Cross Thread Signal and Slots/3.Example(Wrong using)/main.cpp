#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.show();
    w.setWindowTitle("Slots in QThread Subclass");

    return a.exec();
}
