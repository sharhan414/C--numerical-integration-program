#include "MathExpFunction.h"
#include <QString>
#include <iostream>
//using namespace std;
MathExpFunction::MathExpFunction()
{
    m_Error=false;

}

std::string MathExpFunction::to_stdString(double values)
{
    return QString::number(values,'f',15).toStdString();
}

double MathExpFunction::stdString_toDouble(std::string strValues)
{

    QString QStrVal=QString::fromStdString(strValues);
    auto answer=QStrVal.toDouble(&m_Error);
    m_Error= !m_Error;
    return answer;
}

std::string MathExpFunction::SearchBeginText(std::string& mathExp,std::string::iterator& it,std::string::iterator& itBegin)
{
    auto n_it = it;
    do {////////begin text
        --n_it;
        if (find(UserChars.begin(), UserChars.end(), *n_it) == UserChars.end())
        {
            std::string Textproc(n_it + 1, it);
            itBegin = n_it + 1;
            return Textproc;

        }
        else if (n_it == mathExp.begin())
        {
            std::string Textproc(n_it, it);
            itBegin = n_it;
            return Textproc;

        }

    } while (n_it != mathExp.begin());
}

std::string MathExpFunction::SearchEndText(std::string & mathExp, std::string funk, std::string::iterator &it,std::string::iterator &itEnd)
{

    for (auto i = it + int(funk.size()); i != mathExp.end(); ++i)
    {
        if(*(i)=='-')//если после фун-и стоить знак -, то его включаем а значение
        {
             i++;
        }
        if (find(UserChars.begin(), UserChars.end(), *i) == UserChars.end())
        {
            std::string value(it + int64_t(funk.size()), i);
            itEnd = i;
            return value;
        }
        else if (i == mathExp.end() - 1)
        {
            std::string value(it + int64_t(funk.size()), i + 1);
            itEnd = i + 1;
            return value;
        }
    }
}


template<class MathExp>
void MathExpFunction::replMathExp(MathExp &mathExp, MathExp Sign,MathExp newSign)
{

    auto iter=mathExp.begin();
    while(iter!=mathExp.end())
    {

        iter=search(iter,mathExp.end(),Sign.begin(),Sign.end());
        if(iter==mathExp.end())
        {
            break;
        }
        iter=mathExp.erase(iter,iter+Sign.size());
        iter=mathExp.insert(iter,newSign.begin(),newSign.end());
    }

}
