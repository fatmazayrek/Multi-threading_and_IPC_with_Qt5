#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QProgressBar>
#include <QLCDNumber>
#include <QPushButton>
#include <QThread>
#include <QMessageBox>
#include <QSizePolicy>
#include "worker.h"

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
    void on_Info_clicked();

    void countDone(QString text);
    void currentCount(int value);
    void threadFinished();

private:
    Ui::Widget *ui;
    QThread *thread;
};
#endif // WIDGET_H
