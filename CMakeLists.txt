cmake_minimum_required(VERSION 3.6)
project(weather_backend_app)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SOURCE_FILES src/main.cpp )
add_executable(weather_processor ${CONAN_LIBS} ${SOURCE_FILES})