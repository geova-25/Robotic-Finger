#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo abajo;
Servo arriba;
Servo medio;

int numAuxAbajo = 95;
int numAuxMedio = 55;
int numAuxArriba = 180;

void inicio(){
  setNumero(15);
}

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

void setNumero(int numero){
  
  switch (numero) {
    case 1:
      moverServoAbajo(numAuxAbajo,85);
      moverServoMedio(numAuxMedio,84);
      moverServoArriba(numAuxArriba,140);
      numAuxAbajo = 85;
      numAuxMedio = 84;
      numAuxArriba = 140;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 2:
      moverServoAbajo(numAuxAbajo,83);
      moverServoMedio(numAuxMedio,74);
      moverServoArriba(numAuxArriba,112);
      numAuxAbajo = 83;
      numAuxMedio = 74;
      numAuxArriba = 112;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 3:
      moverServoAbajo(numAuxAbajo,80);
      moverServoMedio(numAuxMedio,55);
      moverServoArriba(numAuxArriba,69); //53
      numAuxAbajo = 80;
      numAuxMedio = 55;
      numAuxArriba = 69; //53
      
      moverServoMedio(numAuxMedio,69);
      numAuxMedio = 69;
      
      moverServoMedio(numAuxMedio,55);
      numAuxMedio = 55;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;  
    case 4:
      moverServoAbajo(numAuxAbajo,95);
      moverServoMedio(numAuxMedio,84);
      moverServoArriba(numAuxArriba,142);
      numAuxAbajo = 95;
      numAuxMedio = 84;
      numAuxArriba = 142;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 5:
      moverServoAbajo(numAuxAbajo,95);
      moverServoMedio(numAuxMedio,75);
      moverServoArriba(numAuxArriba,112);
      numAuxAbajo = 95;
      numAuxMedio = 75;
      numAuxArriba = 112;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 6:
      moverServoAbajo(numAuxAbajo,95);
      moverServoMedio(numAuxMedio,55);
      moverServoArriba(numAuxArriba,70); //53
      numAuxAbajo = 95;
      numAuxMedio = 55;
      numAuxArriba = 70; //53
      
      moverServoMedio(numAuxMedio,68);
      numAuxMedio = 68;
      
      moverServoMedio(numAuxMedio,55);
      numAuxMedio = 55;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 7:
      moverServoAbajo(numAuxAbajo,105);
      moverServoMedio(numAuxMedio,84);
      moverServoArriba(numAuxArriba,142);
      numAuxAbajo = 105;
      numAuxMedio = 84;
      numAuxArriba = 142;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 8:
      moverServoAbajo(numAuxAbajo,110);
      moverServoMedio(numAuxMedio,75);
      moverServoArriba(numAuxArriba,117);
      numAuxAbajo = 110;
      numAuxMedio = 75;
      numAuxArriba = 117;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 9:
      moverServoAbajo(numAuxAbajo,115);
      moverServoMedio(numAuxMedio,55);
      moverServoArriba(numAuxArriba,72); //53
      numAuxAbajo = 115;
      numAuxMedio = 55;
      numAuxArriba = 72; //53
      
      
      moverServoMedio(numAuxMedio,68);
      numAuxMedio = 68;
      
      moverServoMedio(numAuxMedio,55);
      numAuxMedio = 55;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 0:
      moverServoAbajo(numAuxAbajo,120);
      moverServoMedio(numAuxMedio,75);
      moverServoArriba(numAuxArriba,117);
      numAuxAbajo = 120;
      numAuxMedio = 75;
      numAuxArriba = 117;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 11:
      moverServoAbajo(numAuxAbajo,130);
      moverServoMedio(numAuxMedio,55);
      moverServoArriba(numAuxArriba,80);
      numAuxAbajo = 130;
      numAuxMedio = 55;
      numAuxArriba = 80;
      
      
      moverServoMedio(numAuxMedio,68);
      numAuxMedio = 68;
      
      moverServoMedio(numAuxMedio,55);
      numAuxMedio = 55;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 12:
      // statements
      break;  
    default:
      moverServoAbajo(numAuxAbajo,95);
      moverServoMedio(numAuxMedio,25);
      moverServoArriba(numAuxArriba,70); //53
      numAuxAbajo = 95;
      numAuxMedio = 25;
      numAuxArriba = 70; //53
      break;
  }
}


