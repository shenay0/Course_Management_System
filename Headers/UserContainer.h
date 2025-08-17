#include "Admin.h"
#include "Teacher.h"
#include "Student.h"
#include "HeterogeneousContainer.hpp"

class UserContainer{
    UserContainer() = default;
    static UserContainer* instance;
    
    HeterogeneousContainer<User> users;
    int loggedUserId = -1;

    UserContainer& operator= (const UserContainer& other)  = delete;
    UserContainer(const UserContainer& other) = delete;



    public:
    static UserContainer* getInstance();
    static void freeInstance();

    void logInUser(int id, const string& pass);
    void logOutUser();

    void createUser(User* user);
    void removeUser(int id);

    User* findUser(int id);
    User* getLoggedUser();
    //
    void writeToBinaryFile(std::ofstream& ofs)const;
    void loadFromBinaryFile(std::ifstream& ifs);

};