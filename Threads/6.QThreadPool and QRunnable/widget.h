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

signals:
    void emitTerminate();

private slots:
    void on_start_clicked();
    void on_progress_clicked();

    void setLcd(int value);
    void setTime(QTime time);

private:
    Ui::Widget *ui;
    QThreadPool *pool;
};
#endif // WIDGET_H
