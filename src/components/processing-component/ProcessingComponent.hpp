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

class ProcessingComponent : public DataProcessingInterface {

public:
    ProcessingComponent() {}

    ProcessingComponent(const std::string &fileURL) : fileURL(fileURL) {}


    const Station &getStation() const {
        return station;
    }

    void setStation(const Station &station) {
        ProcessingComponent::station = station;
    }

    const std::string &getFileURL() const {
        return fileURL;
    }

    void setFileURL(const std::string &fileURL) {
        ProcessingComponent::fileURL = fileURL;
    }

    std::vector<Station> readStationData(std::string stationName) override;

private:
    Station station;
    std::string fileURL;

    std::string readFileData(std::string fileName);
    std::string readFileHeader(std::string fileName);
};

#endif /* ProcessingComponent_hpp */
