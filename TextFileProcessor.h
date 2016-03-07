//
// Created by Benny Franco Dennis on 06/03/16.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#ifndef WEATHERDATAPROCESSING_TEXTFILEPROCESSOR_H
#define WEATHERDATAPROCESSING_TEXTFILEPROCESSOR_H

using namespace std;

class TextFileProcessor {
    string mongoURI;
    string database;
    string collectionName;
    string fileName;

public:
    TextFileProcessor() { }

    TextFileProcessor(const string &mongoURI, const string &database, const string &collectionName,
                      const string &fileName) : mongoURI(mongoURI), database(database), collectionName(collectionName),
                                                fileName(fileName) { }

    int transformTextFile();

    const string &getMongoURI() const {
        return mongoURI;
    }

    void setMongoURI(const string &mongoURI) {
        TextFileProcessor::mongoURI = mongoURI;
    }

    const string &getDatabase() const {
        return database;
    }

    void setDatabase(const string &database) {
        TextFileProcessor::database = database;
    }

    const string &getCollectionName() const {
        return collectionName;
    }

    void setCollectionName(const string &collectionName) {
        TextFileProcessor::collectionName = collectionName;
    }

    const string &getFileName() const {
        return fileName;
    }

    void setFileName(const string &fileName) {
        TextFileProcessor::fileName = fileName;
    }
};


#endif //WEATHERDATAPROCESSING_TEXTFILEPROCESSOR_H
