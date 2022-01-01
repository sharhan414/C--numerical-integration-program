#include "pow.h"
#include <iterator>

using namespace std;
Pow::Pow()
{

}

string Pow::resheniya(string& StrBeginValue,string& StrEndValue)
{

    double DBeginValue=stdString_toDouble(StrBeginValue);//приобразем behinText в число
    double DEndValue= stdString_toDouble(StrEndValue);//приобразем endText в число

    if(Error)
        return string();

    double DOtvet=pow(DBeginValue,DEndValue);

    return to_stdString(DOtvet);
}

void Pow::CalculatePow(string& text)
{
    string pow = "^";

    auto itBegin = text.end(), itEnd = text.end();
    auto it = text.begin();

    while ((it = search(it, text.end(), pow.begin(), pow.end())) != text.end())
    {
        string beginText, endText;

        beginText=SearchBeginText(text,it,itBegin); // search begin text
        endText=SearchEndText(text,pow,it,itEnd);   // search end text

        string otvet = resheniya(beginText, endText);
        text.erase(itBegin, itEnd);
        it = text.insert(itBegin, otvet.begin(), otvet.end());      
    }
}

