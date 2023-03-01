#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>

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
    void on_choose_clicked();
    void on_start_clicked();
    void on_stop_clicked();

    void started();

private:
    Ui::Widget *ui;

    QString fileName;
    QProcess *myProcess;
};
#endif // WIDGET_H
