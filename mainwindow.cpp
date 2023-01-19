#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>
#include <QDebug>
#include <QMessageBox>
#include "chislenintegrall.h"
#include <MathExpCalcLib/mathexpressions.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    setWindowTitle("NSCalc");
    ui->lineEdit_answer->setReadOnly(true);
    ui->SpinBox_epsilon->setEnabled(false);

    ui->SpinBox_a->setMinimum(-1000000);

    ui->SpinBox_a->setDecimals(3);

    ui->SpinBox_b->setMinimum(-1000000);
    ui->SpinBox_b->setDecimals(3);

    ui->SpinBox_epsilon->setDecimals(3);
    ui->SpinBox_epsilon->setSingleStep(0.001);
    m_InputFuncEdit=new MyTextEdit(this);
    //m_m_InputFuncEdit->setReadOnly(true);
    m_InputFuncEdit->setGeometry(15,80,width()-30,110);
    QFont font;
    font.setPointSize(18);
    m_InputFuncEdit->setFont(font);

    connect(ui->Button_0,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotValues()));
    connect(ui->Button_1,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotValues()));
    connect(ui->Button_2,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotValues()));
    connect(ui->Button_3,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotValues()));
    connect(ui->Button_4,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotValues()));
    connect(ui->Button_5,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotValues()));
    connect(ui->Button_6,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotValues()));
    connect(ui->Button_7,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotValues()));
    connect(ui->Button_8,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotValues()));
    connect(ui->Button_9,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotValues()));

    connect(ui->Button_plus,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotPlusMinus()));
    connect(ui->Button_minus,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotPlusMinus()));
    connect(ui->Button_multipl,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotUmn()));
    connect(ui->Button_division,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotDl()));

    connect(ui->Button_factorials,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotFactorial()));
    connect(ui->Button_pow_2,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotVStepen2()));
    connect(ui->Button_pow_n,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotVStepenN()));

    connect(ui->Button_sin,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotTrigFunc()));
    connect(ui->Button_cos,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotTrigFunc()));

    connect(ui->Button_point,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotPoint()));
    connect(ui->Button_deleted,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotDeleteChar()));
    connect(ui->Button_clear,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotCE()));

    connect(ui->Button_sqrt,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotKoren()));
    connect(ui->Button_sqrt_n,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotNKoren()));

    connect(ui->Button_ln,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotLog()));
    connect(ui->Button_log,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotLog()));

    connect(ui->Button_opens_bracket,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotScobs()));
    connect(ui->Button_closes_bracket,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotScobs()));

    connect(ui->Button_e,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotE()));

    connect(ui->Button_receive,SIGNAL(clicked(bool)),this,SLOT(slotRefIntegrall()));

    connect(ui->Button_x,SIGNAL(clicked(bool)),m_InputFuncEdit,SLOT(slotX()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotRefIntegrall()
{
    if(ui->checkBox_accuracy->isChecked())//отмечен ли
    {
        qDebug()<<"yes";
    }
    else
        qDebug()<<"not";
}


void MainWindow::on_checkBox_accuracy_stateChanged(int arg1)
{
    if(ui->checkBox_accuracy->isChecked())//отмечен ли
    {
        ui->SpinBox_epsilon->setEnabled(true);
    }
    else
        ui->SpinBox_epsilon->setEnabled(false);
}

void MainWindow::on_Button_receive_clicked()
{

    double a=ui->SpinBox_a->value();
    double b=ui->SpinBox_b->value();
    double e=ui->SpinBox_epsilon->value();
    int n=ui->spinBox_n->value();
    QString func=m_InputFuncEdit->toPlainText();
    if(func.isEmpty())
    {
        QMessageBox ms;
        ms.setWindowTitle("NSCalc");
        ms.setText("<center>Вы не ввели функцию</center>");
        ms.exec();
        return;
    }

    MathExpressions::ReplacingSigns(func);

//    Resh::Zamena(func);
    if(ui->checkBox_accuracy->isChecked() and e==0.0)//отмечень ли
    {
        QMessageBox ms;
        ms.setWindowTitle("NSCalc");
        ms.setText("<center>Вы не ввели погрешность</center>");
        ms.exec();
        return;
    }

    if(n==0)
    {
        QMessageBox ms;
        ms.setWindowTitle("NSCalc");
        ms.setText("<center>Вы не ввели n</center>");
        ms.exec();
        return;
    }
    if(a==0.0 and b==0.0)
    {
        QMessageBox ms;
        ms.setWindowTitle("NSCalc");
        ms.setText("<center>Вы не ввели a и/или b</center>");
        ms.exec();
        return;
    }

    QString method=ui->comboBox_metods->currentText();
    qDebug()<<"func="<<func;


    if(method=="Метод средних прямоугольников")//1
    {
        if(ui->checkBox_accuracy->isChecked())
        {
            ChislenIntegrall integ(func.toStdString(),a,b,n,e);
            ui->lineEdit_answer->setText(QString::number(integ.getMethodMiddleRectsIsAccuracy()));
        }
        else
        {
            ChislenIntegrall integ(func.toStdString(),a,b,n);
            ui->lineEdit_answer->setText(QString::number(integ.getMethodMiddleRects()));
        }
    }
    if(method=="Метод левых прямоугольников"){//2
        if(ui->checkBox_accuracy->isChecked())
        {
            ChislenIntegrall integ(func.toStdString(),a,b,n,e);
            ui->lineEdit_answer->setText(QString::number(integ.getMethodLeftRectsAccuracy()));
        }
        else
        {
            ChislenIntegrall integ(func.toStdString(),a,b,n);
            ui->lineEdit_answer->setText(QString::number(integ.getMethodLeftRects()));
        }
    }
    if(method=="Метод правых прямоугольников")//3
    {
        if(ui->checkBox_accuracy->isChecked())
        {
            ChislenIntegrall integ(func.toStdString(),a,b,n,e);
            ui->lineEdit_answer->setText(QString::number(integ.getMethodRightRectsAccuracy()));
        }
        else
        {
            ChislenIntegrall integ(func.toStdString(),a,b,n);
            ui->lineEdit_answer->setText(QString::number(integ.getMethodRightRects()));
        }
    }
    if(method=="Метод трапеций")//4
    {
        if(ui->checkBox_accuracy->isChecked())
        {
            ChislenIntegrall integ(func.toStdString(),a,b,n,e);
            ui->lineEdit_answer->setText(QString::number(integ.getMethodTrapezoidIsAccuracy()));
        }
        else
        {
            ChislenIntegrall integ(func.toStdString(),a,b,n);
            ui->lineEdit_answer->setText(QString::number(integ.getMethodTrapezoid()));
        }
    }
    if(method=="Метод парабол(Симпсона)")//5
    {
        if(ui->checkBox_accuracy->isChecked())
        {
            ChislenIntegrall integ(func.toStdString(),a,b,n,e);
            ui->lineEdit_answer->setText(QString::number(integ.getMethodSimsonaAccuracy()));
        }
        else
        {
            ChislenIntegrall integ(func.toStdString(),a,b,n);
            ui->lineEdit_answer->setText(QString::number(integ.getMethodSimsona()));
        }
    }

}
