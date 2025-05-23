#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mythread.h"

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
    void setData(int value);
    void openWindow();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    myThread *thread;
};
#endif // WIDGET_H
