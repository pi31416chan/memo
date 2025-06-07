#include <ctime>

using namespace std;

namespace memo
{
    class Memo
    {
    private:
        time_t _lastUpdated;

    public:
        Memo()
        {
            updateLastUpdated();
        }

        time_t lastUpdated();

        void updateLastUpdated();
        void displayLastUpdated();
    };
}
