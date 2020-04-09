#include "generator.h"

Generator::Generator(QWidget *parent) : QWidget(parent)
{
    setFixedSize(500,150);
    setWindowFlags(Qt::WindowTitleHint);

    initBaseArr();
    initDispBtns(30, 30);

    generatePassword();

    conButton = new QPushButton(this);
    conButton->setText("Continue");
    conButton->setGeometry(175,100,150,30);
    connect(conButton, SIGNAL(clicked()), this,SLOT(on_conButton_clicked()));
}

QString* Generator::getPassword(){return colorArr;}

void Generator::initBaseArr(){
    baseArr[0] = "white";
    baseArr[1] = "yellow";
    baseArr[2] = "green";
    baseArr[3] = "blue";
    baseArr[4] = "teal";
    baseArr[5] = "purple";
    baseArr[6] = "red";
    baseArr[7] = "orange";
}

void Generator::initDispBtns(int w, int h){
    for(int i = 0; i < 7; i ++){
        dispButtons[i] = new QPushButton(this);
        dispButtons[i]->show();
        dispButtons[i]->setGeometry(70+i*(w + 20), 20, w, h);
    }
}

void Generator::generatePassword(){

    QString temp;
    int low = 0, high = 7;

    for(int i=0; i<7; i++){
        intArr[i] = qrand() % ((high +1) - low) + low;
        colorArr[i] = baseArr[intArr[i]];

        dispButtons[i]->setStyleSheet("Background: " + colorArr[i]);
        dispButtons[i]->setText(colorArr[i].mid(0,1).toUpper());
    }
}

void Generator::on_conButton_clicked(){delete this;}
