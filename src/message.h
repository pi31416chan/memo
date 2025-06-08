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
    private:
        void updateLastUpdated();
        void updateCreated();

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
