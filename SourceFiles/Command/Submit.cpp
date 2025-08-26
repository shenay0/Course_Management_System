#include "Submit.h"

void Submit::execute() const{
    User* user = userContainer->getLoggedUser();
    std::cout << "Course name: ";
    string courseName;
    std::getline(cin,courseName);

    Course* course = courseRepository->findCourse(courseName);
    if(!course->studentExists(user->getId())){
        throw std::logic_error("This student is not in this course.\n");
    }

    string submission;
    std::getline(cin,submission);
    
    course->getAssignment(user->getName()).submit(submission);
    
}