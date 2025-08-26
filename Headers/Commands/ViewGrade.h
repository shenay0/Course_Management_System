#pragma once
#include "Command.h"

class ViewGrade: public Command{
    public:
    ViewGrade() = default;
    void execute() const override;
};