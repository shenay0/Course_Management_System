#include "Course.h"
#include "UserFactory.h"

Course::Course(const string& name, const string& pass):courseName(name), password(password){

}
void Course:: addUser(User*user){
    users.push_back(user);
}

void Course:: enroll(const string& pass, User* user){
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

const User* Course::getUserById(int id) const{
    for(int i = 0; i < users.size();i++){
        if(users[i]->getId() == id){
            return users[i];
        }
    }
    throw std::logic_error("There is no user in the course with the same id.\n");
}

User* Course::getUserByIndex(int idx) {
    return users[idx];
}

int Course:: teacherID() const{
    return users[0]->getId();
}

bool Course:: studentExists(int id) const{
    for(int i = 0; i < users.size();i++){
        if(id == users[i]->getId())     
            return true;
    }
    return false;
}

void Course::printSubmittedAssignments(const string& name) const{
    int counter = 0;
    for(int i = 0; i < assignments.size();i++){
        if(assignments[i].isSubmitted() && assignments[i].getAssignmentName() == name){
            counter++;
            assignments[i].printAssignment();
        }
    }

    if(counter == 0){
        std:: cout << "No submitted assignments." << std::endl;
    }

}

Assignment& Course:: getAssignment(const string& studentName){
    for(int i = 0; i < assignments.size();i++){
        if(assignments[i].getStudentName() == studentName)
            return assignments[i];
    }
}
const string& Course:: getCourseName() const{
    return courseName;
}

const string& Course:: getPassword() const{
    return password;
}

Assignment* Course:: getAssignment(int id, const string& assignmentName){
    for(int i = 0; i < assignments.size();i++){
        if(assignments[i].getStudentId() == id)
            return &assignments[i];
    }
    return nullptr;
}

void Course:: setPassword(const string& pass){
    if(pass.empty()){
        throw std:: logic_error("Password cannot be empty.\n");
    }
    
    password = pass;
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

    file_utills::saveStringToBinaryFile(ofs,courseName);

    file_utills::saveStringToBinaryFile(ofs,getPassword());

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

    file_utills::loadStringFromBinaryFile(ifs,courseName);

    file_utills::loadStringFromBinaryFile(ifs,password);
    
   
}



