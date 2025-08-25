#pragma once
#include "Command.h"

class Mailbox: public Command{
    public:
    Mailbox() = default;
    void execute() const override;

};