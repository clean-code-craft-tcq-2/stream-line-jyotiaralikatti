#include "ReceiverStreamBmsData.h"

BMSParameters receiveBmsDataFromConsole(){
  
  char dicardData[300];
  BMSParameters batteryParameters;
  float temperature[50];
  float SOC;
  for(int bufferIndex1 = 0; bufferIndex1 < 50; bufferIndex1++){
    cin >> temperature[bufferIndex1] >> dicardData >> SOC;   
    batteryParameters.Temperature[bufferIndex1] = temperature[bufferIndex1];
    batteryParameters.Soc[bufferIndex1] = SOC;   
    printf("temperature : %f\n, index : %d",temperature[0], bufferIndex1);//,batteryParameters.Soc[0]);
    break;
    //printf("%f, %f\n",batteryParameters.Temperature[bufferIndex],batteryParameters.Soc[bufferIndex]);
    }
  
   //printf("%f\n",batteryParameters.Temperature[0]);//,batteryParameters.Soc[0]);
  batteryParameters.status = 1;
  return batteryParameters;
}

int cmpfunc (const void * int_previousBufferElement, const void * int_currentBufferElement) {
   return ( *(int*)int_previousBufferElement - *(int*)int_currentBufferElement );
}

 float* MinMaxSortFunc(float* InputArray)
 {
   //sort (InputArray, InputArray+50);
   qsort(InputArray, 50, sizeof(float),cmpfunc);
   return InputArray;
 }

MinMaxSMAOutput findMinMaxValueTemperatureFromBmsSender(float* inputArray){
  MinMaxSMAOutput temperatureMinMaxSMAOutput;
  
  float* outputArray = MinMaxSortFunc(inputArray);
 /* for(int i=-25;i<25;i++){
    cout<<outputArray[i]<<endl;
  }*/
  temperatureMinMaxSMAOutput.min = outputArray[0];
  temperatureMinMaxSMAOutput.max = outputArray[49];
  return temperatureMinMaxSMAOutput;
}

MinMaxSMAOutput findMinMaxValueSocFromBmsSender(float* inputArray){
  float* outputArray = MinMaxSortFunc(inputArray);
  MinMaxSMAOutput SocMinMaxSMAOutput;
  SocMinMaxSMAOutput.min = outputArray[0];
  SocMinMaxSMAOutput.max = outputArray[49];
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
  /* for(int i=0;i<50;i++){
    cout<<"TempArray " << batterParam.Temperature[i]<<endl;
  }*/
  MinMaxSMAOutput Temp = findMinMaxValueTemperatureFromBmsSender(&(batterParam.Temperature[0]));
  MinMaxSMAOutput Soc = findMinMaxValueSocFromBmsSender(batterParam.Soc);
 // MinMaxSMAOutput movingAverage = findMovingAverageFromBmsData(receiverBuffer);
  printToConsoleMinMaxAndMovingAverage("Parameter : Temperature",Temp.min,Temp.max,1);
  printToConsoleMinMaxAndMovingAverage("Parameter : SOC",Soc.min,Soc.max,1);
  return 1;
}

