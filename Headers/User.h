#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Enums.h"
using namespace std;


class User{
    string password;

    protected:
    string name;
    int id;
    static int idCounter;
    UserType type;
    //Inbox

    public:
    User() = default;
    User(const string& name,const string& password);
    ~User()=default;

    const string& getName()const;
    const string& getPassword()const;
    int getId() const;
    bool isPasswordCorrect(const string& pass) const;

    void changePassword(const string& newPass);
    
    virtual User* clone() const = 0;
    virtual void writeToBinaryFile(std::ofstream& ofs) const = 0;
    virtual void loadFromBinaryFile(std::ifstream& ifs) = 0;
    virtual UserType getType() const = 0;
    
    



};