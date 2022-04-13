#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Receiver/ReceiverStreamBmsData.h"

TEST_CASE("Check whether sensor inputs are read from sender file") {
  REQUIRE(receiveBmsDataFromConsole() == 1);
  
}

/*TEST_CASE("Process sensor input and output in CSV format") {
  REQUIRE(processData() == E_OK);
}*/
