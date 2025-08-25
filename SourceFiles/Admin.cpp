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

    file_utills::saveStringToBinaryFile(ofs,getPassword());
    
    inbox.writeToBinaryFile(ofs);
}

void Admin:: loadFromBinaryFile(std::ifstream& ifs){
   ifs.read((char*)&type,sizeof(UserType));
   
    ifs.read((char*)&id,sizeof(id));

    string pass;
    file_utills:: loadStringFromBinaryFile(ifs,pass);

    changePassword(pass);

    inbox.loadFromBinaryFile(ifs);
}

User* Admin:: clone() const{
    return new Admin(*this);
}

