#include "ReceiverStreamBmsData.h"

int receiveBmsDataFromConsole(){
  float input[5000];
  for(int i =0 ; i<50;i++){
    scanf("%f",input[i]);
  }
  printf("%f, %f, %f, %f",input[0],input[1],input[2],input[3]);
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
