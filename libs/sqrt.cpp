#include "sqrt.h"

using namespace std;
Sqrt::Sqrt()
{

}

void Sqrt::CalculateSqrt(string& text)
{
    CalculateNSqtn(text);
    Calculate2Sqrt(text);
}

void Sqrt::CalculateNSqtn(string& text){
    string nsqrn = "nsqrt";

    auto itBegin = text.end(), itEnd = text.end();
    auto it =text.begin();

    while ((it=search(it, text.end(), nsqrn.begin(), nsqrn.end())) != text.end())
    {
        string beginText, endText;

        beginText=SearchBeginText(text,it,itBegin); // search begin text
        endText=SearchEndText(text,nsqrn,it,itEnd);   // search end text
        string otvet = resheniya(beginText, endText);
        text.erase(itBegin, itEnd);
        it = text.insert(itBegin, otvet.begin(), otvet.end());
    }
}
void Sqrt::Calculate2Sqrt(string& text)
{
    string Sqrt = "sqrt";
    auto it = search(text.begin(), text.end(), Sqrt.begin(), Sqrt.end());

    while (it != text.end())
    {
        auto endIt = it;
        string strValue = SearchEndText(text,Sqrt,it,endIt);
        string Answer = getMathSqrtAnswer(strValue);
        it=text.erase(it,it+Sqrt.size()+strValue.size());
        it=text.insert(it,Answer.begin(),Answer.end());
        it = search(text.begin(), text.end(), Sqrt.begin(), Sqrt.end());
    }
}
string Sqrt::getMathSqrtAnswer(string& strValue)
{
    double Value=stdString_toDouble(strValue);
    double AnswerVal=sqrt(Value);
    return to_stdString(AnswerVal);
}

string Sqrt::resheniya(string& behinText, string& endText)
{
    if(behinText.empty())
    {
        Error=true;
        return string();
    }

    double DBeginValue=stdString_toDouble(behinText);
    double DEndValue=stdString_toDouble(endText);
    double D_Answer=nsqrt(DEndValue,DBeginValue);

    return to_stdString(D_Answer);
}
