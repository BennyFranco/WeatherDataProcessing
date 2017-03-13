//
// Created by Benny Franco Dennis on 12/03/17.
//


#ifndef WEATHER_BACKEND_APP_PROCESSINGCOMPONENTTESTS_H
#define WEATHER_BACKEND_APP_PROCESSINGCOMPONENTTESTS_H

#include <cppunit/extensions/HelperMacros.h>


class ProcessingComponentTests : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( ProcessingComponentTests );
    CPPUNIT_TEST( read_station_data );
    CPPUNIT_TEST_SUITE_END();

protected:
    void read_station_data();

};


#endif //WEATHER_BACKEND_APP_PROCESSINGCOMPONENTTESTS_H
