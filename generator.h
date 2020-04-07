#ifndef GENERATOR_H
#define GENERATOR_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>

class Generator : public QWidget
{
    Q_OBJECT
public:
    explicit Generator(QWidget *parent = nullptr);
    QString* getPassword();

private slots:
    void on_genButton_clicked();

private:
    QPushButton *dispButtons[7];
    QPushButton *genButton;
    //QPushButton *conButton;

    int intArr[7];
    QString baseArr[8];
    QString colorArr[7];

signals:

};

#endif // GENERATOR_H
