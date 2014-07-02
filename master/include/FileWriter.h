#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "tinylog.h"
#include "WriterUtility.h"
#include <fstream>
#include <sstream>

namespace tinylog
{

class FileWriter : public IWriter
{
    public:
        FileWriter(const char* filename) : m_filename(filename) {}
        virtual ~FileWriter();

        virtual const char* prewrite();
        virtual void write(const char* str);
        virtual const char* postwrite();
    protected:
    private:
        std::string m_filename;
};


}
#endif // FILEWRITER_H
