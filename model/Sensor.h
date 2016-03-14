//
// Created by Benny Franco Dennis on 13/03/16.
//

#ifndef WEATHER_BACKEND_APP_SENSOR_H
#define WEATHER_BACKEND_APP_SENSOR_H

#include <string>

class Sensor {

private:
    std::string name;
    std::string value;
    std::string units;

public:
    Sensor() { }
    Sensor(const std::string &value, const std::string &name) : value(value), name(name) { }
    Sensor(const std::string &name, const std::string &vale, const std::string &units) : name(name), value(vale),
                                                                                         units(units) { }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Sensor::name = name;
    }

    const std::string &getValue() const {
        return value;
    }

    void setValue(const std::string &value) {
        Sensor::value = value;
    }

    const std::string &getUnits() const {
        return units;
    }

    void setUnits(const std::string &units) {
        Sensor::units = units;
    }
};


#endif //WEATHER_BACKEND_APP_SENSOR_H
