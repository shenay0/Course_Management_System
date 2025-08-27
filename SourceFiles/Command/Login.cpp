#include "Login.h"

void Login:: execute() const{
    std:: string password;
    size_t id;
    std::cout << "Enter your ID and password.\n";
    cin >> id >> password;

    userContainer->logInUser(id,password);
    
}