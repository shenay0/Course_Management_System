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

    void addUser(User*); // teacher adds
    void addAssignment(const Assignment& assignment);
    void addUser(const string& pass, User*); // student adds himself/herself

    bool checkPassword(const string& pass) const;

    const vector<User*>& getUsers() const;
    const vector<Assignment>& getAssignments() const;
    const string& getCourseName() const;
    const string& getPassword() const;

    void writeToBinaryFile(std::ofstream& ofs) const;
    void loadFromBinaryFile(std::ifstream& ifs);

};