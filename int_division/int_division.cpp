// An example of distance and iterator
#include <iostream>
#include <string>
#include <ctime>

int main() {
    std::time_t current_time;
    std::time(&current_time);
    tm* current_tm;
    current_tm = std::localtime(&current_time);

    char min_cstr[5];
    std::strftime(min_cstr, 5, "%M", current_tm);

    const int quater = std::stoi(std::string(min_cstr))/15;
    std::cout << std::to_string(quater) << std::endl;
}
