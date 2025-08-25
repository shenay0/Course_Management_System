#pragma once 
#include "Command.h"

class Enroll: public Command{
   public:
   Enroll() = default;
   void execute() const override;

};

