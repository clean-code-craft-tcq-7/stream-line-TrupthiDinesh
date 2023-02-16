#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "Receiver.h"
#include "Sensor_Data_sender.h"

TEST_CASE("Tests to check whether sensor data is read from console and also to check whether correct Max, Min and SMA values of sensor parameters are printed on console") 
{
  float Temperature_value[readings_count] = {0};
  float SOC_value[readings_count] = {0};
  float observedMaxValue, observedMinValue, observedSMAValue, expectedMaxValue, expectedMinValue, expectedSMAValue;
  receiveAndProcessSensorData(&Temperature_value[0],&SOC_value[0]);
  float expectedoutput[2][2] = {{11,74}, {29,74}};
  for(int i=0;i<2;i++)
  {
    REQUIRE(Temperature_value[i] == expectedoutput[i][0]);
    REQUIRE(SOC_value[i] == expectedoutput[i][1]);
  }
  //To check Max, Min and SMA values of Temperature
  expectedMaxValue = 45;
  expectedMinValue = 0;
  expectedSMAValue = 21.8;
  observedMaxValue = fetchMaxValue(&Temperature_value[0]);
  observedMinValue = fetchMinValue(&Temperature_value[0]);
  observedSMAValue = calculateMovingAverage(&Temperature_value[0]);
  REQUIRE(observedMaxValue == expectedMaxValue);
  REQUIRE(observedMinValue == expectedMinValue);
  REQUIRE(observedSMAValue == expectedSMAValue);
  
  //To check print to console function
  REQUIRE(printReceivedDataToConsole(&Temperature_value[0],45,0,21.8) == 1);
          
  //To check Max, Min and SMA values of SOC
  expectedMaxValue = 80;
  expectedMinValue = 20;
  expectedSMAValue = 58.2;
  observedMaxValue = fetchMaxValue(&SOC_value[0]);
  observedMinValue = fetchMinValue(&SOC_value[0]);
  observedSMAValue = calculateMovingAverage(&SOC_value[0]);
  REQUIRE(observedMaxValue == expectedMaxValue);
  REQUIRE(observedMinValue == expectedMinValue);
  REQUIRE(observedSMAValue == expectedSMAValue);
  
  //To check print to console function
  REQUIRE(printReceivedDataToConsole(&SOC_value[0],80,20,58.2) == 1);
}
