#include "Admin.h"
#include "Teacher.h"
#include "Student.h"
#include "Constants.h"
#include "HeterogeneousContainer.hpp"

class UserContainer{
    UserContainer() = default;
    static UserContainer* instance;
    
    HeterogeneousContainer<User> users;
    int loggedUserId = CONSTANTS::INVALID_USER_ID;

    UserContainer& operator= (const UserContainer& other)  = delete;
    UserContainer(const UserContainer& other) = delete;



    public:
    static UserContainer* getInstance();
    static void freeInstance();

    void logInUser(int id, const string& pass);
    void logOutUser();

    void createUser(const User* user);
    void removeUser(int id);

    User* findUser(int id);
    User* getLoggedUser();
    int getLoggedUserId() const;
    void sendMessageToAll(const string& content);
    void sendMessage(int id, const string& content);

    void writeToBinaryFile(std::ofstream& ofs)const;
    void loadFromBinaryFile(std::ifstream& ifs);

};