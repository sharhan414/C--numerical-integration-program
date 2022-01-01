#ifndef SOLVFUNCTION_H
#define SOLVFUNCTION_H

#include <string>
class SolvFunction{
public:
    SolvFunction(std::string added_func);
    double getSolvFunction(double x);
    double operator()(double x);
private:

    std::string func;
    std::string addValuesToFunc(double val);

};
#endif // SOLVFUNCTION_H
