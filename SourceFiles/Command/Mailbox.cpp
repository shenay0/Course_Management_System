#include "Mailbox.h"

void Mailbox::execute() const{
    User* user = userContainer->getLoggedUser();
    user->printInbox();    
}