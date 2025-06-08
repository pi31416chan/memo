#ifndef MEMO_H
#define MEMO_H

#include "constant.h"
#include "message.h"
#include "util.h"
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

namespace fs = std::filesystem;
using namespace std;
using json = nlohmann::json;
using Message = memo::Message;

namespace memo
{
    class Memo
    {
    private:
        json _memoJson;
        vector<Message> _messageList;

        void updateJsonData();
        void createMemoHome();

    public:
        time_t lastUpdated;

        Memo();

        string strLastUpdated();
        void createMessage(string title);
        void createMessage(string title, string message);
        void showMessage(int index);
        void deleteMessage(int index);
        void listAll();
        void clearAll();
        void save();
        void load();
        void loadProperties(json jsonData);
    };
}

#endif // MEMO_H
