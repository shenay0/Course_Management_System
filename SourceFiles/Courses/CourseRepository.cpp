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

const vector<Course>& CourseRepository::getCourses(){
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

Course& CourseRepository::addCourse(const std::string& name, const std::string& pass) {
    Course tempCourse(name, pass);

    courses.push_back(tempCourse);

    return courses[courses.size() - 1];
}

void CourseRepository:: writeToBinaryFile(std::ofstream& ofs) const{
    int len = courses.size();
    ofs.write((const char*)&len,sizeof(len));

    for(int i = 0; i < len;i++){
        int len = courses[i].getUsers().size();
        ofs.write((char*)&len,sizeof(len));

        courses[i].writeToBinaryFile(ofs);

        for(int j = 0; j < len; j++){
        int id = courses[i].getUsers()[j]->getId(); // store ID only
        ofs.write((char*)&id, sizeof(id));
        }

        
    }
}

void CourseRepository:: loadFromBinaryFile(std::ifstream& ifs, UserContainer* userContainer){
    int len = 0;
    ifs.read((char*)&len,sizeof(len));

    courses.clear();

    for(int i = 0; i < len;i++){
        int len = 0;
        ifs.read((char*)&len,sizeof(len));

        Course course;
        course.loadFromBinaryFile(ifs,userContainer);
        

        for(int j = 0; j < len; j++){
        int id;
        ifs.read((char*)&id, sizeof(id));
        User* user = userContainer->findUser(id);
        course.getUsers().push_back(user);
        }

        courses.push_back(course);
    }
}