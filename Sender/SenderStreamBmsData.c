#include "SenderStreamBmsData.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

StatusType SenderData_ReadBatteryParametrs(float* Temperature, float* StateOfCharge)
{
StatusType Ret = E_NOT_OK;
    float Temp, SOC;
    FILE * file= fopen("./Sender/SenderData.txt","r");  
    if (file!=NULL) {
        for(int i=0;fscanf(file, "%f\t%f\n", &Temp,&SOC)!=EOF ;i++)
        {
            Temperature[i] = Temp;
            StateOfCharge[i]  = SOC;
        }
      Ret = E_OK;
    }
    fclose(file); 
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
  
  status_check = SenderData_ReadBatteryParametrs( Temperature,StateOfCharge);
  SendDataToConsole( Temperature,StateOfCharge);
  
  return status_check;
}
