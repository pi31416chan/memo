#ifndef MESSAGE_H
#define MESSAGE_H

#include "util.h"
#include <ctime>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using namespace std;
using json = nlohmann::json;

namespace memo
{
    class Message
    {
    public:
        string title;
        string body;
        time_t created;
        time_t lastUpdated;

        Message(string title, string body);

        void displayLastUpdated();
        json toJson();
    };
}

#endif // MESSAGE_H
