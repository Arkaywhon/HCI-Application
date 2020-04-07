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

bool Account::comparePasswords(QString *a){
    for(int i = 0; i < 7; i ++){
        if(a[i].compare(password[i]) != 0) return false;
    }
    return true;
}