void setNumeroMedio(int numero){
  
  switch (numero) {
    case 1:
      moverServoAbajo(numAuxAbajo,82);
      moverServoMedio(numAuxMedio,84);
      moverServoArriba(numAuxArriba,139);
      numAuxAbajo = 82;
      numAuxMedio = 84;
      numAuxArriba = 139;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 2:
      moverServoAbajo(numAuxAbajo,80);
      moverServoMedio(numAuxMedio,74);
      moverServoArriba(numAuxArriba,110);
      numAuxAbajo = 80;
      numAuxMedio = 74;
      numAuxArriba = 110;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 3:
      moverServoAbajo(numAuxAbajo,77);
      moverServoMedio(numAuxMedio,55);
      moverServoArriba(numAuxArriba,69); //53
      numAuxAbajo = 77;
      numAuxMedio = 55;
      numAuxArriba = 69; //53
      
      moverServoMedio(numAuxMedio,69);
      numAuxMedio = 69;
      
      moverServoMedio(numAuxMedio,55);
      numAuxMedio = 55;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;  
    case 4:
      moverServoAbajo(numAuxAbajo,95);
      moverServoMedio(numAuxMedio,84);
      moverServoArriba(numAuxArriba,140);
      numAuxAbajo = 95;
      numAuxMedio = 84;
      numAuxArriba = 140;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 5:
      moverServoAbajo(numAuxAbajo,95);
      moverServoMedio(numAuxMedio,75);
      moverServoArriba(numAuxArriba,110);
      numAuxAbajo = 95;
      numAuxMedio = 75;
      numAuxArriba = 110;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 6:
      moverServoAbajo(numAuxAbajo,95);
      moverServoMedio(numAuxMedio,55);
      moverServoArriba(numAuxArriba,70); //53
      numAuxAbajo = 95;
      numAuxMedio = 55;
      numAuxArriba = 70; //53
      
      moverServoMedio(numAuxMedio,70);
      numAuxMedio = 70;
      
      moverServoMedio(numAuxMedio,55);
      numAuxMedio = 55;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 7:
      moverServoAbajo(numAuxAbajo,100);
      moverServoMedio(numAuxMedio,84);
      moverServoArriba(numAuxArriba,140);
      numAuxAbajo = 100;
      numAuxMedio = 84;
      numAuxArriba = 140;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 8:
      moverServoAbajo(numAuxAbajo,100);
      moverServoMedio(numAuxMedio,75);
      moverServoArriba(numAuxArriba,112);
      numAuxAbajo = 100;
      numAuxMedio = 75;
      numAuxArriba = 112;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 9:
      moverServoAbajo(numAuxAbajo,110);
      moverServoMedio(numAuxMedio,55);
      moverServoArriba(numAuxArriba,72); //53
      numAuxAbajo = 110;
      numAuxMedio = 55;
      numAuxArriba = 72; //53
      
      
      moverServoMedio(numAuxMedio,68);
      numAuxMedio = 68;
      
      moverServoMedio(numAuxMedio,55);
      numAuxMedio = 55;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 0:
      moverServoAbajo(numAuxAbajo,110);
      moverServoMedio(numAuxMedio,75);
      moverServoArriba(numAuxArriba,111);
      numAuxAbajo = 100;
      numAuxMedio = 75;
      numAuxArriba = 111;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 11:
      moverServoAbajo(numAuxAbajo,115);
      moverServoMedio(numAuxMedio,55);
      moverServoArriba(numAuxArriba,80);
      numAuxAbajo = 115;
      numAuxMedio = 55;
      numAuxArriba = 80;
      
      
      moverServoMedio(numAuxMedio,68);
      numAuxMedio = 68;
      
      moverServoMedio(numAuxMedio,55);
      numAuxMedio = 55;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 12:
      // statements
      break;  
    default:
      moverServoAbajo(numAuxAbajo,95);
      moverServoMedio(numAuxMedio,25);
      moverServoArriba(numAuxArriba,70); //53
      numAuxAbajo = 95;
      numAuxMedio = 25;
      numAuxArriba = 70; //53
      break;
  }
}
  
void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  abajo.attach(9);
  medio.attach(10);
  arriba.attach(11);
}
 
void loop() {
  inicio();
  
  /*setNumero(6);
  setNumero(5);
  setNumero(4);
  setNumero(7);
  setNumero(1);
  setNumero(0);
  setNumero(8);
  setNumero(2);
  setNumero(3);
  setNumero(9);
  setNumero(11);*/
  
  //setNumeroMedio(6);
  //setNumeroMedio(5);
  //setNumeroMedio(4);
  //setNumeroMedio(1);
  //setNumeroMedio(2);
  //setNumeroMedio(3);
  //setNumeroMedio(9);
  //setNumeroMedio(8);
  //setNumeroMedio(7);
  //setNumeroMedio(0);
  //setNumeroMedio(11);
  
  
  
}
