#include "Message.h"
#include <vector>

class Inbox{
    vector<Message> messages;

    public:

    void addMessage(const Message& msg);
    void clear();
    void printInbox()const;

    void writeToBinaryFile(std::ofstream& ofs) const;
    void loadFromBinaryFile(std::ifstream& ifs);
};