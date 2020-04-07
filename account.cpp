#include "account.h"

Account::Account()
{
    passwordExists = false;
}

bool Account::getPassStatus(){return passwordExists;}
void Account::setPassword(QString *p){
    for(int i = 0; i < 7; i ++) password[i] = p[i];
    passwordExists = true;
}
