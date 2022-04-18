#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Receiver/ReceiverStreamBmsData.h"



TEST_CASE("Process sensor input and output in CSV format") {
  REQUIRE(processReceivedBmsStreamData() == 1);
}

TEST_CASE("Check whether sensor inputs are read from sender file") {
  float InArray = {2,4,5,6,7,8,9,10,12,3,4,5,6,7,8,7}; 
  REQUIRE((findMovingAverageFromBmsData(InArray,16)) == 6);
  
}
