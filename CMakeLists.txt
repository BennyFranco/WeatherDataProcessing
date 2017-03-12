cmake_minimum_required(VERSION 3.6)
project(weather_backend_app)

set(CMAKE_CXX_STANDARD 11)

include(conanbuildinfo.cmake)
conan_basic_setup()

#TEST FILES

set(TEST_FILES  tests/components/processing-component/ProcessingComponentTests.h
                tests/components/processing-component/ProcessingComponentTests.cpp
                tests/main-test.cpp)

add_executable(weather_processor_tests ${TEST_FILES})
target_link_libraries(weather_processor_tests ${CONAN_LIBS})

#SOURCE FILES
set(SOURCE_FILES src/main.cpp )
add_executable(weather_processor ${SOURCE_FILES})