#include "SenderStreamBmsData.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

StatusType SenderDataRead(float* Temperature, float* StateOfCharge)
{
StatusType Ret = E_NOT_OK;
  /*
  ..
  Ret = E_OK;
  */
  return Ret;
  
}

void SendDataToConsole(float Temperature[], float StateOfCharge[])
{
    for(int index = 0; index < NUMBER_OF_MAX_DATA; index++)
    {
     printf("Temperature  %f and StateOfCharge  %f\n",Temperature[i],StateOfCharge[i]);
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
