#include "ConsoleWriter.h"

namespace tinylog
{

ConsoleWriter::ConsoleWriter()
{
    //ctor
}

ConsoleWriter::~ConsoleWriter()
{
    //dtor
}

void ConsoleWriter::write(const char* str)
{
    std::cout << str << std::endl;
}

const char* ConsoleWriter::prewrite()
{
    tinylog::utility::ThreadId TI;
    return std::string(TI.GetIt() + " ").c_str();
}

const char* ConsoleWriter::postwrite()
{
    return "";
}

}
