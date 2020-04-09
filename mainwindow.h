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
#include "logger.h"

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

    void on_generator_completed();

    void on_passcreateBtn_clicked();
    void on_loginBtn_clicked();
    void on_coloredBtn_clicked();

    void on_logBtn_clicked();

    void on_beginBtn_clicked();

    void on_attemptBtn_clicked();

private:
    Ui::MainWindow *ui;
    Generator *gen;
    Account accounts[3];
    QString stateCategories[3];
    int currState;
    QString currAttempt[7];
    int entryCount;
    Logger *log;
    int attemptCounter;
    int counter;
    int succStates[3];

    void initLoginWidget();
    void updateState(int);
    void addEntry(QString);
    bool allPassCreated();
    void nextRandState();

};
#endif // MAINWINDOW_H
