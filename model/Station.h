//
// Created by Benny Franco Dennis on 13/03/16.
//

#ifndef WEATHER_BACKEND_APP_STATION_H
#define WEATHER_BACKEND_APP_STATION_H

#include <string>
#include <vector>
#include "Sensor.h"

class Station {
private:
    std::string id;
    std::string name;
    std::string dateTime;
    std::vector<Sensor> sensores;

public:
    Station() { }

    Station(const std::string &id, const std::string &name, const std::string &dateTime) : id(id), name(name),
                                                                                           dateTime(dateTime) { }


    Station(const std::string &id, const std::string &name, const std::string &dateTime,
            const std::vector<Sensor> &sensores) : id(id), name(name), dateTime(dateTime), sensores(sensores) { }


    const std::string &getId() const {
        return id;
    }

    void setId(const std::string &id) {
        Station::id = id;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Station::name = name;
    }

    const std::string &getDateTime() const {
        return dateTime;
    }

    void setDateTime(const std::string &dateTime) {
        Station::dateTime = dateTime;
    }

    const std::vector<Sensor> &getSensores() const {
        return sensores;
    }

    void setSensores(const std::vector<Sensor> &sensores) {
        Station::sensores = sensores;
    }
};


#endif //WEATHER_BACKEND_APP_STATION_H
