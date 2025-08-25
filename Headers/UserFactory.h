#include "Teacher.h"
#include "Admin.h"
#include "Student.h"

class UserFactory{
    public:
    static User* getUser(UserType type);
};

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