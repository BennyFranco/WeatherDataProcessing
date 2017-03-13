#include <iostream>

#include "components/processing-component/DataProcessingInterface.hpp"
#include "components/processing-component/ProcessingComponent.hpp"

int main(int argc, char *argv[]) {
    clock_t tStart = clock();

    std::string fileURL = "../../test-data/Jazmin/20150201.txt";

    DataProcessingInterface *dataProcessingInterface = new ProcessingComponent(fileURL);
    std::vector<Station> station = dataProcessingInterface->readStationData("Jazmin");

    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}