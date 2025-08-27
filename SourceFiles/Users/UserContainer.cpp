#include "UserContainer.h"
#include "Constants.h"
#include "UserFactory.h"

UserContainer* UserContainer:: instance = nullptr;
UserContainer* UserContainer:: getInstance(){
    if(!instance){
        instance = new UserContainer();
    }
    return instance;
}

void UserContainer:: freeInstance(){
    delete instance;
    instance = nullptr;
}

void UserContainer:: logInUser(int id, const string& pass){
    User* user = findUser(id);

	if (!user || !user->isPasswordCorrect(pass))
	{
		throw std::invalid_argument("Wrong user credentials!");
	}

	loggedUserId = id;
	cout << "Login successful!\n";
    cout << user->getName() << " | " << toString(user->getType()) << " | " << user->getId() << std:: endl;
}

void UserContainer:: logOutUser(){
    loggedUserId = -1;
}

void UserContainer:: createUser(User* user){
    if(!user){
        throw std:: invalid_argument("Invalid user.\n");
    }

    users.addObject(user);
    cout <<"Added " << toString(user->getType())<< " " << user->getName() << " with ID " << user->getId() << ".\n";
}

void UserContainer:: removeUser(int id){
    for(int i = 0; i < users.getSize();i++){
        if(users[i]->getId()==id){
            users.remove(i);
        }
    }
    cout << "Successfully removed user with ID " << id <<".\n";

    
}

void UserContainer:: sendMessage(int id, const string& content){
    User* user = findUser(id);
    Message msg(content, getLoggedUser()->getName(), id);
    user->addMessageToInbox(msg);
}

int UserContainer:: getLoggedUserId() const{
    return loggedUserId;
}

User* UserContainer:: findUser(int id){
    for(int i = 0; i < users.getSize();i++){
        if(users[i]->getId()==id){
            return users[i];
        }
    }

    throw std::invalid_argument("Invalid id.\n");
}

User* UserContainer::find(int id){
    for(int i = 0; i < users.getSize();i++){
        if(users[i]->getId()==id){
            return users[i];
        }
    }

    return nullptr;
}

void UserContainer::sendMessageToAll(const string& content){
    User* admin = findUser(CONSTANTS::ADMIN_INDEX);
    for(int i = 1; i < users.getSize();i++){
        Message msg(content, admin->getName(),users[i]->getId());
        users[i]->addMessageToInbox(msg);
    }
}
User* UserContainer:: getLoggedUser(){
    if(loggedUserId == -1){
        throw std::logic_error("Login first.\n");
    }

    
    User* user = findUser(loggedUserId);
    return user;
}

void UserContainer:: writeToBinaryFile(std::ofstream& ofs) const{
    ofs.write((const char*)&loggedUserId, sizeof(loggedUserId));

    int len = users.getSize();
    ofs.write((const char*)&len,sizeof(len));
    for(int i = 0;i < len;i++){
        UserType t = users[i]->getType();
        ofs.write((const char*)&t,sizeof(t));
        users[i]->writeToBinaryFile(ofs);
    }
    int idCounter = User::getIdCounter();
    ofs.write((const char*)&idCounter,sizeof(idCounter));
}

void UserContainer::loadFromBinaryFile(std::ifstream&ifs){
    ifs.read((char*)&loggedUserId,sizeof(loggedUserId));

    int len = 0;
    ifs.read((char*)&len,sizeof(len));
    
    //users.clear();//deletes the objects in the container and the container itself

    for(int i = 0; i < len; i++ ){
        UserType t;
        ifs.read((char*)&t,sizeof(t));
        User* user = UserFactory:: getUser(t);
        user->loadFromBinaryFile(ifs);
        users.addObject(user);
    }

    int idCounter = 0;
    ifs.read((char*)&idCounter,sizeof(idCounter));
    User::setIdCounter(idCounter);

}