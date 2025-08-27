#include "GradeAssignment.h"

void GradeAssignment::execute() const{
    User* teacher = userContainer->getLoggedUser();
    if(teacher->getType() != UserType::TEACHER){
        throw std::logic_error("Only teacher can grade assignments.\n");
    }

    string courseName, assignmentName, comment;
    int id;

    std::cout << "Course name: ";
    std::getline(std::cin >> std:: ws,courseName);

    std::cout << "Assignment name: ";
    std::getline(std::cin >> std:: ws,assignmentName);

    std::cout << "Student id: ";
    std::cin >> id;

    Course* course = courseRepository->findCourse(courseName);
    Assignment* assignment = course->getAssignment(id,assignmentName);
    if(!assignment->isSubmitted() && !assignment){
        throw std::logic_error("Assignment is not submitted.\n");
    }

    int grade;
    std::cin >> grade;
    std::getline(cin,comment);

    assignment->addComment(comment);
    assignment->setGrade(grade);

}