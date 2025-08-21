#include "Assignment.h"

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
    int len = studentName.size();
    ofs.write((const char*)&len,sizeof(len));
    ofs.write(studentName.data(),len);

    len = courseName.size();
    ofs.write((const char*)&len,sizeof(len));
    ofs.write(courseName.data(),len);

    len = name.size();
    ofs.write((const char*)&len,sizeof(len));
    ofs.write(name.data(),len);

    len = comment.size();
    ofs.write((const char*)&len,sizeof(len));
    ofs.write(comment.data(),len);

    len = submission.size();
    ofs.write((const char*)&len,sizeof(len));
    ofs.write(submission.data(),len);

    ofs.write((const char*)&grade,sizeof(grade));

    ofs.write((const char*)&submitted, sizeof(bool));
}

void Assignment:: loadFromBinaryFile(std:: ifstream& ifs){
    int len;
    ifs.read((char*)&len,sizeof(len));
    ifs.read(&studentName[0],len);

    len = 0;
    ifs.read((char*)&len,sizeof(len));
    ifs.read(&courseName[0],len);

    len = 0;
    ifs.read((char*)&len,sizeof(len));
    ifs.read(&name[0],len);

    len = 0;
    ifs.read((char*)&len,sizeof(len));
    ifs.read(&comment[0],len);

    len = 0;
    ifs.read((char*)&len,sizeof(len));
    ifs.read(&submission[0],len);

    ifs.read((char*)&grade,sizeof(grade));

    ifs.read((char*)submitted, sizeof(bool));
}

