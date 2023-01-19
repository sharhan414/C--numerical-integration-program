#include "chislenintegrall.h"
#include "solvfunction.h"
#include <cmath>
ChislenIntegrall::ChislenIntegrall(std::string func, double add_a, double add_b, int add_n)
{
  m_a=add_a;
  m_b=add_b;
  m_n=add_n;
  m_strFunc=func;
  m_notAccuracy=true;
}
ChislenIntegrall::ChislenIntegrall(std::string func,double add_a,double add_b,int add_n,double add_acc):
    ChislenIntegrall(func,add_a,add_b,add_n)
{
    m_accuracy=add_acc;
    m_notAccuracy=false;
}

double ChislenIntegrall::getMethodTrapezoid()
{
    return MethodTrapezoidIsNStep(3*m_n);
}

double ChislenIntegrall::getMethodMiddleRects()
{
    return MethodMiddleRectsIsNStep(3*m_n);
}

double ChislenIntegrall::getMethodLeftRects()
{
   return MethodMiddleRectsIsNStep(3*m_n);
}

double ChislenIntegrall::getMethodRightRects()
{
    return getMethodRightRectsIsNStep(3*m_n);
}

double ChislenIntegrall::getMethodSimsona()
{
    return getMethodSimsonaIsNStep(3*m_n);
}

double ChislenIntegrall::getMethodTrapezoidIsAccuracy()
{
    if(m_notAccuracy)
    {
        return 0;
    }

    int new_n=m_n;
    double S_n=MethodTrapezoidIsNStep(new_n);
    double S_2n=MethodTrapezoidIsNStep(2*new_n);

    while(std::abs(S_n-S_2n) > m_accuracy)
    {
        new_n*=2;

        S_n=MethodTrapezoidIsNStep(new_n);
        S_2n=MethodTrapezoidIsNStep(2*new_n);
    }

    return S_2n;
}

double ChislenIntegrall::getMethodMiddleRectsIsAccuracy()
{
    if(m_notAccuracy)
    {
        return 0;
    }

    int new_n=m_n;
    double S_n=MethodMiddleRectsIsNStep(new_n);
    double S_2n=MethodMiddleRectsIsNStep(2*new_n);

    while(std::abs(S_n-S_2n) > m_accuracy)
    {
       new_n*=2;

       S_n=MethodMiddleRectsIsNStep(new_n);
       S_2n=MethodMiddleRectsIsNStep(2*new_n);
    }

    return S_2n;
}

double ChislenIntegrall::getMethodLeftRectsAccuracy()
{
    if(m_notAccuracy)
    {
        return 0;
    }

    int new_n=m_n;
    double S_n=getMethodLeftRectsIsNStep(new_n);
    double S_2n=getMethodLeftRectsIsNStep(2*new_n);

    while(std::abs(S_n-S_2n) > m_accuracy)
    {
       new_n*=2;

       S_n=getMethodLeftRectsIsNStep(new_n);
       S_2n=getMethodLeftRectsIsNStep(2*new_n);
    }

    return S_2n;

}

double ChislenIntegrall::getMethodRightRectsAccuracy()
{

    if(m_notAccuracy)
    {
        return 0;
    }

    int new_n=m_n;
    double S_n=getMethodRightRectsIsNStep(new_n);
    double S_2n=getMethodRightRectsIsNStep(2*new_n);

    while(std::abs(S_n-S_2n) > m_accuracy)
    {
       new_n*=2;

       S_n=getMethodRightRectsIsNStep(new_n);
       S_2n=getMethodRightRectsIsNStep(2*new_n);
    }

    return S_2n;
}

double ChislenIntegrall::getMethodSimsonaAccuracy()
{
    if(m_notAccuracy)
    {
        return 0;
    }

    int new_n=m_n;
    double S_n=getMethodSimsonaIsNStep(new_n);
    double S_2n=getMethodSimsonaIsNStep(2*new_n);

    while(std::abs(S_n-S_2n) > m_accuracy)
    {
       new_n*=2;

       S_n=getMethodSimsonaIsNStep(new_n);
       S_2n=getMethodSimsonaIsNStep(2*new_n);
    }

    return S_2n;
}


double ChislenIntegrall::MethodTrapezoidIsNStep(int step_n)
{
    SolvFunction func(m_strFunc);
    double h=(m_b-m_a)/step_n;

    double Integrall=0;

    for(double x=m_a;x<=m_b;x+=h)
    {
        Integrall+=(func(x)+func(x+h))/2;
    }
    Integrall*=h;
    return Integrall;
}

double ChislenIntegrall::MethodMiddleRectsIsNStep(int step_n)
{
    SolvFunction func(m_strFunc);
    double h=(m_b-m_a)/step_n;
    double S=0;
         for(double x=m_a;x<m_b;x+=h)
         {
            S+=func((x+x+h)/2);
         }
    S*=h;
    return S;
}

double ChislenIntegrall::getMethodLeftRectsIsNStep(int step_n)
{
    SolvFunction func(m_strFunc);
    double S=0;
    double h=(m_b-m_a)/m_n;//шаг
    for(double i=m_a;i<m_b;i=i+h)
    {
        S+=func(i);//суммируем значения функции в узловых точках
    }
    return S*h;
}

double ChislenIntegrall::getMethodRightRectsIsNStep(int step_n)
{
    SolvFunction func(m_strFunc);
    double S=0;
    double h=(m_b-m_a)/m_n;//шаг
    for(double i=m_a+h;i<=m_b;i=i+h)
    {
        S+=func(i);//суммируем значения функции в узловых точках
    }
    return S*h;
}

double ChislenIntegrall::getMethodSimsonaIsNStep(int step_n)
{
    double h = (m_b-m_a)/step_n;
    SolvFunction func(m_strFunc);

    double simpson_integral = 0;
    for(int step = 0; step < step_n; step++)
    {
        const double x1 = m_a + step*h;
        const double x2 = m_a + (step+1)*h;
        simpson_integral += (x2-x1)/6.0*(func(x1) + 4.0*func(0.5*(x1+x2)) + func(x2));
    }

    return simpson_integral;
}

