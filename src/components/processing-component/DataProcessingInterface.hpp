//
//  DataProcessingInterface.hpp
//  weather-backend-app
//
//  Created by Benny Franco Dennis on 01/02/17.
//
//

#ifndef DataProcessingInterface_hpp
#define DataProcessingInterface_hpp

class DataProcessingInterface
{
public:
    
    virtual ~DataProcessingInterface() {}
    
    virtual void readStationData();
};

#endif /* DataProcessingInterface_h */
