#ifndef ALLOMASH_H
#define ALLOMASH_H

/* file ALLOMASH_H */

#include <iostream>
#include "./string5.h"


class Allomas {
private:
  const char* allomasNev; // STRING type adás neki?? 
public:
  Allomas() : allomasNev(nullptr) {}
  Allomas(const char* allomas) : allomasNev(allomas) {} 

  // Getterek
  const char* getAllomas() const { return allomasNev; }

}; // End of ALLOMAS
// Allomas op<< overload
std::ostream& operator<<(std::ostream& os, const Allomas& allomas) { return os << allomas.getAllomas(); }

// --- // 

class Ido{
  int ora;
  int perc;
public:
  Ido(int ora, int perc) : ora(ora), perc(perc) {}

  // Gettere
  int getOra();
  int getPerc();

}; // END OF IDO
// Globális tgf  
// std::ostream& operator<<(std:ostream& os ){ os << getOra() << ':' << getPerc << std::endl; }



#endif // !ALLOMASH_H
