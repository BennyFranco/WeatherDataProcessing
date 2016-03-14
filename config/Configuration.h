//
// Created by Benny Franco Dennis on 14/03/16.
//

#ifndef WEATHER_BACKEND_APP_CONFIGURATION_H
#define WEATHER_BACKEND_APP_CONFIGURATION_H


#include "Connection.h"
#include "../model/Station.h"

class Configuration {


public:
    Configuration() { }

    int create(Connection connection);
};


#endif //WEATHER_BACKEND_APP_CONFIGURATION_H
