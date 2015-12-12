
#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"


#define CM 1
#define INC 0

class Ultrasonic
{
  public:
    Ultrasonic(int TP, int EP);
    long Timing();
    long Ranging();
    long RangeFinder();
    long RangeFinderPulse();

    private:
    int Trig_pin;
    int Echo_pin;
    long  duration,distacne_cm,distance_inc, distance_RF, pwPin;
    
};

#endif
