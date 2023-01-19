#ifndef POW_H
#define POW_H
#include "MathExpFunction.h"

class CalcMathPow:public MathExpFunction
{
public:
    CalcMathPow();
    virtual ~CalcMathPow(){}

    bool calculate(std::string& mathExp) override;
    void CalculatePow(std::string&);
private:
    std::string resheniya(std::string& StrBeginValue,std::string&StrEndValue);

};

#endif // POW_H
