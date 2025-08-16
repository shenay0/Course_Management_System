#include "User.h"
int User:: idCounter = 100;

User:: User(const string& name, const string& password): name(name), password(password){
    
}

const string& User:: getName() const{
    return name;
}

const string& User:: getPassword() const{
    return password;
}

int User:: getId() const{
    return id;
}

void User:: changePassword(const string& newPass){
    password = newPass;
}
