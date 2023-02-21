#include "customdata.h"

CustomData::CustomData()
    : m_name(),
      m_pointer(nullptr),
      m_number(-1)
{

}

CustomData::CustomData(QString name, int *pointer, int number)
    : m_name(name),
      m_pointer(pointer),
      m_number(number)
{

}
