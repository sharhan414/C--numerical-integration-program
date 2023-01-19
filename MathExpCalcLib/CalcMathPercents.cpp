#include "CalcMathPercents.h"
#include <iostream>
//using namespace std;
CalcMathPercents::CalcMathPercents()
{

}
bool CalcMathPercents::calculate(std::string &mathExp)
{
    CalculatePercent(mathExp);
    return !isError();
}

std::string CalcMathPercents::getOnePercent(std::string& strValue)
{

    double x=stdString_toDouble(strValue) ;//  text.toDouble(&error);
    x=Percent(x);
    return to_stdString(x);
}
double CalcMathPercents::PlusPercens(double Value, double Percents)
{
    Percents /= 100;
    Percents += 1;
    Value *= Percents;
    return Value;
}
double CalcMathPercents::MinusPercens(double Value, double Percents)
{
    Percents /= 100;
    Percents = 1 - Percents;
    Value *= Percents;
    return Value;
}

double CalcMathPercents::Percent(double x)
{
    return x/100;
}

void CalcMathPercents::CalcPercentsFroExp(std::string &mathExp, std::string percentType)
{

    auto itBegin = mathExp.end(), itEnd = mathExp.end();
    auto it = mathExp.begin();

    while ((it = std::search(it, mathExp.end(), percentType.begin(), percentType.end())) != mathExp.end())
    {
        std::string beginStrValue, endStrValue;

        beginStrValue=SearchBeginText(mathExp,it,itBegin); //begin text

        if(percentType==m_oneProcent)
        {
            std::string otvet = getOnePercent(beginStrValue);
            mathExp.erase(itBegin, it+1);
            it = mathExp.insert(itBegin, otvet.begin(), otvet.end());
            continue;
        }

        endStrValue=SearchEndText(mathExp,percentType,it,itEnd);  //end text

        std::string strAnswer = CalcPercentsByValues(beginStrValue, endStrValue, percentType);
        mathExp.erase(itBegin, itEnd);
        it = mathExp.insert(itBegin, strAnswer.begin(), strAnswer.end());

    }
}

std::string CalcMathPercents::CalcPercentsByValues(std::string& strValue, std::string& strPercents, std::string& Func)
{
    double Value=stdString_toDouble(strValue) ;//BeginZnach.toDouble(&error);
    double Percents=stdString_toDouble(strPercents) ;
    if(!m_Error)
    {
        return std::string();
    }
    double Answer=0;
    if(Func==m_incProcent)
    {
        Answer= PlusPercens(Value,Percents);
    }
    if(Func == m_redProcent)
    {
        Answer= MinusPercens(Value,Percents);
    }
    return  to_stdString(Answer);
}

void CalcMathPercents::CalculatePercent(std::string& mathExp)
{
    CalcPercentsFroExp(mathExp,m_incProcent);
    CalcPercentsFroExp(mathExp,m_redProcent);
    CalcPercentsFroExp(mathExp,m_oneProcent);
}


