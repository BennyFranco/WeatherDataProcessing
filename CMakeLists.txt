cmake_minimum_required(VERSION 3.3)
project(weather-backend-app)

set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH /Users/Benny/qt/5.5/clang_64/lib/cmake)

find_package(PkgConfig REQUIRED)

PKG_SEARCH_MODULE(MONGO libmongocxx)
find_package(Qt5Widgets)

include_directories(${MONGO_INCLUDE_DIRS} ${MONGO_LIBRARY_DIRS})

set(MONGO_USE_STATIC_LIBS        ON)
set(MONGO_USE_MULTITHREADED      ON)
set(MONGO_USE_STATIC_RUNTIME    OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/cmake-extensions/ )

link_directories(${MONGO_LIBRARY_DIRS})

set(SOURCE_FILES main.cpp TextFileProcessor.cpp TextFileProcessor.h mainwindow.cpp model/Sensor.cpp model/Sensor.h model/Station.cpp model/Station.h controller/StationController.cpp controller/StationController.cpp controller/StationController.h)
add_executable(weather-backend-app ${SOURCE_FILES})
target_link_libraries(weather-backend-app ${MONGO_LIBRARIES} Qt5::Widgets)