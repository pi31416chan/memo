#include "memo.h"

using Memo = memo::Memo;

// Constructor
Memo::Memo()
{
    createMemoHome();

    if (!fs::exists(MEMO_DATAFILE) || fs::is_empty(MEMO_DATAFILE))
    {
        util::updateTimeStampNow(&lastUpdated);
    }
    else
    {
        load();
    }
}

// Private Methods
void Memo::updateJsonData()
{
    json messageListJson = {};
    for (int i = 0; i < _messageList.size(); i++)
    {
        messageListJson.push_back(_messageList[i].toJson());
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
    createMessage(title, "");
}

void Memo::createMessage(string title, string message)
{
    Message newMessage{title, message};
    _messageList.push_back(newMessage);
    cout << "New message created: " << newMessage.title << endl;

    util::updateTimeStampNow(&lastUpdated);
}

void Memo::showMessage(int index)
{
    if (index > 0 && index <= _messageList.size())
    {
        _messageList[index - 1].show();
    }
    else
    {
        cout << "Message " << index << " not available!" << endl;
    }
}

void Memo::deleteMessage(int index)
{
    string ans;
    _messageList[index - 1].show();
    cout << "\033[0;94mDelete message " << index << " from memo? (y/N)\033[0m" << endl;
    cin >> ans;

    if (tolower(ans[0]) == 'y')
    {
        _messageList.erase(_messageList.begin() + index - 1);
        cout << "Message " << index << " deleted from memo" << endl;
    }
    else
    {
        cout << "Aborted" << endl;
    }

    util::updateTimeStampNow(&lastUpdated);
}

void Memo::listAll()
{
    if (_messageList.size() <= 0)
    {
        cout << "No message in memo!" << endl;
    }
    else
    {
        cout << "Memo list:" << endl;
        cout << "Index   Title" << endl;
        for (int i = 0; i < _messageList.size(); i++)
        {
            cout << i + 1 << "       " << _messageList[i].title << endl;
        }
    }
}

void Memo::clearAll()
{
    string ans;
    listAll();
    cout << "\033[0;94mDelete all message from memo?\033[0m" << endl;
    cout << "\033[1;91mWARNING: This action is irreversible? (y/N)\033[0m" << endl;
    cin >> ans;

    if (tolower(ans[0]) == 'y')
    {
        _memoJson.clear();
        _messageList = {};
        lastUpdated = 0;

        fs::remove(MEMO_DATAFILE);
        cout << "Memo is cleared" << endl;
    }
    else
    {
        cout << "Aborted" << endl;
    }
}

void Memo::save()
{
    updateJsonData();

    ofstream ofile(MEMO_DATAFILE);
    ofile << _memoJson.dump();
    ofile.close();

    // cout << "Memo saved successfully!" << endl;
}

void Memo::load()
{
    _memoJson.clear();

    int fileSize = fs::file_size(MEMO_DATAFILE);
    ifstream ifile(MEMO_DATAFILE);
    char jsonContent[fileSize];

    ifile.getline(jsonContent, fileSize + 1);
    _memoJson = json::parse(string(jsonContent));
    loadProperties(_memoJson);

    // cout << "Memo loaded successfully!" << endl;
}

void Memo::loadProperties(json jsonData)
{
    lastUpdated = jsonData["lastUpdated"];
    for (size_t i = 0; i < jsonData["messageList"].size(); i++)
    {
        _messageList.push_back(Message(jsonData["messageList"][i]));
    }
}
