//---------------------------------------------------------------------------

#ifndef SaveListH
#define SaveListH

#include <memory>
#include <queue>
#include <atomic>
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include <boost/thread/condition.hpp>

namespace SafeStl
{
using namespace std;

template<typename T>
class SafeQueue : boost::noncopyable
{
    public:
		SafeQueue() { m_finish = false; }
        virtual ~SafeQueue() { OrderFinish(); }

        inline shared_ptr<T> Get()
        {
            boost::mutex::scoped_lock lock(m_mutex_messages_access);
            while (m_collection.empty() && !m_finish)
            {
                cond.wait(lock);
            }
            if (m_finish)
                return shared_ptr<T>(nullptr);

            shared_ptr<T> ret = m_collection.front();
            m_collection.pop();
            return ret;
        }

        inline void Push(shared_ptr<T> val)
        {
            boost::mutex::scoped_lock lock(m_mutex_messages_access);
            m_collection.push(val);
            lock.unlock();
            cond.notify_one();
        }
        inline void OrderFinish()
        {
            m_finish = true;
            cond.notify_one();
        }
    protected:
    private:
        atomic_bool m_finish;
        boost::mutex m_mutex_messages_access;
        boost::condition_variable cond;

        std::queue<shared_ptr<T> > m_collection;
};

}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
#endif
