#include "CourseRepository.h"

CourseRepository* CourseRepository:: instance = nullptr;

CourseRepository* CourseRepository:: getInstance(){
    if(!instance){
        instance = new CourseRepository();
    }
    return instance;
}

void CourseRepository:: freeInstance(){
    delete instance;
    instance = nullptr;
}

vector<Course>& CourseRepository::getCourses(){
    return courses;
}

Course* CourseRepository:: findCourse(const string& name){
    for(int i = 0; i < courses.size();i++){
        if(courses[i].getCourseName() == name){
            return &courses[i];
        }
    }

    throw std:: invalid_argument("A course with this name does not exist.\n");
}

void CourseRepository:: addCourse(const Course& course){
    courses.push_back(course);
}

void CourseRepository:: writeToBinaryFile(std::ofstream& ofs) const{
    int len = courses.size();
    ofs.write((const char*)&len,sizeof(len));

    for(int i = 0; i < len;i++){
        courses[i].writeToBinaryFile(ofs);
    }
}

void CourseRepository:: loadFromBinaryFile(std::ifstream& ifs){
    int len = 0;
    ifs.read((char*)&len,sizeof(len));

    for(int i = 0; i < len;i++){
        Course course;
        course.loadFromBinaryFile(ifs);
        courses.push_back(course);
    }
}