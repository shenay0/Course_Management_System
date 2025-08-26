#pragma once
#include "Command.h"

class Submit: public Command{
    public:
    Submit() = default; 
    void execute() const override;
};