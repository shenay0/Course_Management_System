#include "Enroll.h"

void Enroll::execute() const{
    User* user = userContainer->getLoggedUser();
    if(user->getType() != UserType:: STUDENT){
        throw std:: logic_error("Only students can enroll.\n");
    }

    std:: string name, pass;

    std:: cout << "Name: ";
    std:: getline(std::cin >> std:: ws, name);
    std:: cout << "Password: ";
    std::getline(std::cin >> std::ws, pass);

    Course* course = courseRepository->findCourse(name);
    if(!course->checkPassword(pass)){
        throw std:: logic_error("Wrong password.\n");
    }

    course->enroll(pass,user);

    std:: cout << "You enrolled to " << course->getCourseName() << std::endl;
}