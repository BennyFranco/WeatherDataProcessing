//
//  DataProcessingInterface.hpp
//  weather-backend-app
//
//  Created by Benny Franco Dennis on 01/02/17.
//
//

#ifndef DataProcessingInterface_hpp
#define DataProcessingInterface_hpp

#include <iostream>
#include <vector>

#include "../../entities/Station.hpp"

class DataProcessingInterface {
public:
    virtual Station readStationData(std::string stationName)= 0;

    virtual ~DataProcessingInterface() {};
};

#endif /* DataProcessingInterface_h */
