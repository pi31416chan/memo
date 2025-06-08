#include "memo.h"

using namespace std;
using json = nlohmann::json;
using Memo = memo::Memo;

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
    _memoJson = {
        {"lastUpdated", (int)lastUpdated},
    };
}

// Public Methods
void Memo::displayLastUpdated()
{
    cout << ctime(&lastUpdated);
}

void createMessage(string message)
{
    // createMessage
}
