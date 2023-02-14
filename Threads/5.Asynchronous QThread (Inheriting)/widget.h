#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QDebug>
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
    void on_start_clicked();
    void on_stop_clicked();

    void writeontheConsol(QString text);
    void threadFinished();

private:
    Ui::Widget *ui;
    MyThread *thread;
};
#endif // WIDGET_H
