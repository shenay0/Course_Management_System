#include "ViewGrade.h"

void ViewGrade:: execute() const{
    User* user = userContainer->getLoggedUser();
    if(user->getType() != UserType::STUDENT){
        throw std::logic_error("Only students can view their grades.\n");
    }

    string courseName,assignmentName;
    std:: cout << "Course name: ";
    std::getline(cin,courseName);

    std:: cout << "Assignment name: ";
    std::getline(cin,assignmentName);

    Course* course = courseRepository->findCourse(courseName);
    Assignment* assignment = course->getAssignment(user->getId(),assignmentName);

    std:: cout << courseName << " | " << assignmentName << " | " << assignment->getGrade() << " | " << assignment->getComment() << std::endl;
}