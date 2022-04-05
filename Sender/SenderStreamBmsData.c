#include "SenderStreamBmsData.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

# define UNUSED(x) x

StatusType SenderDataRead(float* Temperature, float* StateOfCharge)
{
StatusType Ret = E_NOT_OK;
  /*
  ..
  Ret = E_OK;
  */
  Ret = E_OK;
   UNUSED(Temperature);
   UNUSED(StateOfCharge);
  return Ret;
  
}

void SendDataToConsole(float Temperature[], float StateOfCharge[])
{
    for(int index = 0; index < NUMBER_OF_MAX_DATA; index++)
    {
     printf("Temperature  %f and StateOfCharge  %f\n",Temperature[index],StateOfCharge[index]);
    }
}

StatusType BMS_Sender()
{
  float Temperature[NUMBER_OF_MAX_DATA]= {0}, StateOfCharge[NUMBER_OF_MAX_DATA] = {0};
  StatusType status_check = E_NOT_OK;
  
  status_check = SenderDataRead( Temperature,StateOfCharge);
  SendDataToConsole( Temperature,StateOfCharge);
  
  return status_check;
}
