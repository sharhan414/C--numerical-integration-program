#ifndef CALCPERCENTS_H
#define CALCPERCENTS_H
#include "resheniy.h"

class CalcPercents:public Resheniy
{
public:
   CalcPercents();
    void CalculatePercent(std::string& text);
private:

    std::string CalcPercentsByValues(std::string& beginStrValues, std::string& endStrValues, std::string& Func);
    std::string getOnePercent(std::string& Value);
    double PlusPercens(double, double );
    double MinusPercens(double, double);
    double Percent(double);
    void CalcPercentsFroExp(std::string& mathExp, std::string percentType);
};

#endif // CALCPERCENTS_H
