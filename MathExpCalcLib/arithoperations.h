#ifndef ARITHOPERATIONS_H
#define ARITHOPERATIONS_H
#include <vector>
#include <string>
#include "MathExpFunction.h"

/*\

  Класс ArithOperations может решить страндартные математические выражения по типу "-2*5+6/4-7+..."
  для вычисления математического выражения необходимо создать объект типа ArithOperations и вызвать
  у него метод calcArithExp которому нужно передать переменную std::string которая содержить мат.выражение

 */

class ArithOperations:public MathExpFunction
{
public:
    ArithOperations();
    bool calculate(std::string &mathExp) override;
    double calcArithExp(std::string mathExp);
private:
    void  CalcArithExpMultAndDiv(std::vector<double>&, std::vector<char>&);//решаеть ариф.действия умножение и деление
    double CalcArithExpPlusAndMinus(std::vector<double>&, std::vector<char>& );
    void getArifSignsForExp(std::string &mathExp,std::vector<char>& ArithmeticSigns);
    void getValuesForExp(std::string &mathExp,std::vector<std::string>& ValuesForExp);
    void getDatesForExp(std::string& mathExp,std::vector<std::string>& ValuesForExp,std::vector<char>& ArithmeticSigns);


};

#endif // ARITHOPERATIONS_H
