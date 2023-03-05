// find out the quater of the hour
#include <iostream>
#include <string>
#include <ctime>
#include <map>

int main() {
    std::time_t current_time;
    std::time(&current_time);
    tm* current_tm;
    current_tm = std::localtime(&current_time);

    char min_cstr[5];
    std::strftime(min_cstr, 5, "%M", current_tm);

    const int quater = std::stoi(std::string(min_cstr))/15 + 1;

    const std::map<int, std::string> suffix = {
        {1, "st"}, {2, "nd"}, {3, "rd"}, {4, "th"}
    };

    std::cout << "This is the " 
        << std::to_string(quater) << suffix.find(quater)->second
        << " quater of the hour" << std::endl;
}
