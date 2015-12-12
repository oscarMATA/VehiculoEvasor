#include "Arduino.h"
#include "control.h"

long evaluacionCercaRL (long distance)
{
    long cerca;
    //CERCA
    if (distance  <= cercaRL_1)
    {
      cerca = 100;
    }
    else if ((distance > cercaRL_1 ) && (distance < cercaRL_2) )
    {
      cerca = 100-((100/(cercaRL_2 - cercaRL_1))*(distance - cercaRL_1));
    }
    else
    {
      cerca = 0;
    }
    return cerca;
}


long evaluacionCercaF (long distance)
{
  long cerca;
  if (distance  <= cercaF_1)
  {
    cerca = 100;
  }
  else if ((distance > cercaF_1 )&&(distance < cercaF_2) )
  {
    cerca = 100-((100/(cercaF_2 - cercaF_1))*(distance - cercaF_1));
  }
  else
  {
    cerca = 0;
  }
  
  return cerca;
}

long evaluacionLejosRL (long distance)
{
   long lejos;
  //LEJOS
  if (distance  <= lejosRL_1)
  {
    lejos = 0;
  }
  else if ((distance > lejosRL_1 )&(distance < lejosRL_2) )
  {
    lejos = (100/(lejosRL_2 - lejosRL_1))*(distance - lejosRL_1);
  }
  else
  {
    lejos = 100;
  }
  
  return lejos;
}



long evaluacionLejosF (long distance)
{
  long lejos;
  if (distance  <= lejosF_1)
  {
    lejos = 0;
  }
  else if ((distance > lejosF_1 )&(distance < lejosF_2) )
  {
    lejos = (100/(lejosF_2 - lejosF_1))*(distance- lejosF_1);
  }
  else
  {
    lejos = 100;
  }
  
  return lejos;
}

long evaluacionReglasL (long cercaR, long cercaL, long cercaF, long lejosR, long lejosL, long lejosF)
{
  long R1,R2,R3,R4,R5,R6,R7,R8;
  long vL1,vL2,vL3,vL4,vL5,vL6,vL7,vL8;
  long centroideL;
  long num,den;
  
  R1 = andFnct(lejosL,lejosR,lejosF);
  R2 = andFnct(lejosL,lejosR,cercaF);
  R3 = andFnct(lejosL,cercaR,lejosF);
  R4 = andFnct(lejosL,cercaR,cercaF);
  R5 = andFnct(cercaL,lejosR,lejosF);
  R6 = andFnct(cercaL,lejosR,cercaF);
  R7 = andFnct(cercaL,cercaR,lejosF);
  R8 = andFnct(cercaL,cercaR,cercaF);
  
  vL1 = R1*ADELANTE;
  vL2 = R2*ATRAS;
  vL3 = R3*ATRAS;
  vL4 = R4*ATRAS;
  vL5 = R5*ADELANTE;
  vL6 = R6*ADELANTE;
  vL7 = R7*ADELANTE;
  vL8 = R8*ATRAS;
  
  num = vL1 + vL2 + vL3 + vL4 + vL5 + vL6 + vL7 + vL8 ;
  den = R1 + R2 + R3 + R4 + R5 + R6 + R7 + R8;
  centroideL =num/den;
  

    
  return centroideL;
}

long evaluacionReglasR (long cercaR, long cercaL, long cercaF, long lejosR, long lejosL, long lejosF)
{
  long R1,R2,R3,R4,R5,R6,R7,R8;
  long vR1,vR2,vR3,vR4,vR5,vR6,vR7,vR8;
  long centroideR;
  
  R1 = andFnct(lejosL,lejosR,lejosF);
  R2 = andFnct(lejosL,lejosR,cercaF);
  R3 = andFnct(lejosL,cercaR,lejosF);
  R4 = andFnct(lejosL,cercaR,cercaF);
  R5 = andFnct(cercaL,lejosR,lejosF);
  R6 = andFnct(cercaL,lejosR,cercaF);
  R7 = andFnct(cercaL,cercaR,lejosF);
  R8 = andFnct(cercaL,cercaR,cercaF);
  
  vR1 = R1*ADELANTE;
  vR2 = R2*ADELANTE;
  vR3 = R3*ADELANTE;
  vR4 = R4*ADELANTE;
  vR5 = R5*ATRAS;
  vR6 = R6*ATRAS;
  vR7 = R7*ADELANTE;
  vR8 = R8*ATRAS;
  
  centroideR = (vR1 + vR2 + vR3 + vR4 + vR5 + vR6 + vR7 + vR8)/(R1 + R2 + R3 + R4 + R5 + R6 + R7 + R8);
 
  return centroideR;
}




void motorL (long centroideL)
{
  long velocidad;
  if(centroideL >= 75)
  {
    velocidad = 75 - (centroideL-75) - 4; 
  }
  else 
  {
    velocidad = (75 - centroideL ) + 75 +4;
  }
    Serial.print(" Motor Izq: ");
    Serial.print(velocidad);
  analogWrite(3,255*velocidad/100.0 );
}

void motorR (long centroideR)
{
    long velocidad;
  if(centroideR>= 75)
  {
    velocidad = centroideR; 
  }
  else 
  {
    velocidad = centroideR;
  }
     Serial.print(" motor derecha: ");
    Serial.print(velocidad);
    Serial.println(" ");
  analogWrite(11, 255*velocidad/100.0 );
}

long andFnct(long a, long b, long c)
{
  long R= 0;
  if (a < b)
  { R = a; }
  else 
  { R = b; }
  
  if (R < c)
  { R = R; }
  else 
  { R =c; }
  
  return R;
}
