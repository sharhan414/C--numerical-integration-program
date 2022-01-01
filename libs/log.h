#ifndef LOG_H
#define LOG_H
#include "resheniy.h"

class Log:public Resheniy
{
public:
    Log();

void CalculatehLog(std::string& text);
private:
    std::string resheniya(std::string&,std::string&);
};

#endif // LOG_H
