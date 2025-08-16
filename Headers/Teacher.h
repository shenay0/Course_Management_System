#include "User.h"

class Teacher: public User{
    //courses
    //inbox
    public:
    Teacher() = default;
    Teacher(const string& name, const string& pass);
    ~Teacher() = default;

    //void createCourse();
    //void createAssignment();
    //
    //
    //
    //

    void writeToBinaryFile(std::ofstream& ofs) const override;
    void loadFromBinaryFile(std::ifstream& ifs) override;
    UserType getType() const override;
};