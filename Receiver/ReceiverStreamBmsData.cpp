#include "ReceiverStreamBmsData.h"

BMSParameters receiveBmsDataFromConsole(){
  
  char dicardData[300];
  BMSParameters batteryParameters;
  float temperature;
  float SOC;
  
  for(int bufferIndex = 0; bufferIndex < MAX_BMS_READ ; bufferIndex++){
    cin >> temperature >> dicardData >> SOC;   
    batteryParameters.Temperature[bufferIndex] = temperature;
    batteryParameters.Soc[bufferIndex] = SOC;   
    //printf("%f, %f\n",batteryParameters.Temperature[bufferIndex],batteryParameters.Soc[bufferIndex]);
    }
  batteryParameters.status = 1;
  return batteryParameters;
}

int cmpfunc (const void * int_previousBufferElement, const void * int_currentBufferElement) {
   return ( *(int*)int_previousBufferElement - *(int*)int_currentBufferElement );
}

 float* MinMaxSortFunc(float* InputArray)
 {
   qsort(InputArray, MAX_BMS_READ , sizeof(float),cmpfunc);
   return InputArray;
 }

float findMovingAverageFromBmsData(float* inputArray, int arraySize){
  float SMAValue = 0.0;
  float sampleAdditionForSMA = 0.0;
  int noOfSamplesToBeAveraged = 5;
   for (int idx = 0; idx < 5; idx++)
    {
        sampleAdditionForSMA += inputArray[arraySize-idx-1];
    }
    SMAValue = sampleAdditionForSMA/noOfSamplesToBeAveraged;
    return SMAValue;
}

MinMaxSMAOutput findMinMaxValueTemperatureFromBmsSender(float* inputArray){
  MinMaxSMAOutput temperatureMinMaxSMAOutput;
  temperatureMinMaxSMAOutput.SMA = findMovingAverageFromBmsData(inputArray,MAX_BMS_READ);
  float* outputArray = MinMaxSortFunc(inputArray);
  temperatureMinMaxSMAOutput.min = outputArray[0];
  temperatureMinMaxSMAOutput.max = outputArray[MAX_BMS_READ - 1];
  return temperatureMinMaxSMAOutput;
}

MinMaxSMAOutput findMinMaxValueSocFromBmsSender(float* inputArray){
  MinMaxSMAOutput SocMinMaxSMAOutput;
  SocMinMaxSMAOutput.SMA = findMovingAverageFromBmsData(inputArray,MAX_BMS_READ);
  float* outputArray = MinMaxSortFunc(inputArray);
  SocMinMaxSMAOutput.min = outputArray[0];
  SocMinMaxSMAOutput.max = outputArray[MAX_BMS_READ  - 1];
  return SocMinMaxSMAOutput;
}


void printToConsoleMinMaxAndMovingAverage(string parameter, float min, float max, int movingAverage){
  
  cout << parameter << " Min Value is : " << min << " Max Value is : " << max <<" Moving Average is : " << movingAverage <<endl;
}

int processReceivedBmsStreamData(){
  BMSParameters batterParam;
  batterParam = receiveBmsDataFromConsole();
  MinMaxSMAOutput Temp = findMinMaxValueTemperatureFromBmsSender(&(batterParam.Temperature[0]));
  MinMaxSMAOutput Soc = findMinMaxValueSocFromBmsSender(batterParam.Soc);
  printToConsoleMinMaxAndMovingAverage("Parameter : Temperature : ", Temp.min, Temp.max, Temp.SMA);
  printToConsoleMinMaxAndMovingAverage("Parameter : SOC : ", Soc.min, Soc.max, Soc.SMA);
  return 1;
}

