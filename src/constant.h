#ifndef CONSTANT_H
#define CONSTANT_H

#include <cstdlib>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;
using path = fs::path;

const string LOCAL_DIRNAME = ".local";
const string MEMO_HOME_NAME = "memo";
const string MEMO_DATAFILE_NAME = "/data.json";
const fs::path USER_HOME = string(getenv("HOME"));
const fs::path MEMO_HOME = USER_HOME / LOCAL_DIRNAME / MEMO_HOME_NAME;
const fs::path MEMO_DATAFILE = MEMO_HOME / MEMO_DATAFILE_NAME;

#endif // CONSTANT_H
