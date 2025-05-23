#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include "mythread.h"
#include "mythread2.h"
#include "readclass.h"

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

    void changeTextEdit(const QString &message);

private:
    Ui::Widget *ui;
    MyThread *r_thread;
    MyThread *r_thread2;
    MyThread2 *w_thread;
};
#endif // WIDGET_H
