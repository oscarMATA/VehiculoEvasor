#include "Ultrasonic.h"
#include "control.h"
#include "Arduino.h"

Ultrasonic ultrasonic(12,13);//output, input,                SENSOR IZQ
Ultrasonic ultrasonic2(6,7); //                              SENSOR DER
Ultrasonic ultrasonic3(8,9); //solo utilizo el 9 como input  SENSOR FRONTAL
 long A;
 long B;
 long C;
 
 long cR, cL,cF,lR,lL,lF;
 long cercaR, cercaL, cercaF, lejosC, lejosR, lejosF;
 long centroideR, centroideL;

void setup() 
{
  Serial.begin(9600);
  TCCR2B = TCCR2B & 0b11111000 | 0x4; //490 HZ , pin 3 y 11

}

void loop()
{



    //control TOTAL
    A = ultrasonic.Ranging();
    B = ultrasonic2.Ranging();
    C = ultrasonic3.RangeFinder();
    
    cR = evaluacionCercaRL(A);
    cL = evaluacionCercaRL(B);
    cF = evaluacionCercaF(C);
    
    lR = evaluacionLejosRL(A);
    lL = evaluacionLejosRL(B);
    lF = evaluacionLejosF(C);
    
    centroideR = evaluacionReglasR(cR,cL,cF,lR,lL,lF);
    centroideL = evaluacionReglasL(cR,cL,cF,lR,lL,lF);
    
    

    motorL(centroideL);
    motorR(centroideR);

   
  //control
 //PARA CAMBIAR EL DUTY CYCLE, pin 3, porcentaje de duty = PERCENT
 // 50% reversa
 //75% stop
 //100 % adelante
 //analogWrite(3, 255* 60/100.0 ); //L
 //analogWrite(11, 255* 90/100.0 ); //R
 
}
