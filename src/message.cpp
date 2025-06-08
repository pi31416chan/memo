#include "message.h"

using namespace std;
using Message = memo::Message;

// Constructor
Message::Message(string title, string body)
{
    this->title = title;
    this->body = body;

    updateCreated();
    updateLastUpdated();
}

// Private Methods
void Message::updateCreated()
{
    time_t now;
    created = time(&now);
}

void Message::updateLastUpdated()
{
    time_t now;
    lastUpdated = time(&now);
}

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
        {"created", (int)created},
        {"lastUpdated", (int)lastUpdated},
    };

    return j;
}
