#pragma once
#include "Assignment.h"
#include "Student.h"
#include "Teacher.h"


class Course{
    vector<User*> users;
    vector<Assignment> assignments;
    string courseName;
    string password;

    public:
    Course() = default;
    Course(const string& name, const string& password);

    void addUser(User*);
    void addAssignment(const Assignment& assignment);
    void enroll(const string& password, User*); 

    bool checkPassword(const string& pass) const;
    void setPassword(const string&);
    
    const vector<User*>& getUsers() const;
    const vector<Assignment>& getAssignments() const;
    const string& getCourseName() const;
    const string& getPassword() const;
    const User* getUserById(int id);
    int teacherID() const;

    void writeToBinaryFile(std::ofstream& ofs) const;
    void loadFromBinaryFile(std::ifstream& ifs);

};