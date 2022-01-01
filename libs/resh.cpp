#include "resh.h"

#include <QString>
#include "arifdeyst.h"
#include <string>
#include <iterator>
#include<QDebug>
#include "reshtrigfunc.h"
#include <QtAlgorithms>
using namespace  std;

void Resh::resh(string & text)
{
    string::iterator b=text.begin(),e=text.end(),e2=text.end();
    OpeningBrackets(text,b,e,e2);
}

Resh::Resh()
{

}

string Resh::QtFunck(string text) {

factorial.CalculateFactorial(text);
trig.CalculateTrigFunc(text);
if(trig.isError())
    qDebug()<<"v trig error";

Proc.CalculatePercent(text);
log.CalculatehLog(text);

qsrt.CalculateSqrt(text);
pow.CalculatePow(text);


double value=0;
arif.arif_detstvie(value,text);


return QString::number(value).toStdString();
}

/////////////////////////////////////
/// \brief Resh::sleep
/// \param text
/// \param begin
/// \param end
/// \param verhEnd
/////////////////////////////////////////////////////
void Resh::OpeningBrackets(string& text, string::iterator& begin, string::iterator& end, string::iterator& verhEnd) {
//функция для раскрытия скобок
    if(!resheniya2(text, begin, end, verhEnd ))
        return;
    int zak = 0, ot = 0;
    auto c = text.end();
    auto i = begin;

    while (i != end) {


        if (*i == '(') {           //подсчитывает количество открытых скобок
            ++ot;
            if (c == text.end())
                c = i;                  //сохраняет позицию первой открытой скобки
        }
        else if (*i == ')') {      //подсчитывает количество закрытых скобок
            ++zak;
        }
        if (zak != 0 && ot == zak) {        //если количество окрытых и закрытых скобок равно, то
            string n(c + 1, c + (i - c));  //сохраняет текст скобки
            int64_t ras1 = text.size();
            OpeningBrackets(text, ++c, i,end);
            int64_t ras2 = text.size();     //
            int64_t ras =  ras1-ras2;
            verhEnd -= ras;
            if (!resheniya2(text, begin,end, verhEnd))
                return;		//закрываем нашу функцию
            c = text.end();
            zak = 0;
            ot = 0;
        }
        ++i;//увеличиваем счетшик на 1
    }
}
bool  Resh::resheniya2(string& text, string::iterator& begin, string::iterator& end, string::iterator& verhEnd) {


    string textskobky(begin, end);//вычисляется текст нашей скобки
    int64_t sizeIshodText = int64_t(text.size());

    if (find(textskobky.begin(), textskobky.end(), '(') == textskobky.end() && !textskobky.empty()) {//если в нашем тексте нету скобок то
        string otvet = QtFunck(textskobky);//вычисляем ответ арифметических действий в нашем тексте и ответ сохраняем в переменной "otvet"

        if (begin == text.begin() && end==text.end()) {//
            text.clear();
            text = otvet;
            begin = text.begin();
            end = text.end();
            verhEnd = end;

            }
        else  {
            if (begin != text.begin() && end != text.end())
                end = text.erase(begin - 1, end + 1);
            else if (begin == text.begin() && end != text.end())
                end = text.erase(begin , end + 1);
            else if (begin != text.begin() && end == text.end())
                end = text.erase(begin-1, end );

            text.insert(end, otvet.begin(), otvet.end());
            end = begin;
            if (begin != text.begin())
                --end;
                int64_t sizeKonechText = int64_t(text.size());
                int64_t raznica = sizeIshodText - sizeKonechText;
                verhEnd = verhEnd - raznica;
            }
             return false;
        }
        else
            return true;
    }




void Resh::ReplacingSigns(QString & text)//заменят знаки
{
qDebug()<<"Zamena do text="<<text;

int i=0;
    while(true){
    QString BeginText,EndTExt;
    QString NewText="";
    QString Func="nsqrt";
    if(text[i]=="/"){

        for(int b=0;b!=i;++b){
            BeginText.push_back(text[b]);
        }
        for(int e=i+2;e!=text.size();++e){
            EndTExt.push_back(text[e]);
        }
text=BeginText+Func+EndTExt;
    }
++i;
    if(i==text.size())
        break;

}

    int j=0;
        while(true){
        QString BeginText,EndTExt;
        QString NewText="";
        QString Func="sqrt";
        if(text[j]=="√"){

            for(int b=0;b!=j;++b){
                BeginText.push_back(text[b]);
            }
            for(int e=j+1;e!=text.size();++e){
                EndTExt.push_back(text[e]);
            }
    text=BeginText+Func+EndTExt;
        }
    ++j;
        if(j==text.size())
            break;
    }


            QString::size_type t=0;
            while(true){
                if(text[t]=="×")
                    text[t]='*';
                else if(text[t]=="÷")
                    text[t]='/';
                else if(text[t]=="e"){

                    QString BeginText="",EndText="";
                    for(QString::size_type j=0;j!=t;++j){
                        BeginText.push_back(text[j]);
                    }
                    for(QString::size_type j=t+1;j!=text.size();++j){
                        EndText.push_back(text[j]);
                    }
                    text=BeginText+"2.7"+EndText;
                }
                else if(text[t]=="π"){
                    QString BeginText="",EndText="";
                    for(QString::size_type j=0;j!=t;++j){
                        BeginText.push_back(text[j]);
                    }
                    for(QString::size_type j=t+1;j!=text.size();++j){
                        EndText.push_back(text[j]);
                    }
                    text=BeginText+"3.14"+EndText;
                }
                ++t;

                if(t==text.size())
                    break;
            }


}

