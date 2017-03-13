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

    std::string headers = readFileHeader(this->fileURL);
    std::string data = readFileData(this->fileURL);

    std::vector<std::string> split_headers = Shared::split(headers, ",");

    for (int i = 0; i < split_headers.size(); i++) {
        std::cout<<split_headers[i]<<std::endl;
    }

    return std::vector<Station>();
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

    // std::cout << file_contents << std::endl;

    return file_contents;
}

std::string ProcessingComponent::readFileHeader(std::string fileName) {
    std::ifstream file(fileName);
    std::string str;
    std::string file_headers;

    std::getline(file, str);

    file_headers += str;
    file_headers.push_back('\n');


    // std::cout << file_headers << std::endl;

    return file_headers;
}

