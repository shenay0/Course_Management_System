#include "ChangePassword.h"

void ChangePassword::execute() const{
    User* user = userContainer->getLoggedUser();
    if(user->getType() == UserType:: ADMIN){
        throw std::invalid_argument("Admin cannot change password.\n");
    }
    std:: cout << "Current password: ";
    string text;
    std::getline(cin,text);

    if(!user->isPasswordCorrect(text)){
        throw std:: logic_error("Wrong password!\n");
    }
    std:: cout << "New password: ";
    string password;
    std:: getline(std::cin >>std::ws,password);
    user->changePassword(password);
    std:: cout << "Password successfully changed!\n";
}