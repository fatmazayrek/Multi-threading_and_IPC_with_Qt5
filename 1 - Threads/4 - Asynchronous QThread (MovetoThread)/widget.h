#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QThread>
#include <QTimer>
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
    void writeOntheEdit(QString text);
    void finishedThread(QString text);

    void on_stop_clicked();

private:
    Ui::Widget *ui;
    QThread *thread;
};
#endif // WIDGET_H
