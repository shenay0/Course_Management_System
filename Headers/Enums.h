#pragma once
#include <iostream>

enum UserType{
    Student,
    Teacher,
    Administrator
};

inline std::string toString(UserType type) {
    switch (type) {
        case UserType::Administrator:   return "Admin";
        case UserType::Student: return "Student";
        case UserType::Teacher: return "Teacher";
    }
    return "Unknown";
}