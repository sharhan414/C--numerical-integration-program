#ifndef MATHEXPRESSIONS_H
#define MATHEXPRESSIONS_H

#include <string>
#include <iterator>
#include "reshtrigfunc.h"
#include "arifdeyst.h"
#include "log.h"
#include "factorial.h"
#include "sqrt.h"
#include "pow.h"
#include <QString>
#include "calcpercents.h"
class MathExpressions
{
public:
    MathExpressions();
    void CalculateMathExp(std::string&);
    static void ReplacingSigns(QString&);

private:
    void OpeningBrackets(std::string& text, std::string::iterator& begin, std::string::iterator& end, std::string::iterator& verhEnd);
    std::string ApplicationFuncCalc(std::string text);
    bool  getTextFromBrackets(std::string& text, std::string::iterator& begin, std::string::iterator& end, std::string::iterator& verhEnd);
    static void InsertNewSingExp(std::u16string& text,std::u16string Sign,std::u16string newSign);

private:
    ReshTrigFunc trig;
    CalcPercents Proc;
    ArifDeyst arif;
    Log log;
    Factorial factorial;
    Sqrt qsrt;
    Pow pow;

};

#endif // MATHEXPRESSIONS_H
