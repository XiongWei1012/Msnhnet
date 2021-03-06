﻿#ifndef MSNHEXCEPTION_H
#define MSNHEXCEPTION_H
#include <exception>
#include <string>
#include "Msnhnet/utils/MsnhExport.h"

namespace Msnhnet
{
class Exception:public std::exception
{
public:

    Exception (int errCode, std::string err, std::string errFile, int errLine):
        err(err),
        errCode(errCode),
        errFile(errFile),
        errLine(errLine)
    {
    }

    Exception()
    {
        err="error";
    }

    virtual const char* what () const noexcept
    {
        return err.data();
    }

    inline std::string getErrFile() const
    {
        return errFile;
    }

    inline int getErrLine() const
    {
        return errLine;
    }

    inline int getErrCode() const
    {
        return errCode;
    }

private:

    std::string err;
    int         errCode;
    std::string errFile;
    int         errLine;
};
}
#endif 

