#include "widget.h"
#include "mymetatype.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    qRegisterMetaType<myMetaType>("myMetaType");

    QApplication a(argc, argv);

    Widget w;
    w.setWindowTitle("QMutex with Shared Value");
    w.show();

    return a.exec();
}
