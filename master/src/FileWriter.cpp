#include "FileWriter.h"

namespace tinylog
{

FileWriter::~FileWriter()
{
    //dtor
}

void FileWriter::write(const char* str)
{
    std::fstream resfile(m_filename, std::fstream::out|std::fstream::app);
    resfile << str << std::endl;
}

const char* FileWriter::prewrite()
{
    std::stringstream resstr;
    tinylog::utility::DateTime DT;
    tinylog::utility::ThreadId TI;
    resstr << DT.GetIt() << " " << TI.GetIt() << " ";
    return resstr.str().c_str();
}

const char* FileWriter::postwrite()
{
    return "";
}

}
