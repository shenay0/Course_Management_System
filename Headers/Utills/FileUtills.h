#include "Enums.h"
#include <fstream>
using namespace std;

namespace file_utills{
    void saveStringToBinaryFile(std::ofstream& ofs, const string& txt);
    void loadStringFromBinaryFile(std::ifstream& ifs, string& txt);
    void appendIntAsString(string& str,int num);
}