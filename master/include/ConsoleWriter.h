#ifndef CONSOLEWRITER_H
#define CONSOLEWRITER_H

#include "tinylog.h"
#include "WriterUtility.h"

namespace tinylog
{

class ConsoleWriter : public IWriter
{
    public:
        ConsoleWriter();
        virtual ~ConsoleWriter();

        virtual const char* prewrite();
        virtual void write(const char* str);
        virtual const char* postwrite();
    protected:
    private:
};

class ToNowhere : public IWriter
{
public:
    virtual ~ToNowhere() {};
    virtual const char* prewrite() { return ""; }
    virtual void write(const char* str) { return; }
    virtual const char* postwrite() { return ""; }
};

}

#endif // CONSOLEWRITER_H
