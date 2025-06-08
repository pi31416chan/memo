#ifndef MEMO_H
#define MEMO_H

#include "message.h"
#include <ctime>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

namespace memo
{
    class Memo
    {
    private:
        json _memoJson;
        vector<Message> messageList;

        void updateLastUpdated();
        void updateJsonData();

    public:
        time_t lastUpdated;

        Memo();

        void displayLastUpdated();
        void createMessage(string title, string message);
        void deleteMessage(int index);
    };
}

#endif // MEMO_H
