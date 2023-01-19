#ifndef MATHEXPRESSIONS_H
#define MATHEXPRESSIONS_H

#include <string>
#include <iterator>
#include "CalcMathTrigFunc.h"
#include "arithoperations.h"
#include "CalcMathLog.h"
#include "CalcMathFactorial.h"
#include "CalcMathSqrt.h"
#include "CalcMathPow.h"
#include <QString>
#include "CalcMathPercents.h"
class MathExpressions
{
public:
    MathExpressions();
    void CalculateMathExp(std::string&);
    static void ReplacingSigns(QString&);

private:
    void OpeningBrackets(std::string& mathExp, std::string::iterator& begin, std::string::iterator& end, std::string::iterator& verhEnd);
    std::string ApplicationFuncCalc(std::string mathExp);
    bool  getTextFromBrackets(std::string& mathExp, std::string::iterator& begin, std::string::iterator& end, std::string::iterator& verhEnd);
    static void InsertNewSingExp(std::u16string& mathExp,std::u16string Sign,std::u16string newSign);

private:
    CalcMathTrigFunc calcTrigFunc;
    CalcMathPercents calcPercent;
    ArithOperations arithAct;
    CalcMathLog log;
    CalcMathFactorial factorial;
    CalcMathSqrt qsrt;
    CalcMathPow pow;

};

#endif // MATHEXPRESSIONS_H
