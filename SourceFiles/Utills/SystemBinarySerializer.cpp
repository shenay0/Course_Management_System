#include "SystemBinarySerializer.h"
#include "Constants.h"

UserContainer* SystemBinarySerializer::userContainer = UserContainer::getInstance();
CourseRepository* SystemBinarySerializer::courseRepository = CourseRepository::getInstance();


void SystemBinarySerializer::saveToBinaryFile(){
    std:: ofstream ofs(CONSTANTS::FILE_NAME,std::ios::binary | std::ios::trunc);

    if(!ofs.is_open()){
        throw std::logic_error("Failed to open file.\n");
    }

    userContainer->writeToBinaryFile(ofs);
    courseRepository->writeToBinaryFile(ofs);

};

void SystemBinarySerializer::loadFromBinaryFile(){
    std::ifstream ifs(CONSTANTS::FILE_NAME,std::ios::binary);

    if(!ifs.is_open()){ // if it's not open, creates an empty file 
        std::ofstream ofs(CONSTANTS::FILE_NAME,std::ios::binary);
        ofs.close();
        return;
    }


    if(getFileSize(ifs) == 0){
        return;
    }

    userContainer->loadFromBinaryFile(ifs);
    courseRepository->loadFromBinaryFile(ifs, userContainer);
}

size_t getFileSize(std::ifstream& ifs){

	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currPos, std::ios::beg);
	return size;

}