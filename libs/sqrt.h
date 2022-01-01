#ifndef SQRT_H
#define SQRT_H
#include "resheniy.h"

class Sqrt:public Resheniy
{
public:
    Sqrt();
    void CalculateSqrt(std::string&);
    void CalculateNSqtn(std::string&);
    void Calculate2Sqrt(std::string&);
    std::string getMathSqrtAnswer(std::string&);
    std::string resheniya(std::string& ,std::string&);



    double nsqrt(double x, double y)
    {
        if( y == 0.0 || (x<0 && abs(y)-abs(int(y))==0 && abs(int(y))%2==0))
        {
            Error=true;
            return 0;
        }
        double otvet = pow(x, 1/y);
        return otvet;
    }
    double sqrt(double x)
    {
        if(x<0)
        {
            Error=true;
            return 0;
        }
        return pow(x, 0.5);
    }
};

#endif // SQRT_H
