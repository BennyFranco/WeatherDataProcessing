//
// Created by Benny Franco Dennis on 12/03/17.
//

#include "Shared.h"

std::vector<std::string> Shared::split(std::string str, std::string sep) {
    char *cstr = const_cast<char *>(str.c_str());
    char *current;
    std::vector<std::string> arr;
    current = strtok(cstr, sep.c_str());
    while (current != NULL) {
        arr.push_back((std::basic_string<char, std::char_traits<char>, std::allocator<char>> &&) current);
        current = strtok(NULL, sep.c_str());
    }
    return arr;
}
