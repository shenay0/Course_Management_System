#include "User.h"
int User:: idCounter = 100;

User:: User(const string& name, const string& password): name(name), password(password){

}

int User::getIdCounter(){
    return idCounter;
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

void User::setIdCounter(int counter){
    idCounter = counter;
}

UserType User:: getType() const{
    return type;
}

void User:: changePassword(const string& newPass){
    password = newPass;
}

bool User:: isPasswordCorrect(const string& pass)const{
    return(pass==password);
}

void User:: printInbox() const{
    inbox.printInbox();
}

void User:: addMessageToInbox(const Message& msg){
    inbox.addMessage(msg);
}

void User:: clearInbox(){
    inbox.clear();
}