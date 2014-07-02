#include "Speaker.h"

namespace tinylog
{

    using namespace std;

void SpeakerThr(Speaker* pParam)
{
    std::shared_ptr<std::string> str;

    while(!pParam->m_finish)
    {
        str = pParam->m_messages.Get();
        if (str != nullptr)
        {
            pParam->m_writer->write((*str).c_str());
        }
    }
    return;
}

}
