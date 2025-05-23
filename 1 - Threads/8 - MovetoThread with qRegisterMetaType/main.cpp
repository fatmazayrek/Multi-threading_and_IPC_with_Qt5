#include "widget.h"
#include <QApplication>
#include "mymetatype.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<MyMetaType>("MyMetaType");

    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
