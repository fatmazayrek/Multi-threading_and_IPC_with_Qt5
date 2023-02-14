#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void count(int count);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QThread *thread;

public slots:
    void finished();
};
#endif // WIDGET_H
