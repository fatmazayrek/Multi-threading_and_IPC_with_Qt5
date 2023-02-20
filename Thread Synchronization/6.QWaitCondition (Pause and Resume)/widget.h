#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mylcdclass.h"
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
    void setLCD(const int &value);
    void setProgressBar(const int &value);

    void on_pushButton_clicked();
    void on_pause_clicked();

    void on_resume_clicked();

private:
    Ui::Widget *ui;

    myLCDClass *myLCD;
    myThread *myProgress;
};
#endif // WIDGET_H
