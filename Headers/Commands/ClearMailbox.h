#pragma once
#include "Command.h"

class ClearMailbox: public Command{
    public:
    ClearMailbox() = default;
    void execute() const override;
};