//
// Created by Benny Franco Dennis on 13/03/16.
//

#ifndef WEATHER_BACKEND_APP_CONNECTION_H
#define WEATHER_BACKEND_APP_CONNECTION_H

#include <string>

class Connection {

private:
    std::string _mongoURI;
    std::string _database;
    std::string _collectionName;
    std::string _fileName;


public:
    Connection() { }
    Connection(const std::string &mongoURI, const std::string &database, const std::string &collectionName,
               const std::string &fileName) : _mongoURI(mongoURI), _database(database), _collectionName(collectionName),
                                              _fileName(fileName) { }

    const std::string &getMongoURI() const {
        return _mongoURI;
    }

    void setMongoURI(const std::string &mongoURI) {
        Connection::_mongoURI = mongoURI;
    }

    const std::string &getDatabase() const {
        return _database;
    }

    void setDatabase(const std::string &database) {
        Connection::_database = database;
    }

    const std::string &getCollectionName() const {
        return _collectionName;
    }

    void setCollectionName(const std::string &collectionName) {
        Connection::_collectionName = collectionName;
    }

    const std::string &getFileName() const {
        return _fileName;
    }

    void setFileName(const std::string &fileName) {
        Connection::_fileName = fileName;
    }
};


#endif //WEATHER_BACKEND_APP_CONNECTION_H
