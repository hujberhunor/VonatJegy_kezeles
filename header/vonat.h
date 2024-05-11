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
  int szam; // Vonatszám 
  Allomas indulo; // Kiinduló állomas
  // Allomas* koztes;
  Allomas veg; // Végállomas
  int kocsidb; // Kocsik darabszáma, basically semmit sem csinál
  Ido indulas; // Indulási idő
  Ido erkezes; // Érkezési idp

public:
  // Paraméter nélküli Konstruktor
  Vonat() : szam(0), indulo(""), veg(""), kocsidb(0), indulas(0,0), erkezes(0,0) {}

  // Paraméteres Konstruktor
  Vonat(int vszam, Allomas indulop, Allomas vegp, int kocsidb, Ido indulasp, Ido erkezesp)
        : szam(vszam), indulo(indulop), veg(vegp), kocsidb(kocsidb), indulas(indulasp), erkezes(erkezesp) {} 

  // Setterek
  void setSzam(int szam)              { this->szam = szam; }
  void setIndulo(const char* indulo)  { this-> indulo = Allomas(indulo); }
  void setVeg(const char* veg)        { this->veg = Allomas(veg); }
  void setKocsidb(int kocsidb )       { this->kocsidb = kocsidb; }
  void setIndulas(const char* ido)    { this->indulas = Ido(ido); }
  void setErkezes(const char* ido)    { this->erkezes = Ido(ido); }

  // Getterek
  int getSzam() const       { return szam; }
  Allomas getIndulo() const { return indulo; }
  Allomas getVeg() const    { return veg; }
  int getKocsidb() const    { return kocsidb; }
  Ido getIndulas() const    { return indulas; }
  Ido getErkezes() const    { return erkezes; }

  // Kiírja a vonat adatait. 
  // A jegyhez használom
  void kiir() const {
    std::cout << "Vonat szama: " << szam << std::endl;
    std::cout << "Indulasi allomas: " << indulo << std::endl;
    std::cout << "Erkezesi allomas: " << veg << std::endl;
    std::cout << "Kocsi darabszam: " << kocsidb << std::endl;
    std::cout << "Indulas idopontja: " << std::setw(2) << std::setfill('0') 
              <<indulas.getOra() << ":" << indulas.getPerc() << std::endl; // Nagyon ronda, tudom...
    std::cout << "Erkezes idopontja: " << std::setw(2) << std::setfill('0') 
              <<erkezes.getOra() << ":" << erkezes.getPerc() << std::endl;
  }

  Vonat beolvas(std::streampos& currPos);
  void addTrain(std::streampos& currPos, int szam, Allomas indulo,
                Allomas veg, int kocsidb, Ido indulas, Ido erkezes);
  
}; // end of VONAt


#endif // !VONAT_H 
