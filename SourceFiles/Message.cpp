#include "Message.h"
#include "Constants.h"

namespace {
    static void appendIntAsString(string& str, int num){
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


Message:: Message(const string& message, const string& senderName, int receiverID):content(message),senderName(senderName){
    time_t now = std:: time(nullptr);
    tm* localTime = std::localtime(&now);

    sentOn = localTime->tm_hour < 10 ? "0" : "";
    appendIntAsString(sentOn, localTime->tm_hour);

    sentOn += ":";
    sentOn += (localTime->tm_min < 10 ? "0" : "");
    appendIntAsString(sentOn, localTime->tm_min);

    sentOn +=" ";
    sentOn += localTime->tm_mday < 10 ? "0" : "";
    appendIntAsString(sentOn, localTime->tm_mday);

    sentOn += ".";
    sentOn += localTime->tm_mon <10 ? "0" :"";
    appendIntAsString(sentOn, localTime->tm_mon);

    sentOn+=".";
    appendIntAsString(sentOn, localTime->tm_year+1990);
}

const string& Message:: getContent()const{
    return content;
}

const string& Message:: getSenderName() const{
    return senderName;
}

const string& Message:: getTime() const{
    return sentOn;
}

int Message:: getReceiverID() const{
    return receiverID;
}


void Message:: printMessage() const{
    cout << sentOn << ", sent by " << senderName <<": " << content << std::endl;
}

void Message:: writeToBinaryFile(std::ofstream& ofs)const{
    int len = content.size();
    ofs.write((const char*)&len,sizeof(len));
    ofs.write(content.data(), len);

    len = senderName.size();
    ofs.write((const char*)&len, sizeof(len));
    ofs.write(senderName.data(),len);

    len = sentOn.size();
    ofs.write((const char*)&len, sizeof(len));
    ofs.write(sentOn.data(),len);

    ofs.write((const char*)&receiverID,sizeof(receiverID));


}

void Message:: loadFromBinaryFile(std::ifstream& ifs) {
    int len = 0;
    ifs.read((char*)&len,sizeof(len));
    ifs.read(&content[0],len);

    len = 0;
    ifs.read((char*)&len,sizeof(len));
    ifs.read(&senderName[0],len);
    
    len = 0;
    ifs.read((char*)&len,sizeof(len));
    ifs.read(&sentOn[0],len);

    ifs.read((char*)&receiverID,sizeof(receiverID));
}
