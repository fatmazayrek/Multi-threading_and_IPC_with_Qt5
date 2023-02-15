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
    void addfromThread(QString text);

    void on_startButton_clicked();

private:
    Ui::Widget *ui;

    bool flag;
    QMutex *mutex;
    MyWorker *worker1;
    MyWorker *worker2;
};
#endif // WIDGET_H
