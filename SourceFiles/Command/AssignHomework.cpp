#include "AssignHomework.h"

void AssignHomework::execute() const{
    User* user = userContainer->getLoggedUser();
    if(user->getType() != UserType::TEACHER){
        throw std::logic_error("Only teachers can assign homework.\n");
    }

    std::string courseName, assignmentName;
    std::cout << "Course name: ";
    std::getline(std::cin >> std:: ws,courseName);
    std::cout << "Assignment name: ";
    std::getline(std::cin >> std:: ws,assignmentName);

    Course* course = courseRepository->findCourse(courseName);
    for(int i = 1; i < course->getUsers().size(); i++){//the teacher is at idx 0
        Assignment assignment(course->getUserByIndex(i)->getId(),course->getUserByIndex(i)->getName(), courseName, assignmentName);
        course->addAssignment(assignment);
    }

    std:: cout << "Sucessfully created a new assignment." << std::endl;
    
}
