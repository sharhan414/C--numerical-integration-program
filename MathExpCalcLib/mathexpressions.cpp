#include "mathexpressions.h"
#include <iterator>
#include <algorithm>
#include<QDebug>
//using namespace std;
MathExpressions::MathExpressions()
{

}

void MathExpressions::CalculateMathExp(std::string & mathExp)
{
    std::string::iterator b=mathExp.begin(),e=mathExp.end(),e2=mathExp.end();
    int32_t opens=0,closes=0;
    for(auto it:mathExp)
    {
        if(it=='(')
        {
            opens++;
        }
        if(it==')')
        {
            closes++;
        }
    }
    if(opens!=closes)
    {
        return ;
    }
    OpeningBrackets(mathExp,b,e,e2);
}

std::string MathExpressions::ApplicationFuncCalc(std::string mathExp)
{

    factorial.calculate(mathExp);//вычисляет фактириалы
    calcTrigFunc.calculate(mathExp);//вычисляет тригонометрических функций

    if(calcTrigFunc.isError())//проверка на наличие ошибки при произведения действия
    {
        qDebug()<<"v trig error";
    }

    calcPercent.calculate(mathExp);//вычисляет процент

    log.calculate(mathExp);//вычисляет логарифм
    qsrt.calculate(mathExp);//вычисляет корней
    pow.calculate(mathExp);//вычисляет спепеней

    double answer=arithAct.calcArithExp(mathExp);
    return QString::number(answer).toStdString();
}

/////////////////////////////////////
/// \brief MathExpressions::sleep
/// \param text
/// \param begin
/// \param end
/// \param verhEnd
/////////////////////////////////////////////////////
void MathExpressions::OpeningBrackets(std::string& mathExp, std::string::iterator& begin, std::string::iterator& end, std::string::iterator& verhEnd)
{
//функция для раскрытия скобок

    if(!getTextFromBrackets(mathExp, begin, end, verhEnd ))
        return;
    int bracket_close = 0, bracket_open = 0;//переменные для подсчёта открых и закрытых скобок
    auto it_exp_last = mathExp.end();
    auto it_begin_last = begin;

    while (it_begin_last != end)
    {

        if (*it_begin_last == '(')
        {           //подсчитывает количество открытых скобок
            ++bracket_open;
            if (it_exp_last == mathExp.end())
                it_exp_last = it_begin_last;                  //сохраняет позицию первой открытой скобки
        }
        else if (*it_begin_last == ')')
        {      //подсчитывает количество закрытых скобок
            ++bracket_close;
        }
        if (bracket_close != 0 && bracket_open == bracket_close)
        {        //если количество окрытых и закрытых скобок равно, то
            int64_t ras1 = int64_t(mathExp.size());
            OpeningBrackets(mathExp, ++it_exp_last, it_begin_last,end);
            int64_t ras2 = int64_t(mathExp.size());     //
            int64_t ras =  ras1-ras2;
            verhEnd -= ras;
            if (!getTextFromBrackets(mathExp, begin,end, verhEnd))
                return;		//закрываем нашу функцию
            it_exp_last = mathExp.end();
            bracket_close = 0;
            bracket_open = 0;
        }
        ++it_begin_last;//увеличиваем счетшик на 1
    }
}
bool  MathExpressions::getTextFromBrackets(std::string& mathExp, std::string::iterator& begin, std::string::iterator& end, std::string::iterator& verhEnd)
{

    std::string textskobky(begin, end);//вычисляется текст нашей скобки
    int64_t sizeIshodText = int64_t(mathExp.size());

    if (std::find(textskobky.begin(), textskobky.end(), '(') == textskobky.end() && !textskobky.empty()) //если в нашем тексте нету скобок то
    {
        std::string ansewr = ApplicationFuncCalc(textskobky);//вычисляем ответ арифметических действий в нашем тексте и ответ сохраняем в переменной "otvet"

        if (begin == mathExp.begin() && end==mathExp.end())
        {//
            mathExp.clear();
            mathExp = ansewr;
            begin = mathExp.begin();
            end = mathExp.end();
            verhEnd = end;

         }
        else
        {
            if (begin != mathExp.begin() && end != mathExp.end())
                end = mathExp.erase(begin - 1, end + 1);
            else if (begin == mathExp.begin() && end != mathExp.end())
                end = mathExp.erase(begin , end + 1);
            else if (begin != mathExp.begin() && end == mathExp.end())
                end = mathExp.erase(begin-1, end );

            mathExp.insert(end, ansewr.begin(), ansewr.end());
            end = begin;
            if (begin != mathExp.begin())
            {
                --end;
            }
            int64_t sizeKonechText = int64_t(mathExp.size());
            int64_t raznica = sizeIshodText - sizeKonechText;
            verhEnd = verhEnd - raznica;
         }
             return false;
    }
        else
        return true;
}

void MathExpressions::InsertNewSingExp(std::u16string &mathExp,std::u16string Sign, std::u16string newSign)
{
    auto iter=mathExp.begin();
    while(iter!=mathExp.end())
    {

        iter=std::search(iter,mathExp.end(),Sign.begin(),Sign.end());
        if(iter==mathExp.end())
        {
            break;
        }
        iter=mathExp.erase(iter,iter+Sign.size());
        iter=mathExp.insert(iter,newSign.begin(),newSign.end());
    }
}

void MathExpressions::ReplacingSigns(QString & mathExp)//заменят знаки
{
    auto str=mathExp.toStdU16String();

    InsertNewSingExp(str,u"/√",u"nsqrt");
    InsertNewSingExp(str,u"×",u"*");
    InsertNewSingExp(str,u"÷",u"/");
    InsertNewSingExp(str,u"√",u"sqrt");
    mathExp=mathExp.fromStdU16String(str);

}
