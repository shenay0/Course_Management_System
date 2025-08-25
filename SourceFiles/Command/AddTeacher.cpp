#include "AddTeacher.h"
#include <sstream>


void AddTeacher:: execute() const{
    std::cout << "Teacher's name: ";
    std::string name;
    std::getline(std::cin >> std::ws, name); 

    std::cout << "Default password: ";
    std::string password;
    std::getline(std::cin, password);  

    Teacher* teacher = new Teacher(name, password);
    userContainer->createUser(teacher);


}