#include "Enums.h"

std::string toString(UserType type) {
    switch (type) {
        case UserType::ADMIN:   return "Admin";
        case UserType::STUDENT: return "Student";
        case UserType::TEACHER: return "Teacher";
    }
    return "Unknown";
}