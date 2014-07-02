#ifndef WRITERUTILITY_H
#define WRITERUTILITY_H

#include <string>
#include <sstream>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/thread/thread.hpp>

namespace tinylog
{
namespace utility
{

class IUtility
{
public:
    virtual ~IUtility() {};
    virtual std::string GetIt() = 0;
};

class DateTime : public IUtility
{
public:
    virtual ~DateTime() {};
    virtual std::string GetIt();
};

class ThreadId : public IUtility
{
public:
    virtual ~ThreadId() {};
    virtual std::string GetIt();
};
}

}

#endif // WRITERUTILITY_H
