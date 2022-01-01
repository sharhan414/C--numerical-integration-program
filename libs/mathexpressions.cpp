#include "mathexpressions.h"
#include <iterator>
#include <algorithm>
#include<QDebug>
using namespace std;
MathExpressions::MathExpressions()
{

}

void MathExpressions::CalculateMathExp(string & text)
{
    string::iterator b=text.begin(),e=text.end(),e2=text.end();
    OpeningBrackets(text,b,e,e2);
}

string MathExpressions::ApplicationFuncCalc(string text)
{

    factorial.CalculateFactorial(text);//вычисляет фактириалы      
    trig.CalculateTrigFunc(text);//вычисляет тригонометрических функций      
    if(trig.isError())
        qDebug()<<"v trig error";

    Proc.CalculatePercent(text);//вычисляет процент  
    log.CalculatehLog(text);//вычисляет логарифм   
    qsrt.CalculateSqrt(text);//вычисляет корней   
    pow.CalculatePow(text);//вычисляет спепеней   
    double value=0;
    arif.arif_detstvie(value,text);
    return QString::number(value).toStdString();
}

/////////////////////////////////////
/// \brief MathExpressions::sleep
/// \param text
/// \param begin
/// \param end
/// \param verhEnd
/////////////////////////////////////////////////////
void MathExpressions::OpeningBrackets(string& text, string::iterator& begin, string::iterator& end, string::iterator& verhEnd)
{
//функция для раскрытия скобок

    if(!getTextFromBrackets(text, begin, end, verhEnd ))
        return;
    int bracket_close = 0, bracket_open = 0;//переменные для подсчёта открых и закрытых скобок
    auto c = text.end();
    auto i = begin;

    while (i != end)
    {

        if (*i == '(')
        {           //подсчитывает количество открытых скобок
            ++bracket_open;
            if (c == text.end())
                c = i;                  //сохраняет позицию первой открытой скобки
        }
        else if (*i == ')')
        {      //подсчитывает количество закрытых скобок
            ++bracket_close;
        }
        if (bracket_close != 0 && bracket_open == bracket_close)
        {        //если количество окрытых и закрытых скобок равно, то
            int64_t ras1 = int64_t(text.size());
            OpeningBrackets(text, ++c, i,end);
            int64_t ras2 = int64_t(text.size());     //
            int64_t ras =  ras1-ras2;
            verhEnd -= ras;
            if (!getTextFromBrackets(text, begin,end, verhEnd))
                return;		//закрываем нашу функцию
            c = text.end();
            bracket_close = 0;
            bracket_open = 0;
        }
        ++i;//увеличиваем счетшик на 1
    }
}
bool  MathExpressions::getTextFromBrackets(string& text, string::iterator& begin, string::iterator& end, string::iterator& verhEnd)
{

    string textskobky(begin, end);//вычисляется текст нашей скобки
    int64_t sizeIshodText = int64_t(text.size());

    if (find(textskobky.begin(), textskobky.end(), '(') == textskobky.end() && !textskobky.empty()) //если в нашем тексте нету скобок то
    {
        string ansewr = ApplicationFuncCalc(textskobky);//вычисляем ответ арифметических действий в нашем тексте и ответ сохраняем в переменной "otvet"

        if (begin == text.begin() && end==text.end())
        {//
            text.clear();
            text = ansewr;
            begin = text.begin();
            end = text.end();
            verhEnd = end;

         }
        else
        {
            if (begin != text.begin() && end != text.end())
                end = text.erase(begin - 1, end + 1);
            else if (begin == text.begin() && end != text.end())
                end = text.erase(begin , end + 1);
            else if (begin != text.begin() && end == text.end())
                end = text.erase(begin-1, end );

            text.insert(end, ansewr.begin(), ansewr.end());
            end = begin;
            if (begin != text.begin())
                --end;
                int64_t sizeKonechText = int64_t(text.size());
                int64_t raznica = sizeIshodText - sizeKonechText;
                verhEnd = verhEnd - raznica;
         }
             return false;
    }
        else
        return true;
}

void MathExpressions::InsertNewSingExp(u16string &text,u16string Sign, u16string newSign)
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

void MathExpressions::ReplacingSigns(QString & text)//заменят знаки
{
    auto str=text.toStdU16String();
    InsertNewSingExp(str,u"/√",u"nsqrt");
    InsertNewSingExp(str,u"×",u"*");
    InsertNewSingExp(str,u"÷",u"/");
    InsertNewSingExp(str,u"√",u"sqrt");
    text=text.fromStdU16String(str);
}
