#include "constant.h"
#include "memo.h"
#include <iostream>
#include <nlohmann/json.hpp>

namespace util = memo::util;
using namespace std;
using json = nlohmann::json;
using Memo = memo::Memo;

int main(int argc, char const *argv[])
{
    Memo m;

    if (argc == 1)
    {
        // Show Help
        cout << HELP_MESSAGE;
        return 0;
    }

    string command = argv[1];
    string content;
    for (size_t i = 2; i < argc; i++)
    {
        content += argv[i];
        if (i != argc - 1)
            content += ' ';
    }

    if (command == "-h" || command == "--help" || command == "help")
    {
        cout << HELP_MESSAGE;
    }
    else if (command == "rm" && argc == 3)
    {
        int index = util::validateNumber(argv[2], "Only number is allowed for \"rm\" command!");
        m.deleteMessage(index);
        m.save();
    }
    else if (command == "show" && argc == 3)
    {
        int index = util::validateNumber(argv[2], "Only number is allowed for \"show\" command!");
        m.showMessage(index);
    }
    else if (command == "list" && argc == 2)
    {
        m.listAll();
    }
    else if (command == "clear" && argc == 2)
    {
        // Clear
    }
    else if (command == "create" && argc == 2)
    {
        string title;
        string body;

        cout << "Enter the message title:" << endl;
        getline(cin, title);

        cout << "\nEnter the message body (Press Enter twice to complete):" << endl;
        string line;
        do
        {
            getline(cin, line);
            body += line;
            if (!line.empty())
                body += '\n';
        } while (!line.empty());

        m.createMessage(title, body);
        m.save();
    }
    else
    {
        content = command + ' ' + content;

        m.createMessage(content);
        m.save();
    }
}
