#include "ReceiverStreamBmsData.h"

int receiveBmsDataFromConsole(float* Temperature, float* Soc){
  
  char dicardData[300];
  for(int bufferIndex = 0; bufferIndex < 6; bufferIndex++){
    scanf("%f", &Temperature[bufferIndex]);     
    scanf("%50s", dicardData);
    scanf("%f", &soc[bufferIndex]);
    /*if(scanf("%50s", unusedData) == EOF) 
        {
            break;
        } */
    printf("%f, %f\n",Temperature[bufferIndex],Soc[bufferIndex]);
    }
  
  return 1;
}


static int intCompare(const void *previousBufferElement, const void *currentBufferElement)
{
    float int_previousBufferElement = * ( (float*) previousBufferElement );
    float int_currentBufferElement = * ( (float*) currentBufferElement );

    if ( int_previousBufferElement == int_currentBufferElement ) return 0;
    else if ( int_previousBufferElement < int_currentBufferElement ) return -1;
    else return 1;
}
 void MinMaxSortFunc(float* InputArray)
 {
   qsort(inputArray, 50, sizeof(float), intCompare);
 }

float findMinMaxValueTemperatureFromBmsSender(float* inputArray){
  MinMaxSortFunc(inputArray);
  return inputArray[0];
}

float findMinMaxValueSocFromBmsSender(float* inputArray){
  MinMaxSortFunc(inputArray);
  return inputArray[0];
}
float findMovingAverageFromBmsData(float* inputArray){
  return 1;
}

void printToConsoleMinMaxAndMovingAverage(float min, float max, int movingAverage){
  
  cout << "Min Value is : " << min << " Max Value is : " << max <<" Moving Average is : " << movingAverage <<endl;
}

int processReceivedBmsStreamData(){
  float Temperature[300];
  float Soc[300];  
  int status = receiveBmsDataFromConsole(Temperature, Soc);
  float minTemp = findMinMaxValueTemperatureFromBmsSender(Temperature);
  float minSoc = findMinMaxValueSocFromBmsSender(Soc);
 // char movingAverage = findMovingAverageFromBmsData(receiverBuffer);
  printToConsoleMinMaxAndMovingAverage(minTemp, minSoc,1);
  return 1;
}

