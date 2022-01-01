#include "factorial.h"
using namespace std;
Factorial::Factorial()
{

}
void Factorial::CalculateFactorial(string& text)
{
    string factorials = "!";
    auto itBegin = text.end();
    auto it = text.begin();

    while ((it= search(it, text.end(), factorials.begin(), factorials.end())) != text.end())
    {
        string beginText=SearchBeginText(text,it,itBegin);
        string otvet = resheniya(beginText);
        text.erase(itBegin, it+1);
        it = text.insert(itBegin, otvet.begin(), otvet.end());
    }
}
string Factorial::resheniya(string& Znachenie)
{    
    int value= atoi(Znachenie.c_str());//QStrText.toInt(&error);
    int fact=factorial(value);
    return to_stdString(fact);
}
