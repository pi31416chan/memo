#include "memo.h"

using Memo = memo::Memo;

// Constructor
Memo::Memo()
{
    util::updateTimeStampNow(&lastUpdated);
}

// Private Methods
void Memo::updateJsonData()
{
    json messageListJson = {};
    for (int i = 0; i < messageList.size(); i++)
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

void Memo::deleteMessage(int index)
{
    string ans;
    cout << "Delete message " << index << " from memo?" << endl;
    cout << "Preview: " << messageList[index - 1].title << "(y/N)" << endl;
    cin >> ans;

    if (tolower(ans[0]) == 'y')
    {
        messageList.erase(messageList.begin() + index - 1);
    }
    else
    {
        cout << "Not deleting" << endl;
    }
}
