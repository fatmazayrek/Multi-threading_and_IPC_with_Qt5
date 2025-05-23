#include "readclass.h"

ReadClass::ReadClass()
{
    m_count = 0;
}

QString ReadClass::print(const QString &text)
{
    QReadLocker r_locker(&m_lock);

    QString message(QString("%1 : %2").arg(text).arg(m_count));

    return message;
}

void ReadClass::increment()
{
    QWriteLocker m_locker(&m_lock);

    m_count++;
}

int ReadClass::count() const
{
    return m_count;
}
