#pragma once
#include "Command.h"


class ChangePassword: public Command{
    ChangePassword() = default;
    void execute() const override;
};