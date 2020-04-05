#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int high = pow(2,21);
    int low = -1;
    int randVal = qrand() % ((high + 1) - low) + low;
    std::string bin;
    //ui->numLabel->setText(QString::number(randVal));
    while( randVal > 0 ) {
            if( randVal % 2 == 0 ){
                bin.insert( bin.begin( ), '0' );
            }
            else {
                bin.insert( bin.begin( ), '1' );
            }
            randVal >>= 1;
        }
    ui->label->setText(QString::fromStdString(bin));
}
