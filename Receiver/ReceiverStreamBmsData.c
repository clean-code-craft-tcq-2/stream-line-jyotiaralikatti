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

int cmpfunc (const void * int_previousBufferElement, const void * int_currentBufferElement) {
   return ( *(int*)int_previousBufferElement - *(int*)int_currentBufferElement );
}

 float* MinMaxSortFunc(float* InputArray)
 {
   qsort(InputArray, 50, sizeof(float), cmpfunc);
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

