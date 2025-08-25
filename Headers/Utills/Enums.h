#pragma once
#include <iostream>

enum UserType{
    STUDENT,
    TEACHER,
    ADMIN
};

std::string toString(UserType type);