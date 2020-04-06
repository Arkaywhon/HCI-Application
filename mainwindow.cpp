#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*QPixmap pixmap("path");
    QIcon buttonIcon(pixmap);
    ui->dispBtn1->setIcon(buttonIcon);
    ui->dispBtn1->setIconSize(pixmap.rect().size());*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int high = 7;
    int low = 0;
    int intArr[7];
    QString temp;
    QString baseArr[] = {"white", "yellow", "green", "blue", "teal", "purple", "red", "orange"};
    QString colorArr[7];
    QTextStream out(stdout);

    for(int i=0; i<7; i++){
        intArr[i] = qrand() % ((high +1) - low) + low;
    }

    for(int i=0; i<7; i++){
        colorArr[i] = baseArr[intArr[i]];
    }

    for(int i = 0; i < 7; i++){
        temp = "dispBtn" + QString::number(i);
        dispButtons[i] = this->findChild<QPushButton*>(temp);
        temp = "Background: " + colorArr[i];
        dispButtons[i]->setStyleSheet(temp);
        temp = colorArr[i];
        dispButtons[i]->setText(temp.mid(0,1).toUpper());
    }

    for(int i=0; i<7; i++){
        out << colorArr[i] << " ";
    }
    out << endl;






}
