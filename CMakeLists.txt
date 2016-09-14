cmake_minimum_required(VERSION 3.3)
project(weather-backend-app)

set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH /Users/bennyfranco/qt/5.7/clang_64/lib/cmake)

find_package(PkgConfig REQUIRED)
PKG_SEARCH_MODULE(MONGO libmongocxx)
find_package(Qt5Widgets)

include_directories(${MONGO_INCLUDE_DIRS} ${MONGO_LIBRARY_DIRS} /usr/local/include/mongocxx/v_noabi/mongocxx /usr/local/include/bsoncxx/v_noabi/bsoncxx)

set(MONGO_USE_STATIC_LIBS        ON)
set(MONGO_USE_MULTITHREADED      ON)
set(MONGO_USE_STATIC_RUNTIME    OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/cmake-extensions/ )

link_directories(${MONGO_LIBRARY_DIRS})

set(SOURCE_FILES main.cpp view/CreateStationWindow.cpp model/Sensor.cpp model/Sensor.h model/Station.cpp model/Station.h controller/StationController.cpp controller/StationController.cpp controller/StationController.h config/connection.cpp config/connection.h config/Connection.cpp config/Connection.h config/Configuration.cpp config/Configuration.h view/mainwindow.cpp view/mainwindow.h)
add_executable(weather-backend-app ${SOURCE_FILES})
target_link_libraries(weather-backend-app ${MONGO_LIBRARIES} Qt5::Widgets)