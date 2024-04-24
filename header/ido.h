#ifndef IDO_H
#define IDO_H

#include <iostream>

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

#endif // !IDO_H
