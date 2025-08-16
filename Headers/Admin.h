#pragma once
#include "User.h"

class Admin: public User{
    public:
    Admin();
    ~Admin() = default;

    void createTeacher(const string& name, const string& pass);
    void createStudent(const string& name,const string& pass);
    void deleteTeacher(int id);
    void deleteStudent(int id);
    
    User* clone() const override;
    void writeToBinaryFile(std::ofstream& ofs) const override;
    void loadFromBinaryFile(std::ifstream& ifs) override;
    UserType getType() const override;

};