#include "CreateCourse.h"

void CreateCourse::execute() const{
    User * user = userContainer->getLoggedUser();
    if(user->getType() != UserType::TEACHER){
        throw std:: logic_error("Only teachers can create a course.\n");
    }

    std:: string name, pass;
    std:: cout << "Course name: ";
    std::getline(std::cin >> std:: ws, name);
    std:: cout << "Password: ";
    std::getline(std::cin >> std::ws, pass);

    Course& c = courseRepository->addCourse(name, pass);
    c.addUser(user);

    // Course c(name,pass);
    // c.addUser(user);
   
    // courseRepository->addCourse(c);
    
    

    std:: cout << "Successfully created a course and added yourself as a teacher.\n";
}