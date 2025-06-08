#ifndef CONSTANT_H
#define CONSTANT_H

#include <cstdlib>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;
using path = fs::path;

const string LOCAL_DIRNAME = ".local/share";
const string MEMO_HOME_NAME = "memo";
const string MEMO_DATAFILE_NAME = "data.json";
const fs::path USER_HOME = string(getenv("HOME"));
const fs::path MEMO_HOME = USER_HOME / LOCAL_DIRNAME / MEMO_HOME_NAME;
const fs::path MEMO_DATAFILE = MEMO_HOME / MEMO_DATAFILE_NAME;

const string HELP_MESSAGE =
    "Usage: memo [command] [message]\n"
    "\n"
    "memo   <message>       Create oneline message in memo\n"
    "memo   create          Create message with title and body in memo\n"
    "memo   list            List all messages in memo\n"
    "memo   show <number>   Show selected message by index number\n"
    "memo   rm <number>     Delete selected message by index number\n"
    "memo   clear           Clear all messages from memo (irreversible)\n";

#endif // CONSTANT_H
