#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initLoginWidget();
    log = new Logger();

    attemptCounter = 0;

    counter = 0;
    for(int i = 0; i < 3; i ++) succStates[i] = -1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initLoginWidget(){
    entryCount = 0;
    stateCategories[0] = "E-Mail";
    stateCategories[1] = "Bank";
    stateCategories[2] = "Shop";
    QPushButton *colorBtns[8] = {ui->whiteBtn, ui->yellowBtn, ui->greenBtn, ui->blueBtn, ui->tealBtn, ui->purpleBtn, ui->redBtn, ui->orangeBtn};
    for(int i = 0; i < 8; i ++) connect(colorBtns[i], SIGNAL(clicked()), this, SLOT(on_coloredBtn_clicked()));
    ui->loginWidget->setEnabled(false);
}

void MainWindow::updateState(int state){
    currState = state;
    if(currState >= 0){
        ui->stateStatusLbl->setText(stateCategories[currState] + " Account Login");
        entryCount = 0;
        ui->entryLbl->setText("0 / 7");
        ui->logStatusLbl->setText("Logged Out");
        ui->loginWidget->setEnabled(true);
    }
}

void MainWindow::addEntry(QString c){
    if(entryCount >= 7) return;
    currAttempt[entryCount] = c;
    entryCount ++;
    ui->entryLbl->setText(QString::number(entryCount) + " / 7");
}

bool MainWindow::allPassCreated(){
    for(int i = 0; i < 3; i ++) if (!accounts[i].getPassStatus()) return false;
    return true;
}

void MainWindow::nextRandState(){

    bool checker = true;
    bool unique = true;
    int rand = qrand() % ((2 + 1) - 0) + 0;

    while(checker == true){
        for(int i = 0; i < counter; i ++){
            if(succStates[i] == rand){
                unique = false;
                break;
            }
        }
        if(unique == true){
            break;
        }
        unique = true;
        rand = qrand() % ((2 + 1) - 0) + 0;
    }

    succStates[counter] = rand;
    counter ++;
    entryCount = 0;
    updateState(rand);
}

void MainWindow::on_emailBtn_clicked(){updateState(0);}
void MainWindow::on_bankBtn_clicked(){updateState(1);}
void MainWindow::on_emailBtn_3_clicked(){updateState(2);}

void MainWindow::on_passcreateBtn_clicked()
{
    this->setEnabled(false);
    gen = new Generator();
    connect(gen, SIGNAL(destroyed(QObject*)), this, SLOT(on_generator_completed()));
    gen->show();

    entryCount = 0;
    accounts[currState].setPassword(gen->getPassword());
    updateState(currState);
}

void MainWindow::on_coloredBtn_clicked(){
    //if(entryCount == 0) log->beginTimeLog();
    QPushButton *pushedBtn = qobject_cast<QPushButton*>(sender());
    QString btnName = pushedBtn->objectName();
    QString color = btnName.mid(0, btnName.length()-3);
    addEntry(color);
}

void MainWindow::on_loginBtn_clicked()
{

    if(entryCount != 7) return;
    bool validated = accounts[currState].comparePasswords(currAttempt);

    if(validated){

        ui->logStatusLbl->setText("Login Succesfull");
        log->logSuccess();
        attemptCounter = 0;
        ui->octaPass->setEnabled(false);
        ui->beginBtn->setEnabled(true);

        if(counter < 3){
            nextRandState();
            return;
        }else{
            updateState(currState);
        }
    }else if(attemptCounter < 2){

        attemptCounter ++;
        updateState(currState);
        ui->logStatusLbl->setText("Login Failed");
    }else{
        log->logFailure();
        if(counter < 3){
            nextRandState();
            ui->beginBtn->setEnabled(true);
        }else{
            updateState(currState);
        }
    }
//    entryCount = 0;
//    ui->entryLbl->setText(QString::number(entryCount) + " / 7");
}

void MainWindow::on_generator_completed(){
    this->setEnabled(true);
    //qDebug() << "Poggy Woggy";
}

void MainWindow::on_logBtn_clicked(){
    qDebug() << "Log button pushed";
}

void MainWindow::on_beginBtn_clicked()
{
    ui->octaPass->setEnabled(true);
    ui->beginBtn->setEnabled(false);
    log->beginTimeLog();
}

void MainWindow::on_attemptBtn_clicked()
{
    if(allPassCreated()){
        int rand = qrand() % ((2 + 1) - 0) + 0;
        ui->beginBtn->setEnabled(true);
        succStates[counter] = rand;
        counter += 1;
        updateState(rand);
    }
}
