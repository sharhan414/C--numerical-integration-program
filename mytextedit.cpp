#include "mytextedit.h"

#include <QTextCursor>
#include <QDebug>
#include <string>
#include <iostream>
#include <QScroller>
#include <QScrollBar>
#include<QPushButton>
//#include "resh.h"
#include <string>
#include <iterator>
//#include "NameSpaceC.h"
#include <QTextDocumentFragment>
#include <qiterator.h>
#include <QString>
#include "libs/mathexpressions.h"
MyTextEdit::MyTextEdit(QWidget*w):QTextEdit(w)
{
    this->verticalScrollBar()->grabGesture(Qt::GestureType::SwipeGesture);
    this->setFrameShape(QFrame::NoFrame);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QScroller::grabGesture(this,QScroller::LeftMouseButtonGesture);
   //  QScroller::grabGesture(this,QScroller::TouchGesture);
        //TouchGesture
    this->setStyleSheet("QTextEdit {"
                      "background: rgb(44, 44, 44);"
                      "border: 6px inset rgb(150, 150, 150);"
                      "color: rgb(221, 225, 255);"
                   //   "font-size: "+QString::number(this->font().pixelSize()*2)+"px;"
                    //  "font: bold;"
                   " }");
}


void MyTextEdit::slotKoren()//принимает квадратный корень
{
    auto cursor=this->textCursor();
    if(ProvStavSimvolov())
    {
        if(ProvNeedStavUmn())
        {
            cursor.insertText("×√(");
        }
    else
        cursor.insertText("√(");
    this->setTextCursor(cursor);
}

}

void MyTextEdit::slotNKoren()//принимает умножение
{

    auto cursor=this->textCursor();
    if(ProvStavSimvolov())
    {
        if(ProvNeedStavUmn())
        {
            cursor.insertText("×()/√(");
        }
        else
            cursor.insertText("()/√(");
        this->setTextCursor(cursor);
    }

}
void MyTextEdit::slotPlusMinus()//принимаеть + -
{
    auto button=static_cast<QPushButton*>(sender());
    auto ButTExt=button->text();
    auto cursor=this->textCursor();
    QString text=this->toPlainText();
    if( ButTExt=="+" && (cursor.atStart() || (cursor.position() > 0 && text[cursor.position()-1]=="(")))
        return;

    if(ButTExt=="-")
    {
        if(ProvStavArifDey() )
        {
            cursor.insertText(ButTExt);
            return;
        }

        if( cursor.position() > 0 && ProvStavArifDey() &&  text[cursor.position()-1]=="(")
        {
            cursor.insertText(ButTExt);//возможность ставить знак - после (
            return ;
        }
    }

    if(ProvStavArifDey())
        cursor.insertText(ButTExt);

    this->setTextCursor(cursor);
}
void MyTextEdit::slotUmn()//принимает деление
{
    if(ProvStavArifDey())
    {
        auto cursor=this->textCursor();
        if(!cursor.atStart())
        cursor.insertText("×");
        this->setTextCursor(cursor);
    }
}

void MyTextEdit::slotDl()
{
    if(ProvStavArifDey())
    {
        auto cursor=this->textCursor();
        if(!cursor.atStart())
        cursor.insertText("÷");
        this->setTextCursor(cursor);
    }
}

void MyTextEdit::slotFactorial()
{
    auto cursor=this->textCursor();
    if(ProvStavSimvolov())
    {
        cursor.insertText("!");
        this->setTextCursor(cursor);
    }
}

void MyTextEdit::slotVStepen2()
{
    auto cursor=this->textCursor();
    if(ProvStavSimvolov())
        cursor.insertText(tr("^(2)"));
    this->setTextCursor(cursor);
}

void MyTextEdit::slotVStepenN()
{
    auto cursor=this->textCursor();
    if(ProvStavSimvolov())
        cursor.insertText(tr("^("));

    this->setTextCursor(cursor);
}

void MyTextEdit::slotPi()//принимает число  ПИ
{
    auto cursor=this->textCursor();
    if(ProvStavSimvolov())
    {
        if(ProvNeedStavUmn())
        {
            cursor.insertText("×π");
        }
        else
            cursor.insertText("π");
        this->setTextCursor(cursor);
    }
}

