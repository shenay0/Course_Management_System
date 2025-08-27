#include "AddStudentToCourse.h"

void AddStudentToCourse::execute() const{
    User* user = userContainer->getLoggedUser();
    if(user->getType() != UserType:: TEACHER){
        throw std::invalid_argument("Only teachers can add students to course.\n");
    }

    std:: cout << "Course name: ";
    std::string name;
    std::getline(std::cin>>std::ws,name);
    Course* course = courseRepository->findCourse(name);

    if(course->teacherID() != user->getId()){
        throw std:: invalid_argument("This teacher is not in the course.\n");
    }

    int studentId;
    std::cout << "Student id: ";
    std:: cin >> studentId;

    User* student = userContainer->findUser(studentId);
    course->addUser(student);
}