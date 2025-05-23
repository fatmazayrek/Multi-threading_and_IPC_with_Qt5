#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QMutex>
#include "myworker.h"

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
    void writeOntheConsol(const QString text);

    void on_start_clicked();

private:
    Ui::Widget *ui;
    MyWorker *worker;
    MyWorker *worker1;
    QMutex mutex;
    bool flag;
};
#endif // WIDGET_H
