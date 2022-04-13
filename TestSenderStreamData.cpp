#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/SenderStreamBmsData.h"

SCENARIO("Read the Sender datas for Temperature and StateofCharge from file")
{
    GIVEN("Read input from file SenderData.txt")
    {
        WHEN("Having Input data in file")
        {
            float Temperature[NUMBER_OF_MAX_DATA] = {0};
            float StateOfCharge[NUMBER_OF_MAX_DATA] = {0};

            THEN("Check weather read of data from file is successful")
            {
               REQUIRE(SenderData_ReadBatteryParametrs(Temperature,StateOfCharge) == E_OK);
            }
        }
    }
}

SCENARIO("Verify whether Read input from the Sender data is correctly processed and output to console")
{
    GIVEN(" Read input from file SenderData.txt")
    {
        WHEN(" Have Input data in file")
        {
            float Temperature[NUMBER_OF_MAX_DATA] = {0}, expectedTemp = 24;
            float StateOfCharge[NUMBER_OF_MAX_DATA] = {0}, expectedSOC = 90;

            THEN("Check weather read of data from file is successful")
            {
               REQUIRE(SenderData_ReadBatteryParametrs(Temperature,StateOfCharge) == E_OK);
               REQUIRE(Temperature[0] == expectedTemp);
               REQUIRE(StateOfCharge[0] == expectedSOC);
               REQUIRE(BMS_Sender() ==E_OK);
            }
        }
    }
}
