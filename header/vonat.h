#ifndef VONAT_H 
#define VONAT_H

#include <iostream>
/*
* VONATok LEÍRÁSA * 
*/

class Ido{
  int ora;
  int perc;
public:
  Ido(int ora, int perc) : ora(ora), perc(perc) {}

  int getOra();
  int getPerc();
  // std::ostream& operator<<(std:ostream& os ){ os << getOra() << ':' << getPerc << std::endl; }
}; // END OF IDO


class Allomas {
private:
  const char* allomasNev; // STRING type adás neki?? 
public:
  Allomas(const char* allomas) : allomasNev(allomas) {} 
}; // End of ALLOMAS


// Vonat->Ido aggregációban. Ido megszűnik ha vonat megszűnik.
class Vonat {
  int szam;
  Allomas indulo;
  // Allomas* koztes;
  Allomas veg;
  // Ido indulas;
  // Ido erkezes;
  int kocsidb;
public:
  // Konstruktor
  Vonat(int vszam, const char* indulop, const char* vegp, int kocsidb)
        : szam(vszam), indulo(indulop), veg(vegp), kocsidb(kocsidb) {} 
  // Setterek
  void setSzam(int szam = 0) { this->szam = szam; }
  // void setIndulo(char* indulo) { this-> indulo = Allomas(indulo);}
  // void setVeg(char* veg) { this->veg = Allomas(veg);}
  void setKocsidb(int szam = 0) { this->szam = szam; }

  // void addTrain();
  
}; // end of VONAt


#endif // VONAT_H 
