#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QDebug>
#include <QString>
#include <QMessageBox>
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
    void currentData(int value);
    void finishedThread();
    void Done(QString text);

    void startClicked();
    void infoClicked();

private:
    Ui::Widget *ui;
    MyThread *thread;
};
#endif // WIDGET_H
