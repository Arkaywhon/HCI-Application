#include "generator.h"

Generator::Generator(QWidget *parent) : QWidget(parent)
{

    baseArr[0] = "white";
    baseArr[1] = "yellow";
    baseArr[2] = "green";
    baseArr[3] = "blue";
    baseArr[4] = "teal";
    baseArr[5] = "purple";
    baseArr[6] = "red";
    baseArr[7] = "orange";

    setFixedSize(500,150);
    for(int i = 0; i < 7; i ++){
        dispButtons[i] = new QPushButton(this);
        dispButtons[i]->show();
        dispButtons[i]->setGeometry(70 + i*(30 + 20),20,30,30);
    }
    genButton = new QPushButton(this);
    genButton->setText("Generate");
    genButton->setGeometry(100, 80, 180,30);
    /*conButton = new QPushButton(this);
    conButton->setText("Continue");
    conButton->setGeometry(280,150,150,30);*/
    connect(genButton, SIGNAL(clicked()), this, SLOT(on_genButton_clicked()));
}

void Generator::on_genButton_clicked(){

    int high = 7;
    int low = 0;
    QString temp;

    qDebug() << "I was clicked! PogU";

    for(int i=0; i<7; i++){
        intArr[i] = qrand() % ((high +1) - low) + low;
    }

    for(int i=0; i<7; i++){
        colorArr[i] = baseArr[intArr[i]];
    }

    for(int i = 0; i < 7; i++){
        temp = "Background: " + colorArr[i];
        dispButtons[i]->setStyleSheet(temp);
        temp = colorArr[i];
        dispButtons[i]->setText(temp.mid(0,1).toUpper());
    }
}

QString* Generator::getPassword(){return colorArr;}
