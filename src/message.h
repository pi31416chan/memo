#ifndef MESSAGE_H
#define MESSAGE_H

#include <ctime>
#include <iostream>
#include <string>

using namespace std;

namespace memo
{
    class Message
    {
    public:
        string title;
        string body;
        time_t lastUpdated;

        void displayLastUpdated();
    };
}

#endif // MESSAGE_H
