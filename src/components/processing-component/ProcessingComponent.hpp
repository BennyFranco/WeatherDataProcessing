//
//  ProcessingComponent.hpp
//  weather-backend-app
//
//  Created by Benny Franco Dennis on 30/01/17.
//
//

#ifndef ProcessingComponent_hpp
#define ProcessingComponent_hpp

#include "../../entities/Station.hpp"
#include "DataProcessingInterface.hpp"

class ProcessingComponent: public DataProcessingInterface {
public:
    ProcessingComponent(){}
    void readStationData();
    
private:
    Station station;
};

#endif /* ProcessingComponent_hpp */
