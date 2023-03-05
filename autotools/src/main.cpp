// main code to be used as an GNU autotools example
#include "config.h"

#include <iostream>
#include "time_now/time_now.h"

int main()
{
    const std::string time = time_now();
    std::cout << "Hello World! "
        << "The current time is "
        << time << "."
        << std::endl;
}
