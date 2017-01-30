//
//  Station.hpp
//  weather-backend-app
//
//  Created by Benny Franco Dennis on 30/01/17.
//
//

#ifndef Station_hpp
#define Station_hpp

#include <vector>
#include "Sensor.hpp"

class Station {
private:
    std::string _id;
    std::string _name;
    std::string _dateTime;
    std::string _fileName;
    std::vector<Sensor> _sensores;
    
public:
    Station() { }
    
    Station(const std::string &id, const std::string &name, const std::string &dateTime) : _id(id), _name(name),
    _dateTime(dateTime) { }
    Station(const std::string &id, const std::string &name, const std::string &dateTime,
            const std::vector<Sensor> &sensores) : _id(id), _name(name), _dateTime(dateTime), _sensores(sensores) { }
    
    Station(const std::string &name, const std::string &fileName) : _name(name), _fileName(fileName) { }
    Station(const std::string &name, const std::string &fileName, const std::vector<Sensor> &sensores) : _name(name),
    _fileName(
              fileName),
    _sensores(
              sensores) { }
    const std::string &getId() const {
        return _id;
    }
    
    void setId(const std::string &id) {
        Station::_id = id;
    }
    
    const std::string &getName() const {
        return _name;
    }
    
    void setName(const std::string &name) {
        Station::_name = name;
    }
    
    const std::string &getDateTime() const {
        return _dateTime;
    }
    
    void setDateTime(const std::string &dateTime) {
        Station::_dateTime = dateTime;
    }
    
    const std::vector<Sensor> &getSensores() const {
        return _sensores;
    }
    
    void setSensores(const std::vector<Sensor> &sensores) {
        Station::_sensores = sensores;
    }
    
    const std::string &getFileName() const {
        return _fileName;
    }
    
    void setFileName(const std::string &fileName) {
        Station::_fileName = fileName;
    }
};

#endif /* Station_hpp */
