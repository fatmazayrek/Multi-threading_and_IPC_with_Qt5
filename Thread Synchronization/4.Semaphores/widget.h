#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSemaphore>
#include "producer.h"
#include "cunsomer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

const int BUFFER_SIZE = 10;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void addTextEdit(const QString &text);

private:
    Ui::Widget *ui;
    bool atEnd;
    QSemaphore *freeSpace;
    QSemaphore *avSpace;
    QVector<int> dataSource;
    int  bufferArray [BUFFER_SIZE];
    Producer *producer;
    Cunsomer *consumer;
};
#endif // WIDGET_H
