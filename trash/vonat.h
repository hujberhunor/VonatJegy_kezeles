#ifndef VONAT_H 
#define VONAT_H

/*
* VONATok LEÍRÁSA * 
*/
#include <iostream>
#include "./header/string5.h"

// 50db ülés / kocsi
static const ulesdb = 50;

class Allomas {
public:
  char* allomasNev;
}; // Endo of ALLOMAS


class Ido{
  int ora;
  int perc;
public:
  int getOra();
  int getPerc();
}; // END OF IDO

class Vonat {
public:
  int szam;
  Allomas indulo;
  Allomas veg;
  // Ido indulas;
  // Ido erkezes;
  int kocsidb;

  // void addTrain();
}; // end of VONAt













#endif // VONAT_H 
