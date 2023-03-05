// This is an example on how to use regex
#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string env_name = "";
    std::cout << "Please provide the name of the environment variable:" << std::endl;
    std::cin >> env_name;

    // use regex to check the environment variable name
    const std::regex name_check("[A-Za-z][A-Za-z0-9]*");
    if (!std::regex_match(env_name, name_check)) {
        std::cerr
            << "Environment variable name must not contain special "
                "characters and must not start with a number."
            << std::endl;
        return 1;
    }

    // get environment variable
    const char* const var_value = std::getenv(env_name.c_str());
    if (!var_value) {
        std::cerr << "Environment variable '" + env_name + "' doesn't exist" << std::endl;
        return 1;
    }
    std::cout << "The value of environment variable '" + env_name + "' is '" + var_value + "'" << std::endl;
}
