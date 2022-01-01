#ifndef RESHENIY_H
#define RESHENIY_H

#include <algorithm>

#include <string>
#include <cmath>
#include <iterator>

class Resheniy
{
public:
    Resheniy();
    bool isError()
    {
        return Error;
    }
    static std::string to_stdString(double);
    double stdString_toDouble(std::string strValues);
    template<class Str>
    void InsertNewSingExp(Str &text,Str Sign, Str newSign);

protected:
    std::string SearchBeginText(std::string&,std::string::iterator&,std::string::iterator&) ;
    std::string SearchEndText(std::string&,std::string,std::string::iterator&,std::string::iterator&) ;
    bool Error=false;
    const std::string UserChars = "0123456789.";

};

#endif // RESHENIY_H
