#include "Teacher.h"
#include "Admin.h"
#include "Student.h"

class UserFactory{
    public:
    static User* getUser(UserType type);
};

