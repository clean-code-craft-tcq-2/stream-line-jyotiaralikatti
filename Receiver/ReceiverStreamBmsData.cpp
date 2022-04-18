#include "ReceiverStreamBmsData.h"


bool readSensorDataFromConsole()
{
  float temperature[200];
  float SOC[200];
  char unwanted[200];
    /*for(int i = 0; i < 50; i++)
    {
      cin >> temperature[i] >> unwanted >> SOC[i];
      cout << temperature[i] <<" " <<SOC[i] <<endl;
    }*/
    
    return true;
}

BMSParameters receiveBmsDataFromConsole(){
  
  char dicardData[300];
  BMSParameters batteryParameters;
  for(int bufferIndex = 0; bufferIndex < 24; bufferIndex++){
    cin >> &(batteryParameters.Temperature[bufferIndex]) >> dicardData >> &(batteryParameters.Soc[bufferIndex]);     
   // scanf("%50s", dicardData);
   // scanf("%f", &(batteryParameters.Soc[bufferIndex]));
    //batteryParameters.status = 1;
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
   qsort(InputArray, 48, sizeof(float), cmpfunc);
   return InputArray;
 }

MinMaxSMAOutput findMinMaxValueTemperatureFromBmsSender(float* inputArray){
  MinMaxSMAOutput temperatureMinMaxSMAOutput;
  float* outputArray = MinMaxSortFunc(inputArray);
  temperatureMinMaxSMAOutput.min = outputArray[0];
  temperatureMinMaxSMAOutput.max = outputArray[47];
  return temperatureMinMaxSMAOutput;
}

MinMaxSMAOutput findMinMaxValueSocFromBmsSender(float* inputArray){
  float* outputArray = MinMaxSortFunc(inputArray);
  MinMaxSMAOutput SocMinMaxSMAOutput;
  SocMinMaxSMAOutput.min = outputArray[0];
  SocMinMaxSMAOutput.max = outputArray[47];
  return SocMinMaxSMAOutput;
}
float findMovingAverageFromBmsData(float* inputArray){
  return 1;
}

void printToConsoleMinMaxAndMovingAverage(string parameter, float min, float max, int movingAverage){
  
  cout << parameter << "Min Value is : " << min << " Max Value is : " << max <<" Moving Average is : " << movingAverage <<endl;
}

int processReceivedBmsStreamData(){
  BMSParameters batterParam;
  
  batterParam = receiveBmsDataFromConsole();
  MinMaxSMAOutput Temp = findMinMaxValueTemperatureFromBmsSender((batterParam.Temperature));
  MinMaxSMAOutput Soc = findMinMaxValueSocFromBmsSender(batterParam.Soc);
 // MinMaxSMAOutput movingAverage = findMovingAverageFromBmsData(receiverBuffer);
  printToConsoleMinMaxAndMovingAverage("Parameter : Temperature",Temp.min,Temp.max,1);
  printToConsoleMinMaxAndMovingAverage("Parameter : SOC",Soc.min,Soc.max,1);
  return 1;
}

