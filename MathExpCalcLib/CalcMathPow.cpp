#include "CalcMathPow.h"
#include <iterator>
#include <iostream>
//using namespace std;
CalcMathPow::CalcMathPow()
{

}

bool CalcMathPow::calculate(std::string &mathExp)
{
    CalculatePow(mathExp);
    return !isError();
}

std::string CalcMathPow::resheniya(std::string& StrBeginValue, std::string& StrEndValue)
{

    double DBeginValue=stdString_toDouble(StrBeginValue);//приобразем behinText в число
    double DEndValue= stdString_toDouble(StrEndValue);//приобразем endText в число

    if(m_Error)
    {
        return std::string();
    }

    double DOtvet=pow(DBeginValue,DEndValue);

    return to_stdString(DOtvet);
}

void CalcMathPow::CalculatePow(std::string& mathExp)
{
    std::string pow = "^";

    auto itBegin = mathExp.end(), itEnd = mathExp.end();
    auto it = mathExp.begin();

    while ((it = std::search(it, mathExp.end(), pow.begin(), pow.end())) != mathExp.end())
    {
        std::string beginText, endText;

        beginText=SearchBeginText(mathExp,it,itBegin); // search begin text
        endText=SearchEndText(mathExp,pow,it,itEnd);   // search end text
        std::string otvet = resheniya(beginText, endText);
        mathExp.erase(itBegin, itEnd);
        it = mathExp.insert(itBegin, otvet.begin(), otvet.end());
    }
}

