#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo abajo;
Servo arriba;
Servo medio;

int numAuxAbajo = 100;
int numAuxMedio = 78;
int numAuxArriba = 55;

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
      delay(150);
    }
  }
  else if(aux>=grados){
    while(aux>grados){
      medio.write(aux);
      aux--;
      delay(150);
    }
  }
}

void moverServoArriba(int aux, int grados){
  // Desplazamos a la posición 0º
  /*if(aux<=grados){
    while(aux<grados){
      arriba.write(aux);
      aux=aux+10;
      delay(500);
    }
  }
  else if(aux>=grados){
    while(aux>grados){
      arriba.write(aux);
      aux=aux-10;
      delay(500);
    }
  }*/
  arriba.write(grados);
  delay(350);
}

void setNumero(int numero){
  
  switch (numero) {
    case 1:
      moverServoAbajo(numAuxAbajo,90);
      moverServoMedio(numAuxMedio,90);
      moverServoArriba(numAuxArriba,140);
      numAuxAbajo = 90;
      numAuxMedio = 90;
      numAuxArriba = 140;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 2:
      moverServoAbajo(numAuxAbajo,88);
      moverServoMedio(numAuxMedio,80);
      moverServoArriba(numAuxArriba,112);
      numAuxAbajo = 88;
      numAuxMedio = 80;
      numAuxArriba = 112;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 3:

      break;  
    case 4:
      moverServoAbajo(numAuxAbajo,100);
      moverServoMedio(numAuxMedio,90);
      moverServoArriba(numAuxArriba,142);
      numAuxAbajo = 100;
      numAuxMedio = 90;
      numAuxArriba = 142;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 5:
      moverServoAbajo(numAuxAbajo,100);
      moverServoMedio(numAuxMedio,80);
      moverServoArriba(numAuxArriba,112);
      numAuxAbajo = 100;
      numAuxMedio = 80;
      numAuxArriba = 112;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 6:
      moverServoAbajo(numAuxAbajo,100);
      moverServoMedio(numAuxMedio,69);
      moverServoArriba(numAuxArriba,70); //53
      numAuxAbajo = 100;
      numAuxMedio = 70;
      numAuxArriba = 72; //53
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 7:
      moverServoAbajo(numAuxAbajo,110);
      moverServoMedio(numAuxMedio,90);
      moverServoArriba(numAuxArriba,142);
      numAuxAbajo = 110;
      numAuxMedio = 90;
      numAuxArriba = 142;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 8:
      moverServoAbajo(numAuxAbajo,115);
      moverServoMedio(numAuxMedio,80);
      moverServoArriba(numAuxArriba,112);
      numAuxAbajo = 115;
      numAuxMedio = 80;
      numAuxArriba = 112;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 9:
      //moverServoAbajo(180);
      //moverServoMedio(180);
      //moverServoArriba(0);
      break;
    case 0:
      moverServoAbajo(numAuxAbajo,125);
      moverServoMedio(numAuxMedio,77);
      moverServoArriba(numAuxArriba,112);
      numAuxAbajo = 125;
      numAuxMedio = 77;
      numAuxArriba = 112;
      
      moverServoArriba(numAuxArriba,180);
      numAuxArriba = 180;
      break;
    case 11:
      // statements
      break;
    case 12:
      // statements
      break;  
    default:
      // statements
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
  
  //setNumero(0);
  setNumero(6);
  setNumero(5);
  setNumero(4);
  setNumero(7);
  setNumero(1);
  setNumero(0);
  setNumero(8);
  setNumero(2);

  
  /*moverServoAbajo(50);
  moverServoAbajo(60);
  moverServoAbajo(70);
  moverServoAbajo(80);
  moverServoAbajo(90);
  moverServoAbajo(100);
  moverServoAbajo(90);
  moverServoAbajo(80);
  moverServoAbajo(70);
  moverServoAbajo(60);
  moverServoAbajo(50);*/
  
  
}
