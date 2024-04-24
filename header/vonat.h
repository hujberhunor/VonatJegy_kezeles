#ifndef VONAT_H 
#define VONAT_H

/*
 * file VONAT_H
*/
#include <iostream>
#include "./allomas.h"
#include "./ido.h"


class Vonat {
private: 
  int szam;
  Allomas indulo;
  // Allomas* koztes;
  Allomas veg;
  // Ido indulas;
  // Ido erkezes;
  int kocsidb;

public:
  // Paraméter nélküli Konstruktor
  Vonat() : szam(0), indulo(nullptr), veg(nullptr), kocsidb(0) {}

  // Paraméteres Konstruktor
  Vonat(int vszam, Allomas indulop, Allomas vegp, int kocsidb)
        : szam(vszam), indulo(indulop), veg(vegp), kocsidb(kocsidb) {} 

  // Setterek
  void setSzam(int szam = 0) { this->szam = szam; }
  void setIndulo(const char* indulo) { this-> indulo = Allomas(indulo);}
  void setVeg(const char* veg) { this->veg = Allomas(veg);}
  void setKocsidb(int szam = 0) { this->szam = szam; }

  // Getterek
  int getSzam() const { return szam; }
  Allomas getIndulo() const { return indulo; }
  Allomas getVeg() const { return veg; }
  int getKocsidb() const { return kocsidb; }

  // Tagfüggvények 
  // void addTrain();
  
}; // end of VONAt


#endif // !VONAT_H 
