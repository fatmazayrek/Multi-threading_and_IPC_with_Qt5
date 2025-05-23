#ifndef MYMETATYPE_H
#define MYMETATYPE_H

#include <QMetaType>
#include <QDebug>
#include <QObject>

class MyMetaType
{
public:
    MyMetaType(); //You must write it.

    MyMetaType(int value, QString string);

    QString String() const;
    int number() const;

private:
    QString m_String;
    int m_number;
};

Q_DECLARE_METATYPE(MyMetaType)

#endif // MYMETATYPE_H
