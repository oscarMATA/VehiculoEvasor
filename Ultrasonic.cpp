
#include "Arduino.h"

#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int TP, int EP)
{
   pinMode(TP,OUTPUT);
   pinMode(EP,INPUT);
   Trig_pin=TP;
   Echo_pin=EP;
   pwPin = EP;
}


long Ultrasonic::Timing()
{
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin,HIGH);
  return duration;
}

long Ultrasonic::Ranging()
{
  distacne_cm = Timing() / 59 ;
  return distacne_cm;
}

long Ultrasonic::RangeFinder()
{
  distance_RF = pulseIn(pwPin, HIGH);
  distance_RF = distance_RF/54;
  
  return distance_RF;
}
