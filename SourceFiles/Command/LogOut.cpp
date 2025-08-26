#include "LogOut.h"

void LogOut:: execute() const{
    if(userContainer->getLoggedUserId() == CONSTANTS::INVALID_USER_ID){
        throw std::logic_error("Already logged out.\n");
    }

    userContainer->logOutUser();
}
