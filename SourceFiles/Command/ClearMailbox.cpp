#include "ClearMailbox.h"

void ClearMailbox::execute() const{
    User* user = userContainer->getLoggedUser();
    user->clearInbox();
}