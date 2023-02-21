#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include "mybutton.h"
#include "CommonData.h"
#include "receiver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void addText(const QString &message);

private:
    Ui::Widget *ui;

    myButton *producer;
    Receiver *myReceiver;
    QThread *myThread;
};
#endif // WIDGET_H
