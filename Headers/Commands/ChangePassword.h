#pragma once
#include "Command.h"


class ChangePassword: public Command{
    public:
    ChangePassword() = default;
    void execute() const override;
};