#ifndef COMMONDATA_H
#define COMMONDATA_H

#include <QObject>
#include <QString>

class CommonData
{
public:
    CommonData();
    CommonData(QString name, int *pointer, int number);

    QString m_name;
    int *m_pointer;
    int m_number;
};

Q_DECLARE_METATYPE(CommonData)

#endif // COMMONDATA_H
