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

    ProcessingComponent(const std::string &fileURL) : m_file_url(fileURL) {}


    const Station &getStation() const {
        return m_station;
    }

    void setStation(const Station &station) {
        ProcessingComponent::m_station = station;
    }

    const std::string &getFileURL() const {
        return m_file_url;
    }

    void setFileURL(const std::string &fileURL) {
        ProcessingComponent::m_file_url = fileURL;
    }

    Station readStationData(std::string stationName) override;

private:
    Station m_station;
    std::string m_file_url;

    std::string readFileData(std::string fileName);

    std::string readFileHeader(std::string fileName);

    std::vector<std::string> processHeaders(std::string fileURL);

    std::vector<std::string> processData(std::string fileURL);

    void createCopyOfDataFile();
};

#endif /* ProcessingComponent_hpp */
