#include "ReceiverStreamBmsData.h"

int receiveBmsDataFromConsole(){
  string input;
  scanf("%s",&input);
  printf("%s",&input);
  return 1;
}

char findMaxValueFromBmsConsole(char* inputArray){
}

char findMinValueFromBmsConsole(char* inputArray){
  
}
char findMovingAverageFromBmsData(char* inputArray){
  
}

void printToConsoleMinMaxAndMovingAverage(char min, char max, char movingAverage){
  
  cout << "Min Value is : " << min << " Max Value is : " << max <<" Moving Average is : " << movingAverage <<endl;
}

processReceivedBmsStreamData(){
  char *receiverBuffer = receiveBmsDataFromConsole();
  char max = findMaxValueFromBmsConsole(receiverBuffer);
  char min = findMinValueFromBmsConsole(receiverBuffer);
  char movingAverage = findMovingAverageFromBmsData(receiverBuffer);
  printToConsoleMinMaxAndMovingAverage(min, max,movingAverage);
}
