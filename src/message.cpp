#include "message.h"

using Message = memo::Message;

// Constructor
Message::Message(string title)
{
    Message(title, "");
}

Message::Message(string title, string body)
{
    this->title = title;
    this->body = body;

    util::updateTimeStampNow(&this->created);
    util::updateTimeStampNow(&this->lastUpdated);
}

Message::Message(json messageJson)
{

    this->title = messageJson["title"];
    this->body = messageJson["body"];
    this->created = messageJson["created"];
    this->lastUpdated = messageJson["lastUpdated"];
}

// Private Methods

// Public Methods
string Message::strCreated()
{
    string t = ctime(&created);

    return util::strip(t);
}

string Message::strLastUpdated()
{
    string t = ctime(&lastUpdated);

    return util::strip(t);
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
    cout << "Created: " << strCreated() << endl;
    cout << "Updated: " << strLastUpdated() << endl;
    cout << "Body:" << endl;
    if (body.empty())
    {
        cout << "    " << "NA" << endl;
    }
    else
    {
        string line;
        istringstream iss(body);

        do
        {
            getline(iss, line);
            if (!iss.eof())
                cout << "    " << line << endl;
        } while (!iss.eof() && !line.empty());
    }
}
