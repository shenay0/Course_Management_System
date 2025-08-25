#pragma once
#include "Command.h"


class Logout: public Command{
    public:
    Logout() = default;
    void execute() const override;
};