#include "memo.h"

using namespace std;
using json = nlohmann::json;
using Memo = memo::Memo;

// Private Methods
void Memo::updateLastUpdated()
{
    time_t now;
    _lastUpdated = time(&now);
}

void Memo::updateJsonData()
{
    _memoJson = {
        {"_lastUpdated", (int)_lastUpdated},
    };
}

// Public Methods
time_t Memo::lastUpdated()
{
    return _lastUpdated;
}

void Memo::displayLastUpdated()
{
    cout << ctime(&_lastUpdated);
}
