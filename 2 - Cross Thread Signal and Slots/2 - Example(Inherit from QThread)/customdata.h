#ifndef CUSTOMDATA_H
#define CUSTOMDATA_H

#include <QObject>
#include <QString>

class CustomData
{
public:
    CustomData();
    CustomData(QString name, int *pointer, int number);

    QString m_name;
    int *m_pointer;
    int m_number;
};

Q_DECLARE_METATYPE(CustomData)
//Don't forget to write qRegisterMetaType<CustomData>(); into the main.cpp

#endif // CUSTOMDATA_H
