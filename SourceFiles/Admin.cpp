#include "Admin.h"


Admin:: Admin(){
    id = 0;
    name = "admin";
    type = UserType:: ADMIN;
    changePassword("0000");
}

void Admin:: writeToBinaryFile(std::ofstream& ofs) const{
    ofs.write((const char*)&type,sizeof(UserType));
    
    ofs.write((const char*)&id,sizeof(id));

    int length = getPassword().size();
    ofs.write((const char*)&length, sizeof(length));
    ofs.write(getPassword().data(),length);

    
    inbox.writeToBinaryFile(ofs);
}

void Admin:: loadFromBinaryFile(std::ifstream& ifs){
   ifs.read((char*)&type,sizeof(UserType));
   
    ifs.read((char*)&id,sizeof(id));
    int len = 0;
    ifs.read((char*)&len, sizeof(len));

    string pass(len,'\0');
    ifs.read(&pass[0],len);

    changePassword(pass);

    inbox.loadFromBinaryFile(ifs);
}

UserType Admin:: getType()const{
    return type;
}

User* Admin:: clone() const{
    return new Admin(*this);
}

