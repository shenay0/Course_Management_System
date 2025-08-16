#include "Teacher.h"

Teacher:: Teacher(const string& name, const string& pass):User(name,pass){
    id = idCounter++;
    type = UserType::Teacher;
} 

void Teacher:: writeToBinaryFile(std::ofstream& ofs) const{
    int len = name.size();
    ofs.write((const char*)&len, sizeof(len));
    ofs.write(name.data(),len);

    len = getPassword().size();
    ofs.write((const char*)&len,sizeof(len));
    ofs.write(getPassword().data(),len);

    ofs.write((const char*)&id,sizeof(id));

    ofs.write((const char*)&type,sizeof(UserType));
}

void Teacher:: loadFromBinaryFile(std::ifstream&ifs){
    int len = 0;
    ifs.read((char*)&len,sizeof(len));
    ifs.read(&name[0],len);

    len = 0;
    ifs.read((char*)&len,sizeof(len));
    string pass(len,'\0');
    ifs.read(&pass[0], len);

    ifs.read((char*)&id,sizeof(id));
    
    ifs.read((char*)&type,sizeof(UserType));
}

UserType Teacher:: getType() const{
    return type;
}