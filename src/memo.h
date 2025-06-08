#include <ctime>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

namespace memo
{
    class Memo
    {
    private:
        json _memoJson;
        time_t _lastUpdated;

        void updateLastUpdated();
        void updateJsonData();

    public:
        Memo()
        {
            updateLastUpdated();
        }

        time_t lastUpdated();

        void displayLastUpdated();
    };
}
