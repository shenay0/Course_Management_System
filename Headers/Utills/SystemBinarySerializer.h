#pragma once
#include "UserContainer.h"
#include "CourseRepository.h"
#include <fstream>

class SystemBinarySerializer{
    static UserContainer* userContainer;
    static CourseRepository* courseRepository;

    public:
    SystemBinarySerializer() = default;
    static void saveToBinaryFile();
    static void loadFromBinaryFile();
};

size_t getFileSize(std::ifstream& ifs);