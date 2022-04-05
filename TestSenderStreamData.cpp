#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/SenderStreamBmsData.h"

SCENARIO("Read the Sender datas for Temperature and StateofCharge from file")
{
    GIVEN("Read input from file SenderData.txt")
    {
        float Temperature[NO_OF_SAMPLES] = {0};
        float StateOfCharge[NO_OF_SAMPLES] = {0};

        WHEN("Having Input data in file")
        {
            StatusType status_check  = E_NOT_OK;
            THEN("Check weather read of data from file is successful")
            {
               REQUIRE(SenderDataRead (Temperature,StateOfCharge) == E_OK);
            }
        }
    }
}
