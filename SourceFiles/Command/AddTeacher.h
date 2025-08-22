#pragma once
#include "Command.h"

class AddTeacher: public Command{
    public:
    AddTeacher() = default;
    virtual void execute() const override;

};