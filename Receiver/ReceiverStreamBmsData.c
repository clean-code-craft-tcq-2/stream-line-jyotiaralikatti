#include "ReceiverStreamBmsData.h"

int receiveBmsDataFromConsole(){
  float input1[300];
  float input2[300];
  //scanf("%f",&input);
  //printf("%f, %f, %f, %f",input[0],input[1],input[2],input[3]);
  
  char unusedData[300];
    for(int j = 0; j < 6; j++){
        if(scanf("%50s", unusedData) == EOF) 
        {
            break;
        } 
        scanf("%f", &input1[j]);     
        scanf("%50s", unusedData);
        scanf("%50s", unusedData);
        scanf("%50s", unusedData);
        scanf("%f", &input2[j]);
        printf("%f, %f",input1[j],input2[j]);
    }
  
  return 1;
}

int findMaxValueFromBmsConsole(char* inputArray){
  return 1;
}

int findMinValueFromBmsConsole(char* inputArray){
  return 1;
}
int findMovingAverageFromBmsData(char* inputArray){
  return 1;
}

void printToConsoleMinMaxAndMovingAverage(char min, char max, char movingAverage){
  
  cout << "Min Value is : " << min << " Max Value is : " << max <<" Moving Average is : " << movingAverage <<endl;
}

/*processReceivedBmsStreamData(){
  char *receiverBuffer = receiveBmsDataFromConsole();
  char max = findMaxValueFromBmsConsole(receiverBuffer);
  char min = findMinValueFromBmsConsole(receiverBuffer);
  char movingAverage = findMovingAverageFromBmsData(receiverBuffer);
  printToConsoleMinMaxAndMovingAverage(min, max,movingAverage);
*/
