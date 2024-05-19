#ifndef JEGY_H
#define JEGY_H

/**
* FILE JEGY_H
*/

#include <iostream>
#include "./vonat.h"

class Jegy {
  int ar;           /// A jegy ára
  double szazalek;  /// Kedvezméy százaléka, pontosabban mennyi az amit fizet százalék.

public:
  /**
   * Anya osztály Konstruktora 
   * @param ar megadja a jegy árát
   * @param szazalek a kedvezmény értékét adja meg
   */
  Jegy(int ar = 1200, double szazalek = 0.7) : ar(ar), szazalek(szazalek)  {}

  /// Fizetendő összeg, ár és a kedvezmény szorzata
  virtual int fizetendo(){ return ar * szazalek; }

  /// Getterek
  int getAr() { return ar; }
  double getSzaz() { return szazalek; }

  /**
  * @param Vonat& megadott vonatra vonatkozik
  * Kíírja a jegy adatinak egy felét. Azt a felét ami minden leszármazottál
  * azonos. A felső pár so. 
  * virtual mivel a leszármazottak megöröklik és felülírják.
  */
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
   /**
   * Konstruktor
   * @param ar megadja a jegy árát
   * @param szazalek a kedvezmény értékét adja meg
   * Meghívja a anya-class konstruktorát.
  */
  Diak(int ar = 1200, const double szazalek = 0.7) : Jegy(ar, szazalek) {}
 
  /// Getterek
  std::string getTipus() { return tipusNev; }
  
  /// megörökölt nyomtat fv overwrite-ja 
  /// meghívja az "eredei", főosztály nyomtatját
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
  /**
   * Konstruktor
   * @param ar megadja a jegy árát
   * @param szazalek a kedvezmény értékét adja meg
   * Meghívja a anya-class konstruktorát.
  */
  Teljes(int ar = 1200, const double szazalek = 1.0) : Jegy(ar, szazalek) {}
  
  std::string getTipus() { return tipusNev; }
  
  /// megörökölt nyomtat fv overwrite-ja 
  /// meghívja az "eredei", főosztály nyomtatját
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
  /**
   * Konstruktor
   * @param ar megadja a jegy árát
   * @param szazalek a kedvezmény értékét adja meg
   * Meghívja a anya-class konstruktorát.
  */
  Kutya(int ar = 1200, const double szazalek = 0.2) : Jegy(ar, szazalek) {}
  
  // Getterek
  std::string getTipus() { return tipusNev; }
  std::string getKov() { return kov; }

  /// megörökölt nyomtat fv overwrite-ja 
  /// meghívja az "eredei", főosztály nyomtatját
  void nyomtat(Vonat &v) {
    std::cout << "### Jegy adatai ###\n";
    std::cout << "Jegy típusa: " << getTipus() << std::endl;
    std::cout << "Követelmény: " << getKov() << std::endl;
    Jegy::nyomtat(v);
  }

}; // end of Kutya


#endif // !JEGY_H
