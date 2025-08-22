#pragma once
#include <iostream>
#include "CourseRepository.h"
#include "UserContainer.h"

class Command{
    protected:
    CourseRepository* courseRepository;
    UserContainer* userContainer;

    public: 
    Command();
    virtual void execute() const = 0;
    virtual ~Command() = default;

};