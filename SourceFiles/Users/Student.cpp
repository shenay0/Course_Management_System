#include "Student.h"

Student:: Student(const string& name, const string& pass):User(name,pass){
    id = idCounter++;
    type = UserType:: STUDENT;
}

void Student:: writeToBinaryFile(std::ofstream&ofs)const{
   ofs.write((const char*)&type,sizeof(UserType));
   
    file_utills:: saveStringToBinaryFile(ofs,name);
    file_utills:: saveStringToBinaryFile(ofs,getPassword());

    ofs.write((const char*)&id,sizeof(id));

    inbox.writeToBinaryFile(ofs);

}

User* Student:: clone() const{
    return new Student(*this);
}

void Student:: loadFromBinaryFile(std::ifstream& ifs){
    ifs.read((char*)&type,sizeof(UserType));
   
    file_utills:: loadStringFromBinaryFile(ifs,name);

    string buff;
    file_utills:: loadStringFromBinaryFile(ifs,buff);
    changePassword(buff);

    ifs.read((char*)&id,sizeof(id));

    inbox.loadFromBinaryFile(ifs);

}