#include "resheniy.h"
#include <QString>
using namespace std;
Resheniy::Resheniy()
{
Error=false;
}

string Resheniy::to_stdString(double values)
{

    return QString::number(values).toStdString();
}

double Resheniy::stdString_toDouble(string strValues)
{
    QString QStrVal=QString::fromStdString(strValues);
    return QStrVal.toDouble(&Error);
}

std::string Resheniy::SearchBeginText(string& text,string::iterator& it,string::iterator& itBegin)
{
    auto k = it;
    do {////////begin text
        --k;
        if (find(UserChars.begin(), UserChars.end(), *k) == UserChars.end())
        {
            string Textproc(k + 1, it);
            itBegin = k + 1;
            return Textproc;

        }
        else if (k == text.begin())
        {
            string Textproc(k, it);
            itBegin = k;
            return Textproc;

        }

    } while (k != text.begin());
}

string Resheniy::SearchEndText(string & text,string funk,string::iterator &it, string::iterator &itEnd)
{

     for (auto i = it + int(funk.size()); i != text.end(); ++i)
     {
         if (find(UserChars.begin(), UserChars.end(), *i) == UserChars.end())
         {
             string Textproc(it + int64_t(funk.size()), i);
             itEnd = i;
             return Textproc;

         }
         else if (i == text.end() - 1)
         {
             string Textproc(it + int64_t(funk.size()), i + 1);
             itEnd = i + 1;
             return Textproc;
         }
     }
}


template<class Str>
void Resheniy::InsertNewSingExp(Str &text, Str Sign,Str newSign)
{

    auto iter=text.begin();
    while(iter!=text.end())
    {

        iter=search(iter,text.end(),Sign.begin(),Sign.end());
        if(iter==text.end())
        {
            break;
        }
        iter=text.erase(iter,iter+Sign.size());
        iter=text.insert(iter,newSign.begin(),newSign.end());
    }
}
