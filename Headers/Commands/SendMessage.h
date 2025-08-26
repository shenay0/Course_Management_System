#pragma once
#include "Command.h"

class SendMessage: public Command{
    public: 
    SendMessage() = default;
    void execute() const override;
};