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
    void on_conButton_clicked();

private:
    QPushButton *dispButtons[7];
    QPushButton *conButton;

    int intArr[7];
    QString baseArr[8];
    QString colorArr[7];

    void initBaseArr();
    void initDispBtns(int, int);
    void generatePassword();
};

#endif // GENERATOR_H
