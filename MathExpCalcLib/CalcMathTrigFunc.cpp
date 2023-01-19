#include "CalcMathTrigFunc.h"
#include <vector>
#include <cmath>
#include <iostream>

bool CalcMathTrigFunc::calculate(std::string &mathExp)
{
    CalculateTrigFunc(mathExp);
    return !isError();
}

CalcMathTrigFunc::CalcMathTrigFunc()
{
    m_Error=false;
}
void CalcMathTrigFunc::CalculateTrigFunc(std::string& mathExp)
{
    trigonometr(mathExp);
}
std::string CalcMathTrigFunc::Calculate(const std::string& Funk, std::string& Value)
{   
    double DoubleVal=stdString_toDouble(Value),Answer=0;

    if(m_Error)
    {
        return std::string();
    }
    double ugol=angleToRadians(DoubleVal);
    if (Funk == m_fSin)
    {
        Answer=std::sin(ugol);
    }
    else if (Funk == m_fCos)
    {
        Answer=std::cos(ugol);
    }
    else if (Funk == m_fTag)
    {
        Answer=std::tan(ugol);
    }
    else if (Funk == m_fCTag)
    {
        Answer=1.0/std::tan(ugol);
    }

    if (Funk == m_fArcSin)
    {
        if(DoubleVal>1 || DoubleVal<-1)
        {
            m_Error=true;
            return std::string();
        }
        Answer=std::asin(DoubleVal)*(180/Math_Pi);    
    }
    else if (Funk == m_fArcCos)
    {
        if(DoubleVal>1 || DoubleVal<-1)
        {
            m_Error=true;
            return std::string();
        }

        Answer=std::acos(DoubleVal)*(180/Math_Pi);
    }
    else if (Funk == m_fArcTag)
    {
        Answer=std::atan(DoubleVal)*(180/Math_Pi);
    }

    else if (Funk == m_fArcCTag)
    {
        Answer=1.0/std::atan(DoubleVal)*(180/Math_Pi);
    }

    return to_stdString(Answer);
}

double CalcMathTrigFunc::angleToRadians(double & x)
{
    return x/(180/Math_Pi);
}

void CalcMathTrigFunc::trigonometr(std::string& mathExp)
{
    auto fTrigCalc=[this](const std::string&trigFunc, std::string& mathExp)
    {
        auto it =mathExp.begin();
        while ((it=search(it, mathExp.end(), trigFunc.begin(), trigFunc.end()) )!= mathExp.end())//в условии проверяется есть ли данная фун-я в выражении
        {
            auto endIt = it ;
            std::string EndText = SearchEndText(mathExp,trigFunc,it,endIt);

            std::string Answer = Calculate(trigFunc, EndText);

            if(m_Error)
            {
                return ;
            }
            mathExp.erase(it, endIt);
            it=mathExp.insert(it, Answer.begin(), Answer.end());
         }
    };

    fTrigCalc(m_fCos,mathExp);
    fTrigCalc(m_fSin,mathExp);
    fTrigCalc(m_fTag,mathExp);
    fTrigCalc(m_fCTag,mathExp);

    fTrigCalc(m_fArcCos,mathExp);
    fTrigCalc(m_fArcSin,mathExp);
    fTrigCalc(m_fArcTag,mathExp);
    fTrigCalc(m_fArcCTag,mathExp);


    /*
    std::vector<std::string> tr_funcs{"asin","acos","atag","sin","cos","tag"};

    for (auto tr_func:tr_funcs)
    {

        auto it =mathExp.begin();
        while ((it=search(it, mathExp.end(), tr_func.begin(), tr_func.end()) )!= mathExp.end())//в условии проверяется есть ли данная фун-я в выражении
        {
            auto endIt = it ;
            std::string EndText = SearchEndText(mathExp,tr_func,it,endIt);

            std::string Answer = Calculate(tr_func, EndText);

            if(m_Error)
            {
                return ;
            }

            mathExp.erase(it, endIt);
            it=mathExp.insert(it, Answer.begin(), Answer.end());
         }
     }
     */
}
