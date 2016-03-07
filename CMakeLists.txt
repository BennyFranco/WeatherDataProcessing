cmake_minimum_required(VERSION 3.3)
project(WeatherDataProcessing)

find_package(PkgConfig REQUIRED)

PKG_SEARCH_MODULE(MONGO libmongocxx)
PKG_SEARCH_MODULE(GTK3 gtk+-3.0)

include_directories(${MONGO_INCLUDE_DIRS} ${MONGO_LIBRARY_DIRS} ${GTK3_INCLUDE_DIRS} ${GTK3_LIBRARY_DIRS})

set(MONGO_USE_STATIC_LIBS        ON)
set(MONGO_USE_MULTITHREADED      ON)
set(MONGO_USE_STATIC_RUNTIME    OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/cmake-extensions/ )

link_directories(${MONGO_LIBRARY_DIRS} ${GTK3_LIBRARY_DIRS})

set(SOURCE_FILES main.cpp TextFileProcessor.cpp TextFileProcessor.h)
add_executable(WeatherDataProcessing ${SOURCE_FILES})
target_link_libraries(WeatherDataProcessing ${MONGO_LIBRARIES} ${GTK3_LIBRARIES})