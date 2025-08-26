#pragma once
#include "AddStudent.h"
#include "AddStudentToCourse.h"
#include "AddTeacher.h"
#include "AssignHomework.h"
#include "ChangePassword.h"
#include "ClearMailbox.h"
#include "Command.h"
#include "CreateCourse.h"
#include "Enroll.h"
#include "GradeAssignment.h"
#include "InvalidCommand.h"
#include "Login.h"
#include "LogOut.h"
#include "Mailbox.h"
#include "MessageAll.h"
#include "SendMessage.h"
#include "SendMessageToStudents.h"
#include "Submit.h"
#include "ViewGrade.h"
#include "ViewSubmissions.h"


class CommandFactory{
    static CommandFactory* instance;
    CommandFactory() =default;

    public:
    static CommandFactory* getInstance();
    static void freeInstance();

    Command* readCommand(const string& command) const;
};