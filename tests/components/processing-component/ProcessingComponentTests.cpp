//
// Created by Benny Franco Dennis on 12/03/17.
//

#include <iostream>

#include "ProcessingComponentTests.h"
#include "../../../src/entities/Station.hpp"
#include "../../../src/components/processing-component/ProcessingComponent.hpp"


CPPUNIT_TEST_SUITE_REGISTRATION(ProcessingComponentTests);

void ProcessingComponentTests::read_station_data() {

    std::string fileURL = "./test-data/Jazmin/20150201.txt";

    DataProcessingInterface *dataProcessingInterface = new ProcessingComponent(fileURL);
    std::vector<Station> stations = dataProcessingInterface->readStationData("Jazmin");

    unsigned long expectedSize = 0;
    // CPPUNIT_ASSERT_GREATER(expectedSize, stations.size());
}