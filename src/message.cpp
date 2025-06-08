#include "message.h"

using namespace std;
using Message = memo::Message;

// Public Methods
void Message::displayLastUpdated()
{
    cout << ctime(&lastUpdated);
}
