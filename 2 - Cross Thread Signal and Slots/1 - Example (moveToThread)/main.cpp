#include "widget.h"

#include <QApplication>
#include "CommonData.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<CommonData>();

    QApplication a(argc, argv);

    Widget w;
    w.setWindowTitle("Cross Thread Signal and Slots");
    w.show();

    return a.exec();
}
