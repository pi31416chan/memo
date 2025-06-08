#include "message.h"

using namespace std;
using Message = memo::Message;

// Public Methods
void Message::displayLastUpdated()
{
    cout << ctime(&lastUpdated);
}

json Message::toJson()
{
    json j = {
        {"title", title},
        {"body", body},
        {"lastUpdated", (int)lastUpdated},
    };

    return j;
}
