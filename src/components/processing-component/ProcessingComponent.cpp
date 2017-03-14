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

std::vector<Station> ProcessingComponent::readStationData(std::string stationName) {
    std::cout << "Reading station: " + stationName << std::endl;


    std::vector<std::string> headers = processHeaders(this->m_file_url);
    std::vector<std::string> data = processData(this->m_file_url);

    // createCopyOfDataFile();

    std::vector<Station> stations;

    for (auto &lineData : data) {
        std::vector<std::string> line = processLine(lineData);

        std::vector<Sensor> sensors;
        Station *station = new Station();

        station->setName(stationName);
        station->setDateTime(line[0]);

        for (int j = 1; j < headers.size(); j++) {

            Sensor *sensor = new Sensor();
            sensor->setName(headers[j]);
            sensor->setValue(line[j]);

            sensors.emplace_back(*sensor);
        }

        station->setSensors(sensors);
        stations.emplace_back(*station);
    }

    // cleanDataFile();

    return stations;
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

    return Shared::split(data, "\n");
}

std::vector<std::string> ProcessingComponent::processLine(std::string line) {

    std::vector<std::string> data = Shared::split(line, ",");

    return data;
}

void ProcessingComponent::createCopyOfDataFile() {
    time_t now = time(0);
    tm *localTime = localtime(&now);
    std::string timeToConcat = std::to_string(1900 + localTime->tm_year) +
                               std::to_string(1 + localTime->tm_mon) +
                               std::to_string(localTime->tm_mday) + "T" +
                               std::to_string(localTime->tm_hour) +
                               std::to_string(localTime->tm_min);

    std::ifstream inFile(this->m_file_url);
    std::ofstream outFile(this->m_file_url + ".bak" + timeToConcat);

    outFile << inFile.rdbuf();
}

void ProcessingComponent::cleanDataFile() {
    std::ofstream ofs;
    ofs.open(this->m_file_url, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

