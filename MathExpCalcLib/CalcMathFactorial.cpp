#include "CalcMathFactorial.h"
//using namespace std;
CalcMathFactorial::CalcMathFactorial()
{

}

bool CalcMathFactorial::calculate(std::string &mathExp)
{
    CalculateFactorial(mathExp);
    return !isError();
}

void CalcMathFactorial::CalculateFactorial(std::string& mathExp)
{
    std::string factorials = "!";
    auto itBegin = mathExp.end();
    auto it = mathExp.begin();

    while ((it= std::search(it, mathExp.end(), factorials.begin(), factorials.end())) != mathExp.end())
    {
        std::string beginText=SearchBeginText(mathExp,it,itBegin);
        std::string otvet = resheniya(beginText);
        mathExp.erase(itBegin, it+1);
        it = mathExp.insert(itBegin, otvet.begin(), otvet.end());
    }
}


std::string CalcMathFactorial::resheniya(std::string& Znachenie)
{    
    int value= atoi(Znachenie.c_str());//QStrText.toInt(&error);
    int fact=factorial(value);
    return to_stdString(fact);
}

int CalcMathFactorial::factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
