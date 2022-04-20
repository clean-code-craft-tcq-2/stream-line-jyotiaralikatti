#pragma once

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NUMBER_OF_MAX_DATA 50

typedef enum
{
	E_NOT_OK,
	E_OK
}StatusType;

StatusType SenderData_ReadBatteryParametrs(float* , float* );
void SendDataToConsole(float Temperature[], float StateOfCharge[]);
StatusType BMS_Sender();
