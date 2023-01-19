#ifndef LOG_H
#define LOG_H
#include "MathExpFunction.h"

class CalcMathLog:public MathExpFunction
{
public:
    CalcMathLog();
    virtual ~CalcMathLog(){}
    void CalculatehLog(std::string& mathExp);
    bool calculate(std::string& mathExp) override;
private:
    std::string resheniya(std::string&,std::string&);

    std::string m_fLog="log";//обозначение логарифма
    std::string m_fLn="ln";//обозначение логарифма
};

#endif // LOG_H
