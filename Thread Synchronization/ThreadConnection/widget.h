#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include "mylcdclass.h"
#include "myprogressclass.h"

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
    void setLCDSecreen(const int &value);
    void setProgressBar(const int &value);
    void startSecondThread();
    void setLcdCheckBox();
    void setProgressCheckBox();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    MyLCDClass *threadLcd;
    MyProgressClass *threadProg;
};
#endif // WIDGET_H
