#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <math.h>
#include <iostream>
#include <QTextStream>
#include <QPixmap>
#include <QIcon>
#include <QPushButton>

#include "generator.h"
#include "account.h"

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
    void on_emailBtn_clicked();
    void on_bankBtn_clicked();
    void on_emailBtn_3_clicked();

    void on_passcreateBtn_clicked();
    void on_continueBtn_clicked();
    void on_coloredBtn_clicked();

private:
    Ui::MainWindow *ui;
    Generator *gen;
    Account accounts[3];
    int currState;

    void changeState(int);
    void changeState(int, QString);
};
#endif // MAINWINDOW_H
