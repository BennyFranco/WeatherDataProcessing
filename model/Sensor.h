//
// Created by Benny Franco Dennis on 13/03/16.
//

#ifndef WEATHER_BACKEND_APP_SENSOR_H
#define WEATHER_BACKEND_APP_SENSOR_H

#include <string>

class Sensor {

private:
    std::string _name;
    std::string _value;
    std::string _units;

public:
    Sensor() { }
    Sensor(const std::string &value, const std::string &name) : _value(value), _name(name) { }
    Sensor(const std::string &name, const std::string &vale, const std::string &units) : _name(name), _value(vale),
                                                                                         _units(units) { }

    const std::string &getName() const {
        return _name;
    }

    void setName(const std::string &name) {
        Sensor::_name = name;
    }

    const std::string &getValue() const {
        return _value;
    }

    void setValue(const std::string &value) {
        Sensor::_value = value;
    }

    const std::string &getUnits() const {
        return _units;
    }

    void setUnits(const std::string &units) {
        Sensor::_units = units;
    }
};


#endif //WEATHER_BACKEND_APP_SENSOR_H
