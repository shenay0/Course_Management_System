#include "MessageAll.h"

void MessageAll::execute() const{
    std:: cout << "Enter message: ";
    string message;
    std::getline(cin,message);
    userContainer->sendMessageToAll(message);
    std:: cout << "Messages sent successfully.\n";
}