#include "memo.h"

using Memo = memo::Memo;

// Constructor
Memo::Memo()
{
    createMemoHome();
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

void Memo::createMemoHome()
{
    fs::create_directories(MEMO_HOME);
}

// Public Methods
string Memo::strLastUpdated()
{
    string t = (string)ctime(&lastUpdated);

    return util::strip(t);
}

void Memo::createMessage(string title)
{
    Message newMessage{title};
    messageList.push_back(newMessage);
    cout << "New message created: " << newMessage.title << endl;
}

void Memo::createMessage(string title, string message)
{
    Message newMessage{title, message};
    messageList.push_back(newMessage);
    cout << "New message created: " << newMessage.title << endl;
}

void Memo::showMessage(int index)
{
    if (index > 0 && index <= messageList.size())
    {
        messageList[index - 1].show();
    }
    else
    {
        cout << "Message " << index << " not available!" << endl;
    }
}

void Memo::deleteMessage(int index)
{
    string ans;
    messageList[index - 1].show();
    cout << "Delete message " << index << " from memo? (y/N)" << endl;
    cin >> ans;

    if (tolower(ans[0]) == 'y')
    {
        messageList.erase(messageList.begin() + index - 1);
        cout << "Message " << index << " deleted from memo" << endl;
    }
    else
    {
        cout << "Not deleting" << endl;
    }
}

void Memo::listAll()
{
    cout << "Memo list:" << endl;
    cout << "Index   Title" << endl;
    for (int i = 0; i < messageList.size(); i++)
    {
        cout << i + 1 << "       " << messageList[i].title << endl;
    }
}

void Memo::save()
{
    updateJsonData();

    ofstream ofile(MEMO_DATAFILE);
    ofile << _memoJson.dump();
    ofile.close();

    cout << "Memo saved successfully!" << endl;
}
