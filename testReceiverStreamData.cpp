#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Receiver/ReceiverStreamBmsData.h"

TEST_CASE("Check whether sensor inputs are read from sender file") {
  float Temperature[300];
  float Soc[300];  
  REQUIRE(receiveBmsDataFromConsole(Temperature,Soc) == 1);
  
}

TEST_CASE("Process sensor input and output in CSV format") {
  REQUIRE(processReceivedBmsStreamData() == 1);
}
