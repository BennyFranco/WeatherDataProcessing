//
// Created by Benny Franco Dennis on 12/03/17.
//

#ifndef WEATHER_BACKEND_APP_SHARED_H
#define WEATHER_BACKEND_APP_SHARED_H

#include <string>
#include <vector>

class Shared {
public:
    static std::vector<std::string> split(std::string str, std::string sep);
};


#endif //WEATHER_BACKEND_APP_SHARED_H
