//
// Created by Benny Franco Dennis on 14/03/16.
//

#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
#include "Configuration.h"

using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::array;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::close_array;

int Configuration::create(Connection connection) {
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{connection.getMongoURI()}};

    auto collection = conn[connection.getDatabase()]["Configurations"];
    bsoncxx::builder::stream::document document{};

    document << "name" << connection.getCollectionName() << "fileURI" << connection.getFileName();
    collection.insert_one(document.view());

    return 0;
}