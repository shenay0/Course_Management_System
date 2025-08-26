#include "ViewSubmissions.h"

void ViewSubmissions::execute() const{
    User* teacher = userContainer->getLoggedUser();
    if(teacher->getType() != UserType::TEACHER){
        throw std::logic_error("Only teachers can see assignment submissions.\n");
    }

    string courseName, assignmentName;
    std:: cout << "Course name: ";
    std::getline(cin,courseName);
    std::cout<<"Assignment name: ";
    std::getline(cin,assignmentName);

    Course* course = courseRepository->findCourse(courseName);
    course->printSubmittedAssignments(assignmentName);
}
