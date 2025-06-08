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

        Message(string title);
        Message(string title, string body);
        Message(json messageJson);

        string strCreated();
        string strLastUpdated();
        json toJson();
        void show();
    };
}

#endif // MESSAGE_H
