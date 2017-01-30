//
//  Sensor.hpp
//  weather-backend-app
//
//  Created by Benny Franco Dennis on 30/01/17.
//
//

#ifndef Sensor_hpp
#define Sensor_hpp

#include <string>

class Sensor {
    
private:
    std::string _id;
    std::string _name;
    std::string _value;
    
public:
    Sensor() { }
    
    const std::string &getId() const {
        return _id;
    }
    
    void setId(std::string id){
        Sensor::_id = id;
    }
    
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
};


#endif /* Sensor_hpp */
