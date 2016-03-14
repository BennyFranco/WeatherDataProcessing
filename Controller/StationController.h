//
// Created by Benny Franco Dennis on 13/03/16.
//

#ifndef WEATHER_BACKEND_APP_STATIONCONTROLLER_H
#define WEATHER_BACKEND_APP_STATIONCONTROLLER_H


#include "../model/Station.h"

class StationController {

public:
    StationController() { }
    void create(Station station);
    void update(Station station);
    void destroy(Station station);
    Station find(Station station);
    std::vector<Station> findAll();
};


#endif //WEATHER_BACKEND_APP_STATIONCONTROLLER_H
