#ifndef CHISLENINTEGRALL_H
#define CHISLENINTEGRALL_H
#include <string>

class ChislenIntegrall
{
public:
    ChislenIntegrall(std::string func,double add_a,double add_b,int add_n);
    ChislenIntegrall(std::string func,double add_a,double add_b,int add_n,double add_acc);

    double getMethodTrapezoid();
    double getMethodMiddleRects();
    double getMethodLeftRects();
    double getMethodRightRects();
    double getMethodSimsona();


    double getMethodTrapezoidIsAccuracy();
    double getMethodMiddleRectsIsAccuracy();
    double getMethodLeftRectsAccuracy();
    double getMethodRightRectsAccuracy();
    double getMethodSimsonaAccuracy();

private:
    double MethodTrapezoidIsNStep(int step_n);
    double MethodMiddleRectsIsNStep(int step_n);
    double getMethodLeftRectsIsNStep(int step_n);
    double getMethodRightRectsIsNStep(int step_n);
    double getMethodSimsonaIsNStep(int step_n);
    double m_a,m_b,m_accuracy;
    bool m_notAccuracy;
    int m_n;
    std::string m_strFunc;
};

#endif // CHISLENINTEGRALL_H
