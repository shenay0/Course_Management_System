#include "AddStudent.h"

void AddStudent:: execute()const{
    std:: cout << "Student's name: ";
    std:: string name;
    std:: getline(std::cin>>std::ws,name);

    std::cout << "Default password: ";
    std::string password;
    std::getline(std::cin >> std:: ws, password);  

    Student* student = new Student(name,password);
    userContainer->createUser(student);
    
}