//
// Created by Benny Franco Dennis on 13/03/16.
//

#ifndef WEATHER_BACKEND_APP_MODELS_H
#define WEATHER_BACKEND_APP_MODELS_H


#include <string>

class models {

private:
    std::string mongoURI;
    std::string database;
    std::string collectionName;
    std::string fileName;


public:
    models() { }


    models(const std::string &mongoURI, const std::string &database, const std::string &collectionName,
           const std::string &fileName) : mongoURI(mongoURI), database(database), collectionName(collectionName),
                                          fileName(fileName) { }


    const std::string &getMongoURI() const {
        return mongoURI;
    }

    void setMongoURI(const std::string &mongoURI) {
        models::mongoURI = mongoURI;
    }

    const std::string &getDatabase() const {
        return database;
    }

    void setDatabase(const std::string &database) {
        models::database = database;
    }

    const std::string &getCollectionName() const {
        return collectionName;
    }

    void setCollectionName(const std::string &collectionName) {
        models::collectionName = collectionName;
    }

    const std::string &getFileName() const {
        return fileName;
    }

    void setFileName(const std::string &fileName) {
        models::fileName = fileName;
    }
};


#endif //WEATHER_BACKEND_APP_MODELS_H
