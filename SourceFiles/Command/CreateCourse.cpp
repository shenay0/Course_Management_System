#include "CreateCourse.h"

void CreateCourse::execute() const{
    User * user = userContainer->getLoggedUser();
    if(user->getType() != UserType::TEACHER){
        throw std:: logic_error("Only teachers can create a course.\n");
    }

    std:: string name, pass;
    std:: cout << "Course name: ";
    std::getline(std::cin, name);
    std:: cout << "Password: ";
    std:: cin >> pass;

    Course c(name,pass);
    courseRepository->addCourse(c);
    
    c.addUser(user);

    std:: cout << "Successfully created a course and added yourself as a teacher.\n";
}