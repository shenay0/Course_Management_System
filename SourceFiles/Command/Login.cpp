#include "Login.h"

void Login:: execute() const{
    std:: string password;
    size_t id;
    std::cout << "Enter your ID and password.\n";
    cin >> id >> password;

    if(userContainer->getLoggedUser()){
        throw std:: invalid_argument("You are already logged in.\n");
    }

    userContainer->logInUser(id,password);

}