#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include "mythread.h"
#include "mythread2.h"

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
    void currentData(int value);
    void finishedThread();
    void finishedThread2();
    void Done(QString text);
    void setDial(int value);

    void startClicked();
    void infoClicked();

private:
    Ui::Widget *ui;
    MyThread *thread;
    MyThread2 *thread2;
};
#endif // WIDGET_H
