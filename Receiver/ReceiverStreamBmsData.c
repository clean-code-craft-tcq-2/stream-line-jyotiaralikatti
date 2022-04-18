#include "ReceiverStreamBmsData.h"


BMSParameters receiveBmsDataFromConsole(){
  
  char dicardData[300];
  BMSParameters batteryParameters;
  for(int bufferIndex = 0; bufferIndex < 6; bufferIndex++){
    scanf("%f", &(batteryParameters.Temperature[bufferIndex]));     
    scanf("%50s", dicardData);
    scanf("%f", &(batteryParameters.Soc[bufferIndex]));
    batteryParameters.status =1;
    /*if(scanf("%50s", unusedData) == EOF) 
        {
            break;
        } */
    printf("%f, %f\n",batteryParameters.Temperature[bufferIndex],batteryParameters.Soc[bufferIndex]);
    }
  
  return batteryParameters;
}


static int intCompare(const void *previousBufferElement, const void *currentBufferElement)
{
    float int_previousBufferElement = * ( (float*) previousBufferElement );
    float int_currentBufferElement = * ( (float*) currentBufferElement );

    if ( int_previousBufferElement == int_currentBufferElement ) return 0;
    else if ( int_previousBufferElement < int_currentBufferElement ) return -1;
    else return 1;
}
 float* MinMaxSortFunc(float* InputArray)
 {
   qsort(InputArray, 50, sizeof(float), intCompare);
   return InputArray;
 }

float findMinMaxValueTemperatureFromBmsSender(float* inputArray){
  
  float* outputArray = MinMaxSortFunc(inputArray);
  for(int i=0; i<6;i++){
    printf("%f\n",outputArray[i]);
           }
  return outputArray[0];
}

float findMinMaxValueSocFromBmsSender(float* inputArray){
  float* outputArray = MinMaxSortFunc(inputArray);
  return outputArray[0];
}
float findMovingAverageFromBmsData(float* inputArray){
  return 1;
}

void printToConsoleMinMaxAndMovingAverage(float min, float max, int movingAverage){
  
  cout << "Min Value is : " << min << " Max Value is : " << max <<" Moving Average is : " << movingAverage <<endl;
}

int processReceivedBmsStreamData(){
  BMSParameters batterParam;
  
  batterParam = receiveBmsDataFromConsole();
  float minTemp = findMinMaxValueTemperatureFromBmsSender((batterParam.Temperature));
  float minSoc = findMinMaxValueSocFromBmsSender(batterParam.Soc);
 // char movingAverage = findMovingAverageFromBmsData(receiverBuffer);
  printToConsoleMinMaxAndMovingAverage(minTemp, minSoc,1);
  return 1;
}

