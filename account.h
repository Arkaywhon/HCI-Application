#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class Account
{
public:
    Account();
    bool getPassStatus();
    void setPassword(QString*);

private:
    bool passwordExists;
    QString password[7];

};

#endif // ACCOUNT_H
