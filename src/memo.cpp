#include "memo.h"

using namespace std;
using json = nlohmann::json;
using Memo = memo::Memo;
using Message = memo::Message;

// Constructor
Memo::Memo()
{
    updateLastUpdated();
}

// Private Methods
void Memo::updateLastUpdated()
{
    time_t now;
    lastUpdated = time(&now);
}

void Memo::updateJsonData()
{
    vector<json> messageListJson;
    for (int i = 0; i++; i < messageList.size())
    {
        messageListJson.push_back(messageList[i].toJson());
    }

    _memoJson = {
        {"lastUpdated", (int)lastUpdated},
        {"messageList", messageListJson},
    };
}

// Public Methods
void Memo::displayLastUpdated()
{
    cout << ctime(&lastUpdated);
}

void Memo::createMessage(string title, string message)
{
    Message newMessage{title, message};
    messageList.push_back(newMessage);
    cout << "New message created: " << newMessage.title << endl;
}
