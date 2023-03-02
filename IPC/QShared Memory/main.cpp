#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.setWindowTitle("Process 1");
    w.show();

    return a.exec();
}
