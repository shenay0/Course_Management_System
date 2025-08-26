#pragma once
#include "Command.h"


class LogOut: public Command{
    public:
    LogOut() = default;
    void execute() const override;
};