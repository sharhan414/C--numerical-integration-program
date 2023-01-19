#include "CalcMathLog.h"
#include <cmath>
#include <vector>
//using namespace  std;
CalcMathLog::CalcMathLog()
{

}

bool CalcMathLog::calculate(std::string &mathExp)
{
    CalculatehLog(mathExp);
    return !isError();
}

void CalcMathLog::CalculatehLog(std::string& mathExp)
{
    std::vector<std::string> fLogs{m_fLn,m_fLog};

    for (std::vector<std::string>::size_type j = 0; j != fLogs.size(); ++j)
    {
        auto  itEnd = mathExp.end();
        auto it =mathExp.begin();

        while ((it= search(it, mathExp.end(), fLogs[j].begin(), fLogs[j].end()) )!= mathExp.end())
        {
            std::string endText=SearchEndText(mathExp,fLogs[j],it,itEnd);
            std::string otvet = resheniya(endText, fLogs[j]);
            if(m_Error)
                return;
            mathExp.erase(it, itEnd);
            it = mathExp.insert(it, otvet.begin(), otvet.end());
        }
    }
}



std::string CalcMathLog::resheniya(std::string& Value, std::string& Func)
{

   int value=int(stdString_toDouble(Value.c_str()));
    if(m_Error)
    {
        return std::string();
    }

    double y{0};
    if(Func==m_fLog)
    {
        y=log10(value)   ;
    }
    if(Func==m_fLn)
    {
        y=log(value);
    }

    return to_stdString(y);
}
