#include "solvfunction.h"
//#include <resh.h>
#include <QString>
#include <MathExpCalcLib/MathExpFunction.h>
#include <MathExpCalcLib/mathexpressions.h>
SolvFunction::SolvFunction(std::string added_func)
{
    func=added_func;
}

std::string SolvFunction::addValuesToFunc(double values)
{
    std::string temporary_func=func;

    std::string str_values=MathExpFunction::to_stdString(values);
    auto it=temporary_func.begin();

    while(it!=temporary_func.end())
    {
        if(*it=='x')
        {
            temporary_func.erase(it);
            it=temporary_func.insert(it,str_values.begin(),str_values.end());
        }

        ++it;
    }
    return temporary_func;
}
double SolvFunction::getSolvFunction(double x)
{
    std::string temp_func=addValuesToFunc(x);

    MathExpressions mth;
    mth.CalculateMathExp(temp_func);

    return QString(temp_func.c_str()).toDouble();

}

double SolvFunction::operator()(double x)
{
    return getSolvFunction(x);
}
