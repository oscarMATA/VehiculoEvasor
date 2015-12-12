#ifndef control_h
#define control_h

#include "Arduino.h"

#define cercaRL_1  15
#define cercaRL_2  25
#define lejosRL_1  15
#define lejosRL_2  25

#define cercaF_1 20
#define cercaF_2 35
#define lejosF_1 20
#define lejosF_2 35

#define ADELANTE 85
#define ATRAS 55


long evaluacionCercaRL (long distance);
long evaluacionLejosRL (long distance);
long evaluacionCercaF (long distance);
long evaluacionLejosF (long distance);
long evaluacionReglasL (long cercaR, long cercaL, long cercaF, long lejosR, long lejosL, long lejosF);
long evaluacionReglasR (long cercaR, long cercaL, long cercaF, long lejosR, long lejosL, long lejosF);
void motorL (long velocidad);
void motorR (long velocidad);

long andFnct(long a, long b, long c);



#endif
