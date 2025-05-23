#include "mymetatype.h"

myMetaType::myMetaType()
{

}

myMetaType::myMetaType(QString id, int counter): m_id(id), m_counter(counter)
{

}

QString myMetaType::getId() const
{
    return m_id;
}

int myMetaType::counter() const
{
    return m_counter;
}
