#ifndef JEGY_H
#define JEGY_H

#include <iostream>
#include "./vonat.h"

// Jegy minden elemét tartalmazza a vonatnak, hiszen mindet ki is kell írnom. 
class Jegy : private Vonat {
  int ar;
  int szazalek;

public:
  Jegy(int ar = 0, int szazalek = 0) : ar(ar), szazalek(szazalek)  {}

  virtual int fizetendo(){ return ar * szazalek; }

  virtual void nyomtat(Vonat& v){
    std::cout << "### Jegy ###\n";
    std::cout << "--- Vonatod adatai ---" << std::endl;
    v.kiir(); 
    std::cout << "--- Mocskos pénzügyek ---" << std::endl;
    std::cout << "Ár: "<< ar << std::endl;
    std::cout << "Százalék: " << szazalek << std::endl;
    std::cout << "Fizetendő: " << fizetendo() << std::endl;
    std::cout << "--- Vonalkód ---" << std::endl;
    std::cout << "||| | || | || |  |" << std::endl;
  }
 
}; // END OF JEGY class



#endif // !JEGY_H
