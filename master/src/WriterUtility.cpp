#include "WriterUtility.h"

namespace tinylog
{
namespace utility
{

std::string DateTime::GetIt()
{
    namespace pt = boost::posix_time;
    return pt::to_simple_string(pt::second_clock::local_time());
}

std::string ThreadId::GetIt()
{
    std::stringstream sstr;
    boost::thread::id ThisID = boost::this_thread::get_id();
    sstr << "[THRID=" << ThisID << "]";
    return sstr.str();
}

}

}
