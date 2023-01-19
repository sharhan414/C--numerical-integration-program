#include "arithoperations.h"

#include "MathExpFunction.h"
#include <algorithm>

//using namespace std;
ArithOperations::ArithOperations()
{

}
bool ArithOperations::calculate(std::string &mathExp)//ещё не реализован
{

}
double ArithOperations::calcArithExp(std::string mathExp)
{
    std::vector<char> ArithmeticSigns;
    std::vector<std::string> ValuesForExp;
    getDatesForExp(mathExp,ValuesForExp,ArithmeticSigns);
    std::vector<double> Answers;

    for(uint64_t i=0;i!=ValuesForExp.size();++i)
    {
        Answers.push_back(stdString_toDouble(ValuesForExp[i]));
    }

    CalcArithExpMultAndDiv(Answers,ArithmeticSigns);//решаеть ариф.действия умножение и деление
    return CalcArithExpPlusAndMinus(Answers,ArithmeticSigns);//решаеть ариф.действия сложение и вычитание
}

// функция для произведения умножения и деления (*,/) т.е. этих действий
void ArithOperations::CalcArithExpMultAndDiv(std::vector<double>& Values, std::vector<char>& ArithmeticSigns)
{
    std::string m = "*/";
    int NumActions = 0,ComplActions=0;//переменные для хранения кол.действий в выраж. и пер. подсчёта выпол-х действий
    for (uint64_t i = 0; i != ArithmeticSigns.size(); ++i)
        if (ArithmeticSigns[i] == m.back() || ArithmeticSigns[i] == m.front())
            ++ComplActions;

    while(NumActions<ComplActions)
    {
        for (size_t i = 0; i != ArithmeticSigns.size(); ++i)
        {
            if (ArithmeticSigns[i] == m.front())
            {
                Values[i] = Values[i] * Values[i + 1];
                Values.erase(Values.begin() + i + size_t(1));
                ArithmeticSigns.erase(ArithmeticSigns.begin() + i);
                ++NumActions;
                break;
            }
            else if (ArithmeticSigns[i] ==m.back())
            {
                if(Values[i + 1] == 0)
                {
                    m_Error=true;
                    return;
                }
                Values[i] = Values[i]/Values[i + 1];
                Values.erase(Values.begin() + i + size_t(1));
                ArithmeticSigns.erase(ArithmeticSigns.begin() + i);
                ++NumActions;
                break;
            }
        }
    }
}

// функция для решения + - действий
double ArithOperations::CalcArithExpPlusAndMinus(std::vector<double>& Answers, std::vector<char>& ArithmeticSigns)
{
    int NumActions = 0, ComplActions = 0;//переменные для хранения кол.действий в выраж. и пер. подсчёта выпол-х действий
    for (uint64_t i = 0; i != ArithmeticSigns.size(); ++i)
        if (ArithmeticSigns[i] == '+' || ArithmeticSigns[i] == '-' )
            ++ComplActions;


    while (NumActions < ComplActions)
    {
        for (uint64_t i = 0; i != ArithmeticSigns.size(); ++i)
        {
            if (ArithmeticSigns[i] == '+')
            {
                Answers[i] = Answers[i] + Answers[i + 1];
                Answers.erase(Answers.begin() + i + 1);
                ArithmeticSigns.erase(ArithmeticSigns.begin() + i);
                ++NumActions;
                break;
            }
            else if (ArithmeticSigns[i] == '-')
            {
                Answers[i] = Answers[i] - Answers[i + 1];
                Answers.erase(Answers.begin() + i + 1);
                ArithmeticSigns.erase(ArithmeticSigns.begin() + i);
                ++NumActions;
                break;
            }
        }
    }
    return Answers.front();
}
//функция для разбиение аризметических  выражения на составляющие
void ArithOperations::getArifSignsForExp(std::string &mathExp,std::vector<char>& ArithmeticSigns)//
{

    mathExp+='|';
    for(uint64_t i=1;i<mathExp.size();++i)
    {
        if(mathExp[i]=='+')
        {
            ArithmeticSigns.push_back('+');
            mathExp[i]='|';
        }
        else if(mathExp[i]=='*')
        {
            ArithmeticSigns.push_back('*');
            mathExp[i]='|';
        }
        else if(mathExp[i]=='/')
        {
            ArithmeticSigns.push_back('/');
            mathExp[i]='|';
        }
        else if(mathExp[i]=='-')
        {
            if(mathExp[i-1]!='|')
            {
                ArithmeticSigns.push_back('-');
                mathExp[i]='|';
            }
        }
    }
}

void ArithOperations::getValuesForExp(std::string &mathExp,std::vector<std::string>& ValuesForExp)
{
    while(!mathExp.empty())
    {
        auto iter=find(mathExp.begin(),mathExp.end(),'|');
        std::string val(mathExp.begin(),iter);
        ValuesForExp.push_back(val);
        mathExp.erase(mathExp.begin(),iter+1);
    }
}

void ArithOperations::getDatesForExp(std::string& mathExp,std::vector<std::string>& ValuesForExp,std::vector<char>& ArithmeticSigns)
{

    getArifSignsForExp(mathExp,ArithmeticSigns);
    getValuesForExp(mathExp,ValuesForExp);
}