void MyTextEdit::slotE()//принимает е
{
    auto button=static_cast<QPushButton*>(sender());
    auto ButTExt=button->text();
    auto cursor=this->textCursor();
    if(ProvStavSimvolov())
    {
        if(ProvNeedStavUmn())
        {
            cursor.insertText("×"+ButTExt+"(");
        }
        else
        cursor.insertText(ButTExt);
        this->setTextCursor(cursor);
    }

}

void MyTextEdit::slotValues()//   принимает чисел
{

    auto button=static_cast<QPushButton*>(sender());
    auto ButTExt=button->text();
    auto cursor=this->textCursor();

    if(ProvStavSimvolov())
    {
        cursor.insertText(ButTExt);
        this->setTextCursor(cursor);
    }
}



void MyTextEdit::slotProcent()//принимает проченты % -% +%
{

    auto button=static_cast<QPushButton*>(sender());
    auto ButTExt=button->text();
    auto cursor=this->textCursor();
        if(ButTExt=="%")
        {//% времмено отключён
            qDebug()<<"textEdit="<<this->toPlainText();
            qDebug()<<"cursor"<<cursor.position();

            QString Simvols="0123456789.(+-×÷";
            auto cursor=this->textCursor();
            auto str=this->toPlainText();
            auto position=cursor.position();
            if(!str.isEmpty() && str.size()>position)
                qDebug()<<"str Cursot position="<<str[position];

            if(qFind(Simvols.begin(),Simvols.end(),str[position])!=Simvols.end())
                qDebug()<<"ravno end";
    }
    else
    {
        if(ProvStavSimvolov())
            cursor.insertText(ButTExt);
        this->setTextCursor(cursor);
    }
}

void MyTextEdit::slotTrigFunc()//принимаеть тригонометрические функции
{
    auto button=static_cast<QPushButton*>(sender());
    auto ButTExt=button->text();
    auto cursor=this->textCursor();
    if(ProvStavSimvolov())
    {
        if(ProvNeedStavUmn())
        {
            cursor.insertText("×"+ButTExt+"(");
        }
        else
            cursor.insertText(ButTExt+"(");

        this->setTextCursor(cursor);
    }
}

void MyTextEdit::slotPoint()//принимает точку (.)
{
    auto cursor=this->textCursor();
    QString StrText=this->toPlainText();

    if(ProvStavSimvolov())
    {
        QString arif="0123456789.";
        QString BeginText="",EndText="";

        for (int i=cursor.position();i!=StrText.size();++i){
        if(qFind(arif.begin(),arif.end(),StrText[i])==arif.end())
            break;

        if(StrText[i]==".")
        {
            return ;
        }
        EndText.push_back(StrText[i]);
        }

        int j=cursor.position();
        if(j > 0)
        {
            do
            {
                j--;
                if(qFind(arif.begin(),arif.end(),StrText[j])==arif.end())
                    break;
                if(StrText[j]==".")
                {
                    return ;
                }
                BeginText+=StrText[j];

            } while(j!=0);
        }

        if(BeginText.isEmpty())
        {
            cursor.insertText("0.");
        }
        else
        {
           cursor.insertText(".");
        }
    }
}

void MyTextEdit::slotDeleteChar()//принимает удаление симполов
{
    auto cursor=this->textCursor();
    QString text=this->toPlainText();
    auto CursPosition=cursor.position();

    if(CursPosition>0)
    {

    QString letters="acgilnost/√^!x";//здесь происходить удаления sin,cos,...,ln

        if(qFind(letters.begin(),letters.end(),text[CursPosition-1])!=letters.end()){//удаляет текст до курсора
            int i=CursPosition;
            do
            {
                --i;
                if(qFind(letters.begin(),letters.end(),text[i])==letters.end())
                    break;

                cursor.setPosition(cursor.position()-1);
                cursor.deleteChar();
            }
            while(i!=0);

////////////////////////////////////////////////////
//удаляет текст после курсора
    for (int j=CursPosition;j!=text.size();++j)
    {
        if(qFind(letters.begin(),letters.end(),text[j])==letters.end())
            break;
         cursor.deleteChar();
     }
    return ;
   }
////////////////////////////////////////////////////

//удаляет всю функцию с "(" до элемента не из "letters"
    if(CursPosition>2 && text[CursPosition-1]=="(" && qFind(letters.begin(),letters.end(),text[CursPosition-2])!=letters.end()){
        int i=CursPosition-1;
        do
        {

            cursor.setPosition(i);
         cursor.deleteChar();
            --i;
            if(i<0)
            {
                return;
            }

        }while(qFind(letters.begin(),letters.end(),text[i])!=letters.end());
}
 /////////////////////////////////////////////////////

    else  if(CursPosition==2 && text[1]=="(" && text[0]=="√")
    {
        cursor.setPosition(cursor.position()-1);
        cursor.deleteChar();
        cursor.setPosition(cursor.position()-1);
        cursor.deleteChar();
        return;
    }


    if(ProvStavSimvolov())
    {
        cursor.setPosition(cursor.position()-1);
        cursor.deleteChar();
    }
}
}
void MyTextEdit::slotCE()// принимает СЕ(очишение текста)
{
    this->clear();
    this->setText("0");

}

