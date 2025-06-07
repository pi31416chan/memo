#include "memo.h"
#include <ctime>
#include <iostream>
#include <string>

using Memo = memo::Memo;

void Memo::updateLastUpdated()
{
    time_t now;
    _lastUpdated = time(&now);
}

time_t Memo::lastUpdated()
{
    return _lastUpdated;
}

void Memo::displayLastUpdated()
{
    cout << ctime(&_lastUpdated);
}
