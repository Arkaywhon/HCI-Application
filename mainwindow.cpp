#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->continueBtn->hide();
    ui->loginWidget->setEnabled(false);

    QPushButton *colorBtns[8] = {ui->whiteBtn, ui->yellowBtn, ui->greenBtn, ui->blueBtn, ui->tealBtn, ui->purpleBtn, ui->redBtn, ui->orangeBtn};
    for(int i = 0; i < 8; i ++){
        connect(colorBtns[i], SIGNAL(clicked()), this, SLOT(on_coloredBtn_clicked()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeState(int state, QString text){
    currState = state;
    ui->continueBtn->hide();
    if(currState >= 0){
        ui->stateStatusLbl->setText(text + " Account Login");
        ui->loginWidget->setEnabled(true);
        if(accounts[currState].getPassStatus() == false){
            ui->loginBtn->setEnabled(false);
        }else ui->loginBtn->setEnabled(true);
    }
}

void MainWindow::on_emailBtn_clicked(){changeState(0, "E-Mail");}
void MainWindow::on_bankBtn_clicked(){changeState(1, "Bank");}
void MainWindow::on_emailBtn_3_clicked(){changeState(2, "Shopping");}

void MainWindow::on_passcreateBtn_clicked()
{
    ui->loginWidget->hide();
    ui->continueBtn->show();
    gen = new Generator(this);
    gen->setGeometry(230,40,500,150);
    gen->show();
}

void MainWindow::on_continueBtn_clicked()
{
    accounts[currState].setPassword(gen->getPassword());
    gen->hide();
    delete gen;
    ui->continueBtn->hide();
    ui->loginBtn->setEnabled(true);
    ui->loginWidget->show();
}

void MainWindow::on_coloredBtn_clicked(){
    QPushButton *pushedBtn = qobject_cast<QPushButton*>(sender());
    QString btnName = pushedBtn->objectName();
    QString color = btnName.mid(0, btnName.length()-3);
    qDebug() << color;
}
