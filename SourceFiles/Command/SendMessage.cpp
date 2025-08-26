#include "SendMessage.h"

void SendMessage::execute() const{
    User* sender = userContainer->getLoggedUser();
    std::cout << "Receiver id: ";
    int id;
    std::cin >> id;

    User* receiver = userContainer->findUser(id);
    std::string content;
    std::getline(cin,content);

    Message message(content,sender->getName(), receiver->getId());
    receiver->addMessageToInbox(message);
}