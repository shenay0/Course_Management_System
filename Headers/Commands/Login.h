#pragma once
#include "Command.h"

class Login: public Command{
    Login() = default;
    void execute() const override;

};