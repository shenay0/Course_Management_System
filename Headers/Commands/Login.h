#pragma once
#include "Command.h"

class Login: public Command{
    public:
    Login() = default;
    void execute() const override;

};