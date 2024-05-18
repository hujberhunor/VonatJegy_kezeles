#ifndef JEGY_H
#define JEGY_H

/* 
* FILE JEGY_H
*/

#include <iostream>
#include "./vonat.h"

class Jegy {
  int ar;
  double szazalek;

public:
  // Konstruktor
  Jegy(int ar = 1200, double szazalek = 0.7) : ar(ar), szazalek(szazalek)  {}

  // Mennyi az aktuális összeg
  virtual int fizetendo(){ return ar * szazalek; }

  // Getterek
  int getAr() { return ar; }
  double getSzaz() { return szazalek; }

  // Jegy printelése
  virtual void nyomtat(Vonat& v) {
    std::cout << "Fizetendő: " << fizetendo() << "JMF\n";
    std::cout << "### Vonatod adatai ###" << std::endl;
    v.kiir();
    std::cout << std::endl;
  }
  // virtual void abstract() = 0 {} 

}; // END OF JEGY 



class Diak : public Jegy {
  const std::string tipusNev = "Diák";
  // const double szazalek = 0.7;

public:
  // Konstruktor
  Diak(int ar = 1200, const double szazalek = 0.7) : Jegy(ar, szazalek) {}
 
  // Getterek
  std::string getTipus() { return tipusNev; }
 
  void nyomtat(Vonat &v) {
    std::cout << "### Jegy adatai ###\n";
    std::cout << "Jegy típusa: " << getTipus() << std::endl;
    Jegy::nyomtat(v);
  }

}; // end of diak


class Teljes : public Jegy {
  const std::string tipusNev = "Teljes";
  // const double szazalek = 1.0;

public:
  Teljes(int ar = 1200, const double szazalek = 1.0) : Jegy(ar, szazalek) {}
  
  std::string getTipus() { return tipusNev; }
  
  void nyomtat(Vonat &v) {
    std::cout << "### Jegy adatai ###\n";
    std::cout << "Jegy típusa: " << getTipus() << std::endl;
    Jegy::nyomtat(v);
  }

}; // end of Teljes


class Kutya : public Jegy {
  const std::string tipusNev = "Kutya";
  const std::string kov = "Szájkosár";

public:
  Kutya(int ar = 1200, const double szazalek = 0.2) : Jegy(ar, szazalek) {}
  
  // Getterek
  std::string getTipus() { return tipusNev; }
  std::string getKov() { return kov; }
 
  // 
  void nyomtat(Vonat &v) {
    std::cout << "### Jegy adatai ###\n";
    std::cout << "Jegy típusa: " << getTipus() << std::endl;
    std::cout << "Követelmény: " << getKov() << std::endl;
    Jegy::nyomtat(v);
  }

}; // end of Kutya


#endif // !JEGY_H
