#include "main.h"


BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}

namespace tinylog
{

DLL_EXPORT ILog* CreateLog(IWriter* writer)
{
  try
  {
    ILog* log(nullptr);
    if (writer == nullptr)
    {
        log = new Speaker(new ToNowhere());
    }
    else
    {
        log = new Speaker(writer);
    }
    return log;
  }
  catch(...)
  {
      return nullptr;
  }
}

DLL_EXPORT IWriter* ToConsole()
{
  try
  {
    IWriter* writer = new ConsoleWriter();
    return writer;
  }
  catch(...)
  {
      return nullptr;
  }
}

DLL_EXPORT IWriter* ToFile(const char* path)
{
  try
  {
    IWriter* writer = new FileWriter(path);
    return writer;
  }
  catch(...)
  {
      return nullptr;
  }
}

}
