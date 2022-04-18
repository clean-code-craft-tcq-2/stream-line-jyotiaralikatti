#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream> // for ostringstream
#include <string.h>
#include<array>
#include <fstream>
using namespace std;
#define MAX_BMS_READ 50
typedef struct BMSPara{
  float Temperature[300];
  float Soc[300];
  int status;
}BMSParameters;

typedef struct BMSOutput{
  float min;
  float max;
  float SMA;
}MinMaxSMAOutput;

bool readSensorDataFromConsole()

BMSParameters receiveBmsDataFromConsole();
int processReceivedBmsStreamData();
