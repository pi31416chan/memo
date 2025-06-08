#ifndef MESSAGE_H
#define MESSAGE_H

#include <ctime>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

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
        json toJson();
    };
}

#endif // MESSAGE_H
