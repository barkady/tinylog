#ifndef SPEAKER_H
#define SPEAKER_H

#include "tinylog.h"
#include "SaveList.hpp"

#include <boost/thread/thread.hpp>
//#include <boost/utility.hpp>

/** \brief namespace for logging
 */
namespace tinylog
{

/** \brief class for logging
  */
class Speaker;
/** \brief Thread function
  */
void SpeakerThr(Speaker* pParam);

#ifdef _MSC_VER
typedef class AtomicWrapper
{
	std::atomic_bool m_finish;
public:
	AtomicWrapper(bool val)
	{
		m_finish = val;
	}
	AtomicWrapper& operator = (bool val) { m_finish = val; return *this; }
	operator bool() { return m_finish; }
} atomic_bool_wrapper;
#else
typedef std::atomic_bool atomic_bool_wrapper;
#endif


class Speaker : public ILog
{
    public:
        friend void SpeakerThr(Speaker* pParam);

        Speaker(IWriter* writer) : m_finish(false), m_thread( boost::bind(&SpeakerThr, this) ), m_writer(writer) {}
        virtual ~Speaker()
        {
            m_messages.OrderFinish();
            m_finish = true;
            m_thread.join();
        }
        virtual void add(const char* str)
        {
            std::stringstream resstr;
            resstr << m_writer->prewrite() << str << m_writer->postwrite();
            m_messages.Push(std::make_shared<std::string>(resstr.str()));
            return;// str;
        }

    protected:

    private:
		atomic_bool_wrapper m_finish;
        boost::thread m_thread;
        SafeStl::SafeQueue<std::string> m_messages;
        std::shared_ptr<IWriter> m_writer;

};

}
#endif // SPEAKER_H
