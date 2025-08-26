#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Assignment{
    int studentId;
    string studentName;
    string courseName;
    size_t grade = 0;
    string name;
    string comment;
    string submission;

    bool submitted = false;

    public:

    Assignment() = default;
    Assignment(int studentId,const string&studentName,const string& courseName, const string& name);
    
    void submit(const string&);
    void addComment(const string&);
    void setGrade(size_t);

    const string& getCourseName()const;
    const string& getAssignmentName()const;
    const string& getStudentName() const;
    size_t getGrade() const;
    const string& getComment() const;
    const string& getSubmission() const;
    int getStudentId() const;
    bool isSubmitted() const;
    void printAssignment() const;

    void writeToBinaryFile(std::ofstream& ofs) const;
    void loadFromBinaryFile(std:: ifstream& ifs);

};