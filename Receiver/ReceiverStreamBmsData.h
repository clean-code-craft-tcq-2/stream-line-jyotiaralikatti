#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream> // for ostringstream
#include <string.h>
#include<array>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_BMS_READ 50
typedef struct BMSPara{
  float Temperature[50];
  float Soc[50];
  int status;
}BMSParameters;

typedef struct BMSOutput{
  float min;
  float max;
  float SMA;
}MinMaxSMAOutput;

BMSParameters receiveBmsDataFromConsole();
int processReceivedBmsStreamData();
float findMovingAverageFromBmsData(float* inputArray, int arraySize);
