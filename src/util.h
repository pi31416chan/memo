#ifndef UTIL_H
#define UTIL_H

#include <ctime>
#include <string>
#include <vector>

using namespace std;

namespace memo::util
{
    string strip(string str);
    void updateTimeStampNow(time_t *timestamp);
}

#endif // UTIL_H
