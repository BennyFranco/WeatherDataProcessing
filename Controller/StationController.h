//
// Created by Benny Franco Dennis on 13/03/16.
//

#ifndef WEATHER_BACKEND_APP_STATIONCONTROLLER_H
#define WEATHER_BACKEND_APP_STATIONCONTROLLER_H


#include "../model/Station.h"
#include "../config/Connection.h"

class StationController {

public:
    StationController() { }
    int create(Connection con);
    void update(Station station);
    void destroy(Station station);
    Station find(Station station);
    std::vector<Station> findAll();
};


#endif //WEATHER_BACKEND_APP_STATIONCONTROLLER_H
