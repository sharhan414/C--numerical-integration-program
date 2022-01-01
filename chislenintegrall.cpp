#include "chislenintegrall.h"
#include "solvfunction.h"
#include <cmath>
ChislenIntegrall::ChislenIntegrall(std::string func, double add_a, double add_b, int add_n)
{
  a=add_a;
  b=add_b;
  n=add_n;
  str_func=func;
  not_accuracy=true;
}
ChislenIntegrall::ChislenIntegrall(std::string func,double add_a,double add_b,int add_n,double add_acc):
    ChislenIntegrall(func,add_a,add_b,add_n)
{
    accuracy=add_acc;
    not_accuracy=false;
}

double ChislenIntegrall::getMethodTrapezoid()
{
    return MethodTrapezoidIsNStep(3*n);
}

double ChislenIntegrall::getMethodMiddleRects()
{
    return MethodMiddleRectsIsNStep(3*n);
}

double ChislenIntegrall::getMethodLeftRects()
{
   return MethodMiddleRectsIsNStep(3*n);
}

double ChislenIntegrall::getMethodRightRects()
{
    return getMethodRightRectsIsNStep(3*n);
}

double ChislenIntegrall::getMethodSimsona()
{
    return getMethodSimsonaIsNStep(3*n);
}

double ChislenIntegrall::getMethodTrapezoidIsAccuracy()
{
    if(not_accuracy)
    {
        return 0;
    }

    int new_n=n;
    double S_n=MethodTrapezoidIsNStep(new_n);
    double S_2n=MethodTrapezoidIsNStep(2*new_n);

    while(std::abs(S_n-S_2n) > accuracy)
    {
        new_n*=2;

        S_n=MethodTrapezoidIsNStep(new_n);
        S_2n=MethodTrapezoidIsNStep(2*new_n);
    }

    return S_2n;
}

double ChislenIntegrall::getMethodMiddleRectsIsAccuracy()
{
    if(not_accuracy)
    {
        return 0;
    }

    int new_n=n;
    double S_n=MethodMiddleRectsIsNStep(new_n);
    double S_2n=MethodMiddleRectsIsNStep(2*new_n);

    while(std::abs(S_n-S_2n) > accuracy)
    {
       new_n*=2;

       S_n=MethodMiddleRectsIsNStep(new_n);
       S_2n=MethodMiddleRectsIsNStep(2*new_n);
    }

    return S_2n;
}

double ChislenIntegrall::getMethodLeftRectsAccuracy()
{
    if(not_accuracy)
    {
        return 0;
    }

    int new_n=n;
    double S_n=getMethodLeftRectsIsNStep(new_n);
    double S_2n=getMethodLeftRectsIsNStep(2*new_n);

    while(std::abs(S_n-S_2n) > accuracy)
    {
       new_n*=2;

       S_n=getMethodLeftRectsIsNStep(new_n);
       S_2n=getMethodLeftRectsIsNStep(2*new_n);
    }

    return S_2n;

}

double ChislenIntegrall::getMethodRightRectsAccuracy()
{

    if(not_accuracy)
    {
        return 0;
    }

    int new_n=n;
    double S_n=getMethodRightRectsIsNStep(new_n);
    double S_2n=getMethodRightRectsIsNStep(2*new_n);

    while(std::abs(S_n-S_2n) > accuracy)
    {
       new_n*=2;

       S_n=getMethodRightRectsIsNStep(new_n);
       S_2n=getMethodRightRectsIsNStep(2*new_n);
    }

    return S_2n;
}

double ChislenIntegrall::getMethodSimsonaAccuracy()
{
    if(not_accuracy)
    {
        return 0;
    }

    int new_n=n;
    double S_n=getMethodSimsonaIsNStep(new_n);
    double S_2n=getMethodSimsonaIsNStep(2*new_n);

    while(std::abs(S_n-S_2n) > accuracy)
    {
       new_n*=2;

       S_n=getMethodSimsonaIsNStep(new_n);
       S_2n=getMethodSimsonaIsNStep(2*new_n);
    }

    return S_2n;
}


double ChislenIntegrall::MethodTrapezoidIsNStep(int step_n)
{
    SolvFunction func(str_func);
    double h=(b-a)/step_n;

    double Integrall=0;

    for(double x=a;x<=b;x+=h)
    {
        Integrall+=(func(x)+func(x+h))/2;
    }
    Integrall*=h;
    return Integrall;
}

double ChislenIntegrall::MethodMiddleRectsIsNStep(int step_n)
{
    SolvFunction func(str_func);
    double h=(b-a)/step_n;
    double S=0;
         for(double x=a;x<b;x+=h)
         {
            S+=func((x+x+h)/2);
         }
    S*=h;
    return S;
}

double ChislenIntegrall::getMethodLeftRectsIsNStep(int step_n)
{
    SolvFunction func(str_func);
    double S=0;
    double h=(b-a)/n;//шаг
    for(double i=a;i<b;i=i+h)
    {
        S+=func(i);//суммируем значения функции в узловых точках
    }
    return S*h;
}

double ChislenIntegrall::getMethodRightRectsIsNStep(int step_n)
{
    SolvFunction func(str_func);
    double S=0;
    double h=(b-a)/n;//шаг
    for(double i=a+h;i<=b;i=i+h)
    {
        S+=func(i);//суммируем значения функции в узловых точках
    }
    return S*h;
}

double ChislenIntegrall::getMethodSimsonaIsNStep(int step_n)
{
    double h = (b-a)/step_n;
    SolvFunction func(str_func);

    double simpson_integral = 0;
    for(int step = 0; step < step_n; step++)
    {
        const double x1 = a + step*h;
        const double x2 = a + (step+1)*h;
        simpson_integral += (x2-x1)/6.0*(func(x1) + 4.0*func(0.5*(x1+x2)) + func(x2));
    }

    return simpson_integral;
}

