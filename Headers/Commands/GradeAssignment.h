#pragma once
#include "Command.h"

class GradeAssignment: public Command{
    public:
    GradeAssignment() = default;
    void execute() const override;
};