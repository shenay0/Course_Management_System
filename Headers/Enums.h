#pragma once
#include <iostream>

enum UserType{
    STUDENT,
    TEACHER,
    ADMIN
};

inline std::string toString(UserType type) {
    switch (type) {
        case UserType::ADMIN:   return "Admin";
        case UserType::STUDENT: return "Student";
        case UserType::TEACHER: return "Teacher";
    }
    return "Unknown";
}