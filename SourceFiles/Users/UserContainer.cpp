#include "UserContainer.h"
#include "Constants.h"
#include "UserFactory.h"
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
}

void UserContainer:: logOutUser(){
    loggedUserId = -1;
}

void UserContainer:: createUser(const User* user){
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

User* UserContainer:: findUser(int id){
    for(int i = 0; i < users.getSize();i++){
        if(users[i]->getId()==id){
            return users[i];
        }
    }

    throw std::invalid_argument("Invalid id.\n");
}

void UserContainer::sendMessageToAll(const string& content){
    if(loggedUserId != CONSTANTS::ADMIN_INDEX){
        throw std::logic_error("Only admin can send message to all.\n");
    }
    User* admin = findUser(CONSTANTS::ADMIN_INDEX);
    for(int i = 1; i < users.getSize();i++){
        Message msg(content, admin->getName(),users[i]->getId());
        users[i]->addMessageToInbox(msg);
    }
}
User* UserContainer:: getLoggedUser(){
    if(loggedUserId == -1) return nullptr;
    
    User* user = findUser(loggedUserId);
    return user;
}

void UserContainer:: writeToBinaryFile(std::ofstream& ofs) const{
    ofs.write((const char*)&loggedUserId, sizeof(loggedUserId));

    int len = users.getSize();
    ofs.write((const char*)&len,sizeof(len));
    for(int i =0;i < len;i++){
        UserType t = users[i]->getType();
        ofs.write((const char*)&t,sizeof(t));
        users[i]->writeToBinaryFile(ofs);
    }
}

void UserContainer::loadFromBinaryFile(std::ifstream&ifs){
    ifs.read((char*)&loggedUserId,sizeof(loggedUserId));

    users.clear();

    int len = 0;
    ifs.read((char*)&len,sizeof(len));
    
    for(int i = 0; i < len; i++ ){
        UserType t;
        ifs.read((char*)&t,sizeof(t));
        User* user = UserFactory:: getUser(t);
        user->loadFromBinaryFile(ifs);
        users.addObject(user);
    }

}