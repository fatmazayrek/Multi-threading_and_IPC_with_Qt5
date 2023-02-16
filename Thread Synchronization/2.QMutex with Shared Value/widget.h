#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myworker.h"
#include "mymetatype.h"
#include "myclass.h"

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
    void on_start_clicked();

    void changeLineEdit1(myMetaType message);
    void changeLineEdit2(myMetaType message);

private:
    Ui::Widget *ui;
    MyWorker *worker1;
    MyWorker *worker2;
};
#endif // WIDGET_H
