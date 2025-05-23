#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTimer>

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

    void socketReady();
    void readyRead();
    void stateChanged(QAbstractSocket::SocketState socketState);

private:
    Ui::Widget *ui;

    QTcpSocket *myClient;
    QTimer *myTimer;
    bool isClientReady;

    void waitCondition();

};
#endif // WIDGET_H
