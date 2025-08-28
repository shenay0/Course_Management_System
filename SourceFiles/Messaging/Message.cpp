#include "Message.h"
#include "Constants.h"
#include "FileUtills.h"


Message:: Message(const string& message, const string& senderName, int receiverID):content(message),senderName(senderName){
    time_t now = std:: time(nullptr);
    tm* localTime = std::localtime(&now);

    sentOn = localTime->tm_hour < 10 ? "0" : "";
    file_utills::appendIntAsString(sentOn, localTime->tm_hour);

    sentOn += ":";
    sentOn += (localTime->tm_min < 10 ? "0" : "");
    file_utills::appendIntAsString(sentOn, localTime->tm_min);

    sentOn +=" ";
    sentOn += localTime->tm_mday < 10 ? "0" : "";
    file_utills::appendIntAsString(sentOn, localTime->tm_mday);

    sentOn += ".";
    sentOn += localTime->tm_mon < 10 ? "0" :"";
    file_utills::appendIntAsString(sentOn, localTime->tm_mon);

    sentOn+=".";
    file_utills::appendIntAsString(sentOn, localTime->tm_year + 1900);
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

    file_utills::saveStringToBinaryFile(ofs,content);

    file_utills::saveStringToBinaryFile(ofs,senderName);

    file_utills::saveStringToBinaryFile(ofs,sentOn);

    ofs.write((const char*)&receiverID,sizeof(receiverID));

}

void Message:: loadFromBinaryFile(std::ifstream& ifs) {
    

    file_utills::loadStringFromBinaryFile(ifs,content);

    file_utills::loadStringFromBinaryFile(ifs,senderName);

    file_utills::loadStringFromBinaryFile(ifs,sentOn);

    ifs.read((char*)&receiverID,sizeof(receiverID));
}
