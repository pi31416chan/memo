#ifndef MEMO_H
#define MEMO_H

#include "message.h"
#include "util.h"
#include <ctime>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using namespace std;
using json = nlohmann::json;
using Message = memo::Message;

namespace memo
{
    class Memo
    {
    private:
        json _memoJson;
        vector<Message> messageList;

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
