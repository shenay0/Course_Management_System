#pragma once
#include "User.h"

class Teacher: public User{
    public:
    Teacher() = default;
    Teacher(const string& name, const string& pass);
    ~Teacher() = default;

    User* clone() const override;
    void writeToBinaryFile(std::ofstream& ofs) const override;
    void loadFromBinaryFile(std::ifstream& ifs) override;
};