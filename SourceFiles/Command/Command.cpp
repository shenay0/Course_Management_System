#include "Command.h"

Command:: Command(){
    courseRepository = CourseRepository:: getInstance();
    userContainer = UserContainer::getInstance();
}