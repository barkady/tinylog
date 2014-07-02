#ifndef TINYLOG_H_INCLUDED
#define TINYLOG_H_INCLUDED

#ifdef NOT_BUILD_DLL
    #define DLL_EXPORT __declspec(dllimport)
#else
    #define DLL_EXPORT __declspec(dllexport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

namespace tinylog
{
    class IWriter
    {
    public:
        virtual ~IWriter() {};
        virtual const char* prewrite() = 0;
        virtual void write(const char* str) = 0;
        virtual const char* postwrite() = 0;
    };

    class ILog
    {
    public:
        virtual ~ILog() {};
        virtual void add(const char* str) = 0;
    };

DLL_EXPORT IWriter* ToConsole();
DLL_EXPORT IWriter* ToFile(const char* path);
DLL_EXPORT ILog* CreateLog(IWriter* writer);

}
#ifdef __cplusplus
}
#endif
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
//Wrappers for make using it easily
#include <string>
//#include <ostream>
#include <memory>

    class LogW
    {
    public:
        LogW() : m_Log(tinylog::CreateLog(nullptr))
        {
        }
        LogW(const std::string& path) : m_Log(tinylog::CreateLog(tinylog::ToFile(path.c_str())))
        {
        }
        LogW(const char* path) : m_Log(tinylog::CreateLog(tinylog::ToFile(path)))
        {
        }
        void ToConsole()
        {
            std::shared_ptr<tinylog::ILog> temp(tinylog::CreateLog(tinylog::ToConsole()));
            m_Log.swap(temp);
        }
        LogW(LogW& L)
        {
            *this = L;
        }
        LogW& operator=(LogW& L)
        {
            m_Log = L.m_Log;
            return *this;
        }
        void operator<<(const char* str)
        {
            m_Log->add(str);
        }
        void operator<<(const std::string& str)
        {
            m_Log->add(str.c_str());
        }

    private:
        std::shared_ptr<tinylog::ILog> m_Log;
    };


#endif // TINYLOG_H_INCLUDED