void MyTextEdit::slotScobs()//принимает скобки (  )
{
    auto button=static_cast<QPushButton*>(sender());
    auto ButTExt=button->text();
    auto cursor=this->textCursor();
    if(ProvStavSimvolov())
    {
        if(ButTExt=="(" && ProvNeedStavUmn())
        {
            cursor.insertText("×(");
        }
        else
        {
           cursor.insertText(ButTExt);
        }
    }
}

void MyTextEdit::slotLog()//принимает логорифмы log ln
{
    auto button=static_cast<QPushButton*>(sender ());
    auto ButTExt=button->text();
    auto cursor=this->textCursor();
    if(ProvStavSimvolov())
    {
        if(ProvNeedStavUmn())
        {
            cursor.insertText("×"+ButTExt+"(");
        }
        else
            cursor.insertText(ButTExt+"(");

        this->setTextCursor(cursor);
    }
}

void MyTextEdit::slot_ravno()
{

    auto StrText=this->toPlainText();
    MathExpressions calc;
    std::string stdStringText=StrText.toStdString();
    calc.CalculateMathExp(stdStringText);

    QString QstrText(stdStringText.c_str());
    this->clear();
    this->setText(QstrText);
    auto cursor=this->textCursor();
    cursor.setPosition(QstrText.size());

}
bool MyTextEdit::proverkaTexta()
{

    return true;
}

bool MyTextEdit::ProvStavPoint()
{

    if(ProvStavSimvolov())
    {

    }
    return true;
}

void MyTextEdit::slotX()
{
    auto button=static_cast<QPushButton*>(sender());
    auto ButTExt=button->text();
    auto cursor=this->textCursor();
    if(ProvStavSimvolov()){
        if(ProvNeedStavUmn()){
         cursor.insertText("×"+ButTExt+"(");
        }
        else
        cursor.insertText(ButTExt);
        this->setTextCursor(cursor);
    }
}
bool MyTextEdit::ProvStavArifDey()
{
    auto cursor=this->textCursor();
    int position=cursor.position();
    const QString Arif="+-×÷(";
    QString text=this->toPlainText();

    if(!text.isEmpty() && !cursor.atStart()&& ProvStavSimvolov())
    {

        if(qFind(Arif.begin(),Arif.end(),text[position-1])==Arif.end() && qFind(Arif.begin(),Arif.end(),text[position])==Arif.end())
        {
            return true;
        }
    }
    else if(cursor.atStart() && text.size()>1 && qFind(Arif.begin(),Arif.end(),text[0])==Arif.end())
        return true;

    return false;
}

bool MyTextEdit::ProvStavSimvolov(){

    QString Simvols="0123456789.()+-×÷%eπx";
    auto cursor=this->textCursor();
    auto text=this->toPlainText();
    auto position=cursor.position();

    if(cursor.atStart())
        return true;

    if(!text.isEmpty() && !cursor.atStart())
    {
        if(qFind(Simvols.begin(),Simvols.end(),text[position-1])!=Simvols.end())
            return true;
    }
    return false;
}

bool MyTextEdit::ProvNeedStavUmn()
{
    auto cursor=this->textCursor();
    auto text=this->toPlainText();
    if(text.isEmpty() || cursor.atStart() )
        return false;
    int position=cursor.position();
    QString Simvols="+-×÷%(";

    if(qFind(Simvols.begin(),Simvols.end(),text[position-1])==Simvols.end())
        return true;

    return false;
}


