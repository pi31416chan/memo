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

        void updateLastUpdated();
        void updateJsonData();

    public:
        Memo()
        {
            updateLastUpdated();
        }

        time_t lastUpdated;

        void displayLastUpdated();
    };
}
