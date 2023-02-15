#include "progressevent.h"

ProgressEvent::ProgressEvent(int progress): QEvent(static_cast<Type>(EventId)),
    m_progress(progress)
{

}

int ProgressEvent::progress() const
{
    return m_progress;
}
