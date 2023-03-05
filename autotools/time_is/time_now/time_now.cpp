// code to get current time
#include "config.h"

#include <ctime>
#include "time_now.h"

const std::string time_is()
{
    const int size = 10;
    std::time_t t;
    std::time(&t);
    tm* tmp;
    tmp = std::localtime(&t);

    char cstr_time[size];
    std::strftime(cstr_time, sizeof(cstr_time), "%T", tmp);

    return std::string(cstr_time);
}
