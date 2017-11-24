#include "Arduino.h"
#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo abajo;
Servo arriba;
Servo medio;

int numAuxAbajo = 95;
int numAuxMedio = 55;
int numAuxArriba = 180;

String serialResponse = "";
int numeroActual = 0;



void moverServoAbajo(int aux, int grados){
  // Desplazamos a la posición 0º
  if(aux<=grados){
    while(aux<grados){
      abajo.write(aux);
      aux++;
      delay(150);
    }
  }
  else if(aux>=grados){
    while(aux>grados){
      abajo.write(aux);
      aux--;
      delay(150);
    }
  }
}


void moverServoMedio(int aux, int grados){
  // Desplazamos a la posición 0º
  if(aux<=grados){
    while(aux<grados){
      medio.write(aux);
      aux++;
      delay(100);
    }
  }
  else if(aux>=grados){
    while(aux>grados){
      medio.write(aux);
      aux--;
      delay(100);
    }
  }
}

void moverServoArriba(int aux, int grados){
  // Desplazamos a la posición 0º
  if(aux<=grados){
    while(aux<grados){
      arriba.write(aux);
      aux=aux+1;
      delay(25);
    }
  }
  else if(aux>=grados){
    while(aux>grados){
      arriba.write(aux);
      aux=aux-1;
      delay(25);
    }
  }
  //arriba.write(grados);
  //delay(350);
}




void instSize(String inst)
{
  if(inst[1] == '1')
  {
    Serial.print("Small ");
  }
  if(inst[1] == '2')
  {
    Serial.print("Medium ");
  }
  if(inst[1] == '3')
  {
    Serial.print("Big ");
  } 
  if(inst[2] == '1')
  { 
    Serial.println("Numeric");
  }
  if(inst[2] == '2')
  {
    Serial.println("Pattern");
  }
}

void touch(int numero)
{
  
}

void push(int numero)
{
  
}

int charToString(char n)
{
  if (n == '0')
    return 0;
  if (n == '1')
    return 1;
  if (n == '2')
    return 2;
  if (n == '3')
    return 3;
  if (n == '4')
    return 4;
  if (n == '5')
    return 5;
  if (n == '6')
    return 6;
  if (n == '7')
    return 7;
  if (n == '8')
    return 8;
  else 
    return 9;
}

void drag(char numero)
{
  numeroActual =  charToString(numero);
  
}

void processInstruction(String inst)
{
  if(inst[0] == '0')
  {
     Serial.print("size ");
     instSize(inst);
  }
  else if(inst[0] == '1')
  {
    touch(numeroActual);
    Serial.println("touch");
  }
  else if(inst[0] == '2')
  {
    push(numeroActual);
    Serial.println("push");
  }
  else if(inst[0] == '3')
  {
    drag(inst[1]);
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

void setup()
{
 Serial.begin(9600);
 Serial.setTimeout(5);
   abajo.attach(9);
  medio.attach(10);
  arriba.attach(11);
}


void loop()
{
  if ( Serial.available()) {
    splitInstructions();
  }
}

