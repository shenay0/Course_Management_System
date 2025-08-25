#pragma once
#include "Command.h"

class MessageAll: public Command{
    public:
    MessageAll()=default;
    void execute() const override;
};