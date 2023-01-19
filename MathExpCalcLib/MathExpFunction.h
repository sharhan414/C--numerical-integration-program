#ifndef RESHENIY_H
#define RESHENIY_H

#include <algorithm>

#include <string>
#include <cmath>
#include <iterator>

class MathExpFunction
{
public:
    enum class ErrorsType//перечисление для обазначения типов ошибок
    {
        DivZero,arcTrihFunc,notNatNumFactorial
    };
    MathExpFunction();
    virtual bool calculate(std::string& mathExp)=0;//функция для произведения вычисления, возврашает false при ошибке в противном случае true

    bool isError()
    {
        return m_Error;
    }
    static constexpr  double Math_Pi=3.141592654;
    static std::string to_stdString(double);
    double stdString_toDouble(std::string strValues);

    template<class MathExp>
    static void replMathExp(MathExp &mathExp,MathExp Sign, MathExp newSign);//заменяет текст Sign из mathExp на newSign

protected:
    //SearchBeginText - функция для нахождения числа находящей впереди указанной позиции,
    std::string SearchBeginText(std::string&,std::string::iterator&,std::string::iterator&) ;
    //SearchEndText - функция для нахождения числа находящей позади указанной позиции,
    std::string SearchEndText(std::string&,std::string,std::string::iterator&,std::string::iterator&) ;
    bool m_Error=false;
    const std::string UserChars = "0123456789.";

};

#endif // RESHENIY_H
