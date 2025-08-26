#include "CommandFactory.h"

CommandFactory* CommandFactory:: instance = nullptr;


CommandFactory* CommandFactory:: getInstance(){
    if(!instance){
        instance = new CommandFactory();
    }

    return instance;
}

void CommandFactory::freeInstance()
{
	delete instance;
}


Command* CommandFactory:: readCommand(const string& command) const{
    if(command == "login"){
        return new Login();
    }
    else if(command == "add_teacher"){
        return new AddTeacher();
    }
    else if(command == "add_student"){
        return new AddStudent();
    }
    else if(command == "message_all"){
        return new MessageAll();
    }
    else if(command == "logout"){
        return new LogOut();
    }
    else if(command == "change_password"){
        return new ChangePassword();
    }
    else if(command == "create_course"){
        return new CreateCourse();
    }
    else if(command == "add_to_course"){
        return new AddStudentToCourse();
    }
    else if(command == "mailbox"){
        return new Mailbox();
    }
    else if(command == "enroll"){
        return new Enroll();
    }
    else if(command == "assign_homework"){
        return new AssignHomework();
    }
    else if(command == "message_students"){
        return new SendMessageToStudents();
    }
    else if(command == "submit_assignment"){
        return new Submit();
    }
    else if(command == "message"){
        return new SendMessage();
    }
    else if(command == "view_submissions"){
        return new ViewSubmissions();
    }
    else if(command == "grade_assignment"){
        return new GradeAssignment();
    }
    else if(command == "clear_mailbox"){
        return new ClearMailbox();
    }
    else if(command == "grades"){
        return new ViewGrade();
    }
    else {
        return new InvalidCommand();
    }

}