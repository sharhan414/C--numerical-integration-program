#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mytextedit.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void slotRefIntegrall();

    void on_checkBox_accuracy_stateChanged(int arg1);

    void on_Button_receive_clicked();

private:
    Ui::MainWindow *ui;
    MyTextEdit* InputFuncEdit;
};
#endif // MAINWINDOW_H
