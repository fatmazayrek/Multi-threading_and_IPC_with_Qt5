#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QDebug>
#include <QThread>
#include "CommonData.h"

class myButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myButton(QWidget *parent = nullptr);   //Inherit QWidget Class

signals:
    void data(const CommonData &data);
    void sendText(const QString &message);

public slots:
    void sendData();

private:
    int m_number;
};

#endif // MYBUTTON_H
