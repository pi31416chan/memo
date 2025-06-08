#include "util.h"
#include <iostream>

namespace util = memo::util;

void util::updateTimeStampNow(time_t *timestamp)
{
    time_t now;
    *timestamp = time(&now);
}

string util::strip(string str)
{
    string WHITESPACES = "\n\r\t ";
    string stripped = str;

    // Finding from left side
    for (int i = 0; i < str.length(); i++)
    {
        if (WHITESPACES.find(str[i]) != WHITESPACES.npos)
        {
            cout << i << endl;
            stripped.erase(i);
            cout << stripped << endl;
        }
        else
        {
            break;
        }
    }
    // Finding from right side
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (WHITESPACES.find(str[i]) != WHITESPACES.npos)
        {
            stripped.erase(i);
        }
        else
        {
            break;
        }
    }

    return stripped;
}

int util::validateNumber(string str, string errMsg = "")
{
    int index;

    try
    {
        index = stoi(str);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << str << " is not a number!" << endl;
        if (!errMsg.empty())
            std::cerr << "Error: " << errMsg << endl;
        exit(1);
    }

    return index;
}
