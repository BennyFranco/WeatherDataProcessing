//
//  ProcessingComponent.cpp
//  weather-backend-app
//
//  Created by Benny Franco Dennis on 30/01/17.
//
//

#include "ProcessingComponent.hpp"
#include "../../Shared/Shared.h"

#include <fstream>
#include <ctime>

Station ProcessingComponent::readStationData(std::string stationName) {
    std::cout << "Reading station: " + stationName << std::endl;


    std::vector<std::string> headers = processHeaders(this->m_file_url);
    std::vector<std::string> data = processData(this->m_file_url);

    createCopyOfDataFile();

    std::vector<Sensor> sensors;

    for (int i = 1; i < headers.size(); i++) {

        Sensor *sensor = new Sensor();
        sensor->setName(headers[i]);
        sensor->setValue(data[i]);

        sensors.emplace_back(*sensor);
    }

    Station *station = new Station();
    station->setName(stationName);
    station->setDateTime(data[0]);
    station->setSensors(sensors);

    return *station;
}

std::string ProcessingComponent::readFileData(std::string fileName) {

    std::ifstream file(fileName);
    std::string str;
    std::string file_contents;
    int i = 0;

    while (std::getline(file, str)) {
        if (i != 0) {
            file_contents += str;
            file_contents.push_back('\n');
        } else {
            i++;
        }
    }

    return file_contents;
}

std::string ProcessingComponent::readFileHeader(std::string fileName) {
    std::ifstream file(fileName);
    std::string str;
    std::string file_headers;

    std::getline(file, str);

    file_headers += str;
    file_headers.push_back('\n');

    return file_headers;
}

std::vector<std::string> ProcessingComponent::processHeaders(std::string fileURL) {

    std::string headers = readFileHeader(fileURL);
    std::vector<std::string> split_headers = Shared::split(headers, ",");

    split_headers[0] += split_headers[1];
    std::replace(split_headers[0].begin(), split_headers[0].end(), '"', ' ');
    split_headers[0].erase(std::remove_if(split_headers[0].begin(), split_headers[0].end(), isspace),
                           split_headers[0].end());
    split_headers[0] = "\"" + split_headers[0] + "\"";

    split_headers.erase(split_headers.begin() + 1);


    return split_headers;
}

std::vector<std::string> ProcessingComponent::processData(std::string fileURL) {
    std::string data = readFileData(fileURL);

    return Shared::split(data, ",");
}

void ProcessingComponent::createCopyOfDataFile() {
    time_t now = time(0);
    tm *localTime = localtime(&now);
    std::string timeToConcat = std::to_string(1900 + localTime->tm_year) + "-" +
                               std::to_string(1 + localTime->tm_mon) + "-" +
                               std::to_string(localTime->tm_mday);

    std::ifstream inFile(this->m_file_url);
    std::ofstream outFile(this->m_file_url + ".bak" + timeToConcat);

    outFile << inFile.rdbuf();
}
