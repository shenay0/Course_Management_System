#include "Assignment.h"
#include "FileUtills.h"
Assignment:: Assignment(const string& studentName, const string& courseName, const string& assignmentName):studentName(studentName), courseName(courseName), name(assignmentName){

}

void Assignment:: submit(const string& answer){
    submission = answer;
    submitted = true;
}

void Assignment:: addComment(const string& str){
    comment = str;
}

void Assignment:: setGrade(size_t gr) {
    if(grade < 2 || grade > 6) 
        throw std:: invalid_argument("Grade should be between 2 and 6.\n");

    grade = gr;
}

const string& Assignment:: getCourseName() const{
    return courseName;
}

const string& Assignment:: getStudentName() const{
    return studentName;
}

const string& Assignment::getAssignmentName() const{
    return name;
}

const string& Assignment:: getComment() const{
    return comment;
}

const string& Assignment:: getSubmission() const{
    return submission;
}

size_t Assignment:: getGrade() const{
    return grade;
}

void Assignment:: writeToBinaryFile(std::ofstream& ofs) const{

    file_utills::saveStringToBinaryFile(ofs,studentName);
    
    file_utills::saveStringToBinaryFile(ofs,courseName);

    file_utills::saveStringToBinaryFile(ofs,name);

    file_utills::saveStringToBinaryFile(ofs,comment);

    file_utills::saveStringToBinaryFile(ofs,submission);

    ofs.write((const char*)&grade,sizeof(grade));

    ofs.write((const char*)&submitted, sizeof(bool));
}

void Assignment:: loadFromBinaryFile(std:: ifstream& ifs){

    file_utills::loadStringFromBinaryFile(ifs,studentName);

    file_utills::loadStringFromBinaryFile(ifs,courseName);

    file_utills::loadStringFromBinaryFile(ifs,name);
   
    file_utills::loadStringFromBinaryFile(ifs,comment);

    file_utills::loadStringFromBinaryFile(ifs,submission);

    ifs.read((char*)&grade,sizeof(grade));

    ifs.read((char*)submitted, sizeof(bool));
}

