#include "FileUtills.h"
#include "Constants.h"

namespace file_utills{
void saveStringToBinaryFile(std::ofstream& ofs, const string& text){
    int len = text.size();
    ofs.write((const char*)&len,sizeof(len));
    ofs.write(text.data(),len);

}

void loadStringFromBinaryFile(std::ifstream& ifs, string& text){
    int len = 0;
    ifs.read((char*)&len,sizeof(len));
    ifs.read(&text[0], len);
}

void appendIntAsString(string& str, int num){
        char buffer[CONSTANTS::BUFFER];
        int len = 0;

        if(num == 0){
            buffer[len++] = '0';
        }
        else{
            char temp[CONSTANTS::BUFFER];
            while(num > 0){
                temp[len++] = num%10 + '0';
                num/=10;
            }
            for(int i = 0; i < len;i++){
                buffer[i] = temp[len - i - 1];
            }
        }
        buffer[len] = '\0';
        str +=buffer;
    }

}