#pragma once
#include <iostream>

enum class UserType{
    STUDENT,
    TEACHER,
    ADMIN
};

std::string toString(UserType type);