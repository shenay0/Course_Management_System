#include "Course.h"
#include "UserFactory.h"

Course::Course(const string& name, const string& pass):courseName(name), password(password){

}
void Course:: addUser(User*user){
    users.push_back(user);
}

void Course:: addUser(const string& pass, User* user){
    if(!checkPassword(pass)){
        throw std::invalid_argument("Invalid password for course.\n");
    }

    addUser(user);
}

void Course:: addAssignment(const Assignment& assignment){
    assignments.push_back(assignment);
}

bool Course:: checkPassword(const string& pass) const{
    return (pass == password);
}

const vector<User*>& Course:: getUsers() const{
    return users;
}

const vector<Assignment>& Course:: getAssignments() const{
    return assignments;
}

const string& Course:: getCourseName() const{
    return courseName;
}

const string& Course:: getPassword() const{
    return password;
}

void Course:: writeToBinaryFile(std::ofstream& ofs) const{
    int len = users.size();
    ofs.write((const char*)&len,sizeof(len));
    for(int i = 0; i < len; i++){
        UserType t = users[i]->getType();
        ofs.write((const char*)&t,sizeof(t));
        users[i]->writeToBinaryFile(ofs);
    }

    len = assignments.size();
    ofs.write((const char*)&len,sizeof(len));
    for(int i = 0; i < len;i++){
        assignments[i].writeToBinaryFile(ofs);
    }

    len = courseName.size();
    ofs.write((const char*)&len,sizeof(len));
    ofs.write(courseName.data(),len);

    len = password.size();
    ofs.write((const char*)&len,sizeof(len));
    ofs.write(password.data(), len);

}

void Course::loadFromBinaryFile(std::ifstream& ifs){
    int len = 0;
    ifs.read((char*)&len,sizeof(len));
    for(int i = 0; i < len; i++){
        UserType t;
        ifs.read((char*)&t,sizeof(t));
        User* user = UserFactory:: getUser(t);
        user->loadFromBinaryFile(ifs);

        users.push_back(user);
    }

    len = 0;
    ifs.read((char*)&len,sizeof(len));
    for(int i = 0; i < len; i++){
        Assignment a;
        a.loadFromBinaryFile(ifs);
        assignments.push_back(a);
    }

    len = 0;
    ifs.read((char*)&len,sizeof(len));
    ifs.read(&courseName[0],len);

    len = 0;
    ifs.read((char*)&len,sizeof(len));
    ifs.read(&password[0],len);
}



