//
// Created by Benny Franco Dennis on 13/03/16.
//

#ifndef WEATHER_BACKEND_APP_CONNECTION_H
#define WEATHER_BACKEND_APP_CONNECTION_H

#include <string>

class Connection {

private:
    std::string mongoURI;
    std::string database;
    std::string collectionName;
    std::string fileName;


public:
    Connection() { }
    Connection(const std::string &mongoURI, const std::string &database, const std::string &collectionName,
               const std::string &fileName) : mongoURI(mongoURI), database(database), collectionName(collectionName),
                                              fileName(fileName) { }

    const std::string &getMongoURI() const {
        return mongoURI;
    }

    void setMongoURI(const std::string &mongoURI) {
        Connection::mongoURI = mongoURI;
    }

    const std::string &getDatabase() const {
        return database;
    }

    void setDatabase(const std::string &database) {
        Connection::database = database;
    }

    const std::string &getCollectionName() const {
        return collectionName;
    }

    void setCollectionName(const std::string &collectionName) {
        Connection::collectionName = collectionName;
    }

    const std::string &getFileName() const {
        return fileName;
    }

    void setFileName(const std::string &fileName) {
        Connection::fileName = fileName;
    }
};


#endif //WEATHER_BACKEND_APP_CONNECTION_H
