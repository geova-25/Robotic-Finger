#include "Arduino.h"

String serialResponse = "";



void setup()
{
 Serial.begin(9600);
 Serial.setTimeout(5);
}


void processInstruction(String inst)
{
  if(inst[0] == '0')
  {
     Serial.println("size");
  }
  else if(inst[0] == '1')
  {
    Serial.println("touch");
  }
  else if(inst[0] == '2')
  {
    Serial.println("push");
  }
  else if(inst[0] == '3')
  {
    Serial.println("drag");
  }
  else if(inst[0] == '4')
  {
    Serial.println("cypher");
  }
  else
  {
    Serial.println("Wrong instruction");
  }
}

void splitInstructions()
{
  serialResponse = Serial.readStringUntil('\r\n');
  int largoString = serialResponse.length();
   
  String inst = "";
   for (int i = 0 ;  i < largoString ; i++)
   {
     if (serialResponse[i] != ';')
     {
       inst = inst + serialResponse[i];
     }
     else
     {
       processInstruction(inst);
       inst = "";
       
     }
      
   }
}


void loop()
{
  if ( Serial.available()) {
    splitInstructions();
  }
}

