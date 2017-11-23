#include "roboticFingerCon.h"

/*
** This function is in charge of sending data to the driver
** reveives as a parameter the string that we are going to send to the finger
*/
void sendDataToFinger(char* stringToSend)
{
  int size;
  size = strlen(stringToSend); //get the size of the string
  printf("size: %d\n",size);
  printf("This what I get: %s\n", stringToSend);
  FILE *fp;  //FILE type to open the device driver
  fp=fopen("/dev/robotic_finger", "w"); //open the device driver
  if(fp == NULL) printf("Error openning the robotic finger driver\n");
  else fwrite(stringToSend, sizeof(char),size,fp); //write to the driver that send to
                                                   //robotic finger
  fclose(fp);
}

/*
int main(int argc, char *argv[])
{
  //char* result = calloc(100,sizeof(char));
  //char* newData = calloc(100,sizeof(char));
  //char* newData2 = calloc(100,sizeof(char));
  //newData2 = "Test 4";

  //newData[0] = '0';
  //newData[1] = '1';
  //newData[2] = '2';
  //newData[3] = '3';
  //newData[4] = '5';
  newData = "No way man";
  strcat(result,newData);
  strcat(result,newData2);
  sendDataToFinger(result);
}
*/
