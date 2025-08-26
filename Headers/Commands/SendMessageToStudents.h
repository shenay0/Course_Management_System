#pragma once
#include "Command.h"

class SendMessageToStudents: public Command{
    public:
    SendMessageToStudents() = default;
    void execute() const override;
};

