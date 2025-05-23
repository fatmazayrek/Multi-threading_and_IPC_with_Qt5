#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThreadPool>
#include <QDebug>
#include <QThread>
#include <QTime>
#include "myrunnable.h"
#include "mytime.h"

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

    void gotUpdate(int value);

private:
    Ui::Widget *ui;
    QThreadPool *pool;
};
#endif // WIDGET_H
