#include "Inbox.h"

void Inbox:: addMessage(const Message& msg){
    messages.push_back(msg);
}

void Inbox:: clear(){
    messages.clear();
}

void Inbox:: printInbox() const{
    for(int i = 0; i < messages.size();i++){
        messages[i].printMessage();
        cout << endl;
    }
}

void Inbox:: writeToBinaryFile(std::ofstream&ofs) const{
    int len = messages.size();
    ofs.write((const char*)&len, sizeof(len));
    
    for(int i = 0; i <len;i++){
        messages[i].writeToBinaryFile(ofs);
    }
}

void Inbox:: loadFromBinaryFile(std:: ifstream& ifs){
    int len =  0;
    ifs.read((char*)&len,sizeof(len));

    for(int i = 0; i < len;i++){
        Message msg;
        msg.loadFromBinaryFile(ifs);
        messages.push_back(msg);
    }
}