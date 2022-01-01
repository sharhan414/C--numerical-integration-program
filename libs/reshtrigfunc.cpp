#include "reshtrigfunc.h"
#include <vector>
using namespace std;
ReshTrigFunc::ReshTrigFunc()
{

}
void ReshTrigFunc::CalculateTrigFunc(string& text)
{
    trigonometr(text);
}
string ReshTrigFunc::resheniya(string& Funk, string& Value)
{   
    double DoubleVal=stdString_toDouble(Value),Ancwer=0;

    if(!Error)
        return string();

    double ugol=UgolToradians(DoubleVal);
    if (Funk == "sin")
    {
        Ancwer=sin(ugol);
    }
    else if (Funk == "cos")
    {
        Ancwer=cos(ugol);
    }
    else if (Funk == "tag")
    {
        Ancwer=tan(ugol);
    }

    if (Funk == "asin")
    {
        if(DoubleVal>1 || DoubleVal<-1)
        {
            Error=true;
            return string();
        }
        Ancwer=asin(DoubleVal);
    }
    else if (Funk == "acos")
    {
        if(DoubleVal>1 || DoubleVal<-1)
        {
            Error=true;
            return string();
        }
        Ancwer=acos(DoubleVal);
    }
    else if (Funk == "atag")
    {
        Ancwer=atan(DoubleVal);
    }

    return to_stdString(Ancwer);
}

double ReshTrigFunc::UgolToradians(double & x)
{
    return x/(180/Pi);
}

void ReshTrigFunc::trigonometr(string& text)
{
    vector<string> v{"asin","acos","atag","sin","cos","tag"};

    for (vector<string>::size_type j = 0; j != v.size(); ++j)
    {

        auto it =text.begin();
        while ((it=search(it, text.end(), v[j].begin(), v[j].end()) )!= text.end())
        {

            auto endIt = it ;
            string EndText = SearchEndText(text,v[j],it,endIt);
            string otvet = resheniya(v[j], EndText);

            if(!Error)
            {
                return ;
            }

            text.erase(it, endIt);
            it=text.insert(it, otvet.begin(), otvet.end());
         }
     }
}
