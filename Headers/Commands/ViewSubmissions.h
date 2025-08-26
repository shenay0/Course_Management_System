#pragma once
#include "Command.h"

class ViewSubmissions: public Command{
    public:
    ViewSubmissions() = default;
    void execute() const override;
};