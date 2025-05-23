#include "mymetatype.h"

MyMetaType::MyMetaType()
{

}

MyMetaType::MyMetaType(int value, QString string): m_String(string), m_number(value)
{

}

QString MyMetaType::String() const
{
    return m_String;
}

int MyMetaType::number() const
{
    return m_number;
}
