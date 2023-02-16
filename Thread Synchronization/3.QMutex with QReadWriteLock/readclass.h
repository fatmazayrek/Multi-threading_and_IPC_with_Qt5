#ifndef READCLASS_H
#define READCLASS_H

#include <QString>
#include <QReadWriteLock>
#include <QReadLocker>
#include <QDebug>

class ReadClass
{
public:
    ReadClass();

    QString print(const QString &text);
    void increment();

    int count() const;

private:
    int m_count;
    QReadWriteLock m_lock;
};

#endif // READCLASS_H
