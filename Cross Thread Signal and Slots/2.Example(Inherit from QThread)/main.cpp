#include "widget.h"

#include <QApplication>
#include "customdata.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<CustomData>();

    QApplication a(argc, argv);

    Widget w;
    w.setWindowTitle("Cross Thread Signal and Slots");
    w.show();

    return a.exec();
}
