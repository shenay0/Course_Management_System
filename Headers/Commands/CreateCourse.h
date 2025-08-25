#pragma once
#include "Command.h"


class CreateCourse: public Command{
    public:
    CreateCourse() = default;
    void execute() const override;
};