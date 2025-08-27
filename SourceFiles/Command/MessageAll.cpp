#include "MessageAll.h"

void MessageAll::execute() const{
    User* user = userContainer->getLoggedUser();
    if(user->getType() != UserType::ADMIN){
        throw std::logic_error("Only admin can send message to all.\n");
    }
    std::cout << "Enter message: ";
    string message;
    std::getline(std::cin>>std::ws,message);
    userContainer->sendMessageToAll(message);
    std:: cout << "Messages sent successfully.\n";
}