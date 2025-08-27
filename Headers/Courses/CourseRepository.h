#pragma once
#include "Course.h"

class CourseRepository{
    static CourseRepository* instance;
    vector<Course> courses;

    CourseRepository(const CourseRepository&) = delete;
    CourseRepository& operator=(const CourseRepository&) = delete;

    public:
    CourseRepository() = default;
    static CourseRepository* getInstance();
    static void freeInstance();

    const vector<Course>& getCourses() ;
    Course* findCourse(const string& name);

    void addCourse(const Course& course);
    Course& addCourse(const string& name, const string& pass);

    void writeToBinaryFile(std::ofstream& ofs) const;
    void loadFromBinaryFile(std::ifstream& ifs);

    



};