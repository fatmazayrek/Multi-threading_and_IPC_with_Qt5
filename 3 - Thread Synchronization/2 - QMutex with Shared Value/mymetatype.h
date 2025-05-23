#ifndef MYMETATYPE_H
#define MYMETATYPE_H

#include <QMetaType>


class myMetaType
{
public:
    myMetaType();
    myMetaType(QString id, int counter);

    QString getId() const;
    int counter() const;

private:
    QString m_id;
    int m_counter;
};

Q_DECLARE_METATYPE(myMetaType)
#endif // MYMETATYPE_H
