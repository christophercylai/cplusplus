// An example of distance and iterator
#include <iostream>
#include <vector>

int main() {
    std::vector<char> ch = {'z', 'b', 'c'};
    std::vector<char>::iterator iter;
    for (auto i = ch.begin() ; i != ch.end() ; i++) {
        if (*i == 'z') {
            iter = i;
            continue;
        }
    }
    ch.at(std::distance(ch.begin(), iter)) = 'a';
    std::cout << ch[0] << std::endl;
}
