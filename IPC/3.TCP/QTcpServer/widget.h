#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

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
    void on_sendButton_clicked();

    void newConnection();
    void readData();

private:
    Ui::Widget *ui;

    QTcpServer myServer;
    QTcpSocket *myClient;
};
#endif // WIDGET_H
