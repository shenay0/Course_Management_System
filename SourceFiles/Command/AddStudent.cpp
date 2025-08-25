#include "AddStudent.h"

void AddStudent:: execute()const{
    User* user = userContainer->getLoggedUser();
    if(user->getType() != UserType:: ADMIN){
        throw std::invalid_argument("Only admins can add users.\n");
    }
    std:: cout << "Student's name: ";
    std:: string name;
    std:: getline(std::cin>>std::ws,name);

    std::cout << "Default password: ";
    std::string password;
    std::getline(std::cin >> std:: ws, password);  

    Student* student = new Student(name,password);
    userContainer->createUser(student);
    
}