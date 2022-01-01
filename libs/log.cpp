#include "log.h"
#include <cmath>
#include <vector>
using namespace  std;
Log::Log()
{

}

void Log::CalculatehLog(string& text)
{

    vector<string> v{"ln","log"};

    for (vector<string>::size_type j = 0; j != v.size(); ++j)
    {
        auto  itEnd = text.end();
        auto it =text.begin();

        while ((it= search(it, text.end(), v[j].begin(), v[j].end()) )!= text.end())
        {
            string endText=SearchEndText(text,v[j],it,itEnd);
            string otvet = resheniya(endText, v[j]);
            if(Error)
                return;
            text.erase(it, itEnd);
            it = text.insert(it, otvet.begin(), otvet.end());
        }
    }
}

string Log::resheniya(string& Value,string& Func)
{


   int value=int(stdString_toDouble(Value.c_str()));
    if(Error)
    {
        return string();
    }

    double y{0};
    if(Func=="log")
    {
        y=log10(value)   ;
    }
    if(Func=="ln")
    {
        y=log(value);
    }

    return to_stdString(y);
}
