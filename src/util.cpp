#include "util.h"

namespace util = memo::util;

void util::updateTimeStampNow(time_t *timestamp)
{
    time_t now;
    *timestamp = time(&now);
}
