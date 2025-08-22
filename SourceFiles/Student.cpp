#include "Student.h"

Student:: Student(const string& name, const string& pass):User(name,pass){
    id = idCounter++;
    type = UserType:: STUDENT;
}

void Student:: writeToBinaryFile(std::ofstream&ofs)const{
   ofs.write((const char*)&type,sizeof(UserType));
   
    int len = name.size();
    ofs.write((const char*)&len, sizeof(len));
    ofs.write(name.data(), len);

    len = getPassword().size();
    ofs.write((const char*)&len,sizeof(len));
    ofs.write(getPassword().data(),len);

    ofs.write((const char*)&id,sizeof(id));

    inbox.writeToBinaryFile(ofs);

}

User* Student:: clone() const{
    return new Student(*this);
}

UserType Student:: getType() const{
    return type;
}
void Student:: loadFromBinaryFile(std::ifstream& ifs){
    ifs.read((char*)&type,sizeof(UserType));
   
    int len = 0;
    ifs.read((char*)&len,sizeof(len));
    ifs.read(&name[0],len);

    len = 0;
    ifs.read((char*)&len,sizeof(len));
    string pass(len,'\0');
    ifs.read(&pass[0],len);
    changePassword(pass);

    ifs.read((char*)&id,sizeof(id));

    

    inbox.loadFromBinaryFile(ifs);

}