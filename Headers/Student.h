#pragma once
#include "User.h"

class Student: public User{
    //inbox
    public:
    Student()=default;
    Student(const string& name, const string& pass);
    ~Student()=default;


    //
    //
    //
    ///
    //

    void writeToBinaryFile(std:: ofstream&ofs)const override;
    void loadFromBinaryFile(std::ifstream& ifs) override;
    UserType getType() const override;

};