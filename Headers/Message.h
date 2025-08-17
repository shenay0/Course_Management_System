#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class Message{
    string content;
    string senderName;
    string sentOn;
    int receiverID = -1;

    public:
    Message() = default;
    Message(const string& message, const string& senderName,int receiverID);

    const string& getContent() const;
    const string& getSenderName() const;
    int getReceiverID()const;
    const string& getTime() const;

    void printMessage() const;

    void writeToBinaryFile(std::ofstream& ofs) const;
    void loadFromBinaryFile(std::ifstream& ifs);

};
