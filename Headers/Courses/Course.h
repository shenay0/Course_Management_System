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
    bool studentExists(int id) const;
    void setPassword(const string&);
    
    const vector<User*>& getUsers() const;
    const vector<Assignment>& getAssignments() const;
    const string& getCourseName() const;
    const string& getPassword() const;
    const User* getUserById(int id) const;
    User* getUserByIndex(int idx);
    Assignment& getAssignment(const string& studentName);
    Assignment* getAssignment(int id,const string& assignmentName);
    int teacherID() const;

    void printSubmittedAssignments(const string& name) const;

    void writeToBinaryFile(std::ofstream& ofs) const;
    void loadFromBinaryFile(std::ifstream& ifs);

};