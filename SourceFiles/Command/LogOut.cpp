#include "LogOut.h"

void Logout:: execute() const{
    if(!userContainer->getLoggedUser()){
        throw std::logic_error("Already logged out.\n");
    }

    userContainer->logOutUser();
}
