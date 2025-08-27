#include "UserFactory.h"

 User* UserFactory:: getUser(UserType type){
    switch(type){
        case UserType:: TEACHER:
            return new Teacher();
        case UserType:: ADMIN:
            return new Admin();
        case UserType:: STUDENT:
            return new Student();
        default:
        throw std:: invalid_argument("Unknown type.\n");
    }
    
}