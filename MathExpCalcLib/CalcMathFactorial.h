#ifndef FACTORIAL_H
#define FACTORIAL_H
#include "MathExpFunction.h"

class CalcMathFactorial:public MathExpFunction
{
public:
    CalcMathFactorial();
    virtual ~CalcMathFactorial(){}
    bool calculate(std::string& mathExp) override;
private:
    void CalculateFactorial(std::string&);
    std::string resheniya(std::string& );
    int factorial(int n);
};

#endif // FACTORIAL_H
