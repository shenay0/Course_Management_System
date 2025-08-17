#include "Admin.h"


Admin:: Admin(){
    id = 0;
    name = "admin";
    type = UserType:: Administrator;
    changePassword("0000");
}

void Admin:: writeToBinaryFile(std::ofstream& ofs) const{
    ofs.write((const char*)&id,sizeof(id));

    int length = getPassword().size();
    ofs.write((const char*)&length, sizeof(length));
    ofs.write(getPassword().data(),length);

    ofs.write((const char*)&type,sizeof(UserType));
    
    inbox.writeToBinaryFile(ofs);
}

void Admin:: loadFromBinaryFile(std::ifstream& ifs){
    ifs.read((char*)&id,sizeof(id));
    int len = 0;
    ifs.read((char*)&len, sizeof(len));

    string pass(len,'\0');
    ifs.read(&pass[0],len);

    changePassword(pass);

    ifs.read((char*)&type,sizeof(UserType));

    inbox.loadFromBinaryFile(ifs);
}

UserType Admin:: getType()const{
    return Administrator;
}

User* Admin:: clone() const{
    return new Admin(*this);
}

