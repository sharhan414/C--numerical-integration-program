#ifndef RESH_H
#define RESH_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "reshtrigfunc.h"
#include "arifdeyst.h"
#include "procents.h"
#include "log.h"
#include "factorial.h"
#include "sqrt.h"
#include "pow.h"
#include <QString>
using namespace std;

class Resh
{

public:
    void resh(string&);
    Resh();
 static void ReplacingSigns(QString&);

private:
    void OpeningBrackets(string& text, string::iterator& begin, string::iterator& end, string::iterator& verhEnd);
    string QtFunck(string text);
    bool  resheniya2(string& text, string::iterator& begin, string::iterator& end, string::iterator& verhEnd);

private:
    ReshTrigFunc trig;
    Procents Proc;
    ArifDeyst arif;
    Log log;
    Factorial factorial;
    Sqrt qsrt;
    Pow pow;
};

#endif // RESH_H
