#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>
#include <QString>

class MyTextEdit final: public QTextEdit
{
    Q_OBJECT
public:
    explicit MyTextEdit(QWidget *parent = nullptr);
private:
    bool proverkaTexta();

    QString text;

    bool ProvStavPoint();
    bool ProvStavArifDey();
    bool ProvStavSimvolov();
    bool ProvNeedStavUmn();

public slots:
    void slotKoren();
    void slotNKoren();
    void slotUmn();
    void slotDl();

    void slotFactorial();
    void slotVStepen2();
    void slotVStepenN();
    void slotPi();
    void slotE();

    void slotValues();
    void slotPlusMinus();
    void slotProcent();
    void slotTrigFunc();
    void slotPoint();

    void slotDeleteChar();
    void slotCE();
    void slotScobs();
    void slotX();
    void slotLog();

    void slot_ravno();
};
#endif // MYTEXTEDIT_H
