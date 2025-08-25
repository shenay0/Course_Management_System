#include "Enroll.h"

void Enroll::execute() const{
    User* user = userContainer->getLoggedUser();
    if(user->getType() != UserType:: STUDENT){
        throw std:: logic_error("Only students can enroll.\n");
    }

    std:: string name, pass;

    std:: cout << "Name: ";
    std:: getline(std::cin, name);
    std:: cout << "Password: ";
    std:: cin >> pass;

    Course* c = courseRepository->findCourse(name);
    if(!c->checkPassword(pass)){
        throw std:: logic_error("Wrong password.\n");
    }

    c->enroll(pass,user);

    std:: cout << "You enrolled to " << c->getCourseName() << std::endl;
}