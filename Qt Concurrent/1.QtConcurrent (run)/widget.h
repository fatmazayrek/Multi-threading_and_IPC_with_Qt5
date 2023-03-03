#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QtConcurrent>
#include <QFuture>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    static void doWork(int counter);

signals:

private slots:
    void on_start_clicked();
    void on_stop_clicked();
    void on_cancel_clicked();
    void on_resume_clicked();

private:
    Ui::Widget *ui;

    QFuture<void> future;
};
#endif // WIDGET_H

//Note: Don't forget to add "QT += concurrent" statement into the .pro file
