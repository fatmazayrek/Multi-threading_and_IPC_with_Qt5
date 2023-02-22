#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QFutureWatcher>
#include <QFuture>
#include <QDebug>
#include <QtConcurrent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    static QFuture<QVector<int>> doWork();
    static QVector<int> doInterWork();

private:
    Ui::Widget *ui;

    QFuture<QVector<int>> future;
    QFutureWatcher<QVector<int>> watcher;

private slots:
    void finished();

    void on_start_clicked();
    void on_cancel_clicked();
    void on_pause_clicked();
    void on_resume_clicked();
};
#endif // WIDGET_H
