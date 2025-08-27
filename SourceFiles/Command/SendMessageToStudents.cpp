#include "SendMessageToStudents.h"

void SendMessageToStudents::execute() const{
    User* user = userContainer->getLoggedUser();
    if(user->getType() != UserType::TEACHER){
        throw std::logic_error("Only teacher in the course can send message to all students.\n");
    }
    string courseName, content;
    std:: cout << "Course name: ";
    std::getline(std::cin>>std::ws,courseName);

    std::cout << "Content: ";
    std::getline(std::cin>>std::ws,content);
    Course* course = courseRepository->findCourse(courseName);

    for(int i = 1; i < course->getUsers().size();i++){
        Message message(content, user->getName(), course->getUserByIndex(i)->getId());
        course->getUserByIndex(i)->addMessageToInbox(message);
    }

}