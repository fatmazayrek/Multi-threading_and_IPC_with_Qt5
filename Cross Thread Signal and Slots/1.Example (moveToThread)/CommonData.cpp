#include "CommonData.h"

CommonData::CommonData()
    : m_name(),
      m_pointer(nullptr),
      m_number(-1)
{

}

CommonData::CommonData(QString name, int *pointer, int number)
    : m_name(name),
      m_pointer(pointer),
      m_number(number)
{

}
