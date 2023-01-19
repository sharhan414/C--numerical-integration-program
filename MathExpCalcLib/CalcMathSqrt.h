#ifndef SQRT_H
#define SQRT_H
#include "MathExpFunction.h"

class CalcMathSqrt:public MathExpFunction
{
public:    
    CalcMathSqrt();    
    virtual ~CalcMathSqrt(){}
    bool calculate(std::string& mathExp) override;

    void CalculateSqrt(std::string&);
    void CalculateNSqtn(std::string&);
    void Calculate2Sqrt(std::string&);
    std::string getMathSqrtAnswer(std::string&);
    std::string resheniya(std::string& ,std::string&);

    double nsqrt(double x, double y);
    double sqrt(double x);

private:
    std::string m_nSqrt = "nsqrt";
    std::string m_Sqrt = "sqrt";
};

#endif // SQRT_H
