//
// Created by Benny Franco Dennis on 13/03/16.
//

#include <iostream>
#include <fstream>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/types.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
#include "StationController.h"

using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::array;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::close_array;


int StationController::create(Connection con) {
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{con.getMongoURI()}};

    std::vector<std::string> headersVector;
    std::vector<std::string> dataLineVector;
    std::vector<std::string>::const_iterator j;
    std::vector<std::string>::const_iterator k;

    std::string headerLine;

    std::ifstream inFile(con.getFileName());

    auto collection = conn[con.getDatabase()][con.getCollectionName()];
    bool isFirstLine=true;

    if (!inFile) {
        std::cerr << "File not found." << std::endl;
        return -1;
    }

    std::string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        if(isFirstLine){
            headerLine = line;
            isFirstLine=false;
        }else {
            dataLineVector.push_back(line);
        }
    }

    inFile.close();

    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    while ((pos = headerLine.find(delimiter)) != std::string::npos) {
        token = headerLine.substr(0, pos);
        token.replace(token.begin(),token.begin()+1,"");
        token.replace(token.end()-1,token.end(),"");
        headerLine.erase(0, pos + delimiter.length());
        headersVector.push_back(token);
    }
    headerLine.replace(headerLine.begin(),headerLine.begin()+1,"");
    headerLine.replace(headerLine.end()-1,headerLine.end(),"");
    headerLine.replace(headerLine.end()-1,headerLine.end(),"");
    headersVector.push_back(headerLine);

    for(j=dataLineVector.begin(); j!=dataLineVector.end(); ++j){
        std::string temp = (*j);
        std::vector<std::string> dataTempVector;
        while ((pos = temp.find(delimiter)) != std::string::npos) {
            token = temp.substr(0, pos);
            temp.erase(0, pos + delimiter.length());
            token.replace(token.begin(),token.begin()+1,"");
            token.replace(token.end()-1,token.end(),"");
            dataTempVector.push_back(token);
        }

        temp.replace(temp.begin(),temp.begin()+1,"");
        temp.replace(temp.end()-1,temp.end(),"");
        temp.replace(temp.end()-1,temp.end(),"");
        dataTempVector.push_back(temp);

        bsoncxx::builder::stream::document document{};

        for(std::size_t i=0;i<dataTempVector.size();++i){
            if(i==0){
                document << "name" << con.getCollectionName() << headersVector[i] << dataTempVector[i];
                document << "sensores" << open_document;
            }else{
                Sensor *sensor = new Sensor(dataTempVector[i],headersVector[i]);
                document << sensor->getName() << sensor->getValue();
            }
        }

        document << close_document;

        collection.insert_one(document.view());
    }
    return 0;
}