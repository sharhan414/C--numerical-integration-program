#include "CalcMathSqrt.h"

//using namespace std;
bool CalcMathSqrt::calculate(std::string &mathExp)
{
    CalculateSqrt(mathExp);
    return !isError();
}

CalcMathSqrt::CalcMathSqrt()
{

}

void CalcMathSqrt::CalculateSqrt(std::string& mathExp)
{
    CalculateNSqtn(mathExp);
    Calculate2Sqrt(mathExp);
}

void CalcMathSqrt::CalculateNSqtn(std::string& mathExp){

    auto itBegin = mathExp.end(), itEnd = mathExp.end();
    auto it =mathExp.begin();

    while ((it=std::search(it, mathExp.end(), m_nSqrt.begin(), m_nSqrt.end())) != mathExp.end())
    {
        std::string beginText, endText;

        beginText=SearchBeginText(mathExp,it,itBegin); // search begin text
        endText=SearchEndText(mathExp,m_nSqrt,it,itEnd);   // search end text
        std::string otvet = resheniya(beginText, endText);
        mathExp.erase(itBegin, itEnd);
        it = mathExp.insert(itBegin, otvet.begin(), otvet.end());
    }
}
void CalcMathSqrt::Calculate2Sqrt(std::string& mathExp)
{
    auto it = std::search(mathExp.begin(), mathExp.end(), m_Sqrt.begin(), m_Sqrt.end());

    while (it != mathExp.end())
    {
        auto endIt = it;
        std::string strValue = SearchEndText(mathExp,m_Sqrt,it,endIt);
        std::string Answer = getMathSqrtAnswer(strValue);
        it=mathExp.erase(it,it+m_Sqrt.size()+strValue.size());
        it=mathExp.insert(it,Answer.begin(),Answer.end());
        it = std::search(mathExp.begin(), mathExp.end(), m_Sqrt.begin(), m_Sqrt.end());
    }
}
std::string CalcMathSqrt::getMathSqrtAnswer(std::string& strValue)
{
    double Value=stdString_toDouble(strValue);
    double AnswerVal=sqrt(Value);
    return to_stdString(AnswerVal);
}

std::string CalcMathSqrt::resheniya(std::string& beginText, std::string& endText)
{
    if(beginText.empty())
    {
        m_Error=true;
        return std::string();
    }

    double DBeginValue=stdString_toDouble(beginText);
    double DEndValue=stdString_toDouble(endText);
    double D_Answer=nsqrt(DEndValue,DBeginValue);

    return to_stdString(D_Answer);
}

double CalcMathSqrt::nsqrt(double x, double y)
{
    if( y == 0.0 || (x<0 && abs(y)-abs(int(y))==0 && abs(int(y))%2==0))
    {
        m_Error=true;
        return 0;
    }
    return pow(x, 1/y);
}

double CalcMathSqrt::sqrt(double x)
{
    if(x<0)
    {
        m_Error=true;
        return 0;
    }
    return pow(x, 0.5);
}
