cmake_minimum_required(VERSION 3.3)
project(WeatherDataProcessing)

find_package(PkgConfig REQUIRED)
PKG_SEARCH_MODULE(MONGO libmongocxx)
include_directories(${MONGO_INCLUDE_DIRS})
include_directories(${MONGO_LIBRARY_DIRS})

set(MONGO_USE_STATIC_LIBS        ON)
set(MONGO_USE_MULTITHREADED      ON)
set(MONGO_USE_STATIC_RUNTIME    OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/cmake-extensions/ )

link_directories(${MONGO_LIBRARY_DIRS})

set(SOURCE_FILES main.cpp )
add_executable(WeatherDataProcessing ${SOURCE_FILES})
target_link_libraries(WeatherDataProcessing ${MONGO_LIBRARIES})