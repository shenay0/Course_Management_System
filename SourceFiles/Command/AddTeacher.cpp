#include "AddTeacher.h"
#include <sstream>


void AddTeacher:: execute() const{
    User* user = userContainer->getLoggedUser();
    if(user->getType() != UserType:: ADMIN){
        throw std::invalid_argument("Only admins can add users.\n");
    }

    std::cout << "Teacher's name: ";
    std::string name;
    std::getline(std::cin >> std::ws, name); 

    std::cout << "Default password: ";
    std::string password;
    std::getline(std::cin >> std:: ws, password);  

    Teacher* teacher = new Teacher(name, password);
    userContainer->createUser(teacher);


}