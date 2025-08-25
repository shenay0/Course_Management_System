#pragma once
#include "Command.h"

class AddTeacher: public Command{
    public:
    AddTeacher() = default;
    void execute() const override;

};