#include "message.h"

using Message = memo::Message;

// Constructor
Message::Message(string title, string body)
{
    this->title = title;
    this->body = body;

    util::updateTimeStampNow(&this->created);
    util::updateTimeStampNow(&this->lastUpdated);
}

// Private Methods

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

void Message::show()
{
    cout << "Title: " << title << endl;
    cout << "Body:" << endl;
    cout << "    " << body << endl;
}
