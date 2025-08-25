#pragma once
#include "User.h"

class Admin: public User{
    public:
    Admin();
    ~Admin() = default;
    
    User* clone() const override;
    void writeToBinaryFile(std::ofstream& ofs) const override;
    void loadFromBinaryFile(std::ifstream& ifs) override;

};