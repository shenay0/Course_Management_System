#pragma once
#include "Command.h"

class AddStudentToCourse: public Command{
    public:
    AddStudentToCourse() = default;
    void execute() const override;

};