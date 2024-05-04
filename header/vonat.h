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
  int kocsidb;
  Ido indulas;
  Ido erkezes;


public:
  // Paraméter nélküli Konstruktor
  Vonat() : szam(0), indulo(""), veg(""), kocsidb(0), indulas(0,0), erkezes(0,0) {}

  // Paraméteres Konstruktor
  Vonat(int vszam, Allomas indulop, Allomas vegp, int kocsidb, Ido indulasp, Ido erkezesp)
        : szam(vszam), indulo(indulop), veg(vegp), kocsidb(kocsidb), indulas(indulasp), erkezes(erkezesp) {} 

  // Setterek
  void setSzam(int szam) { this->szam = szam; }
  void setIndulo(const char* indulo) { this-> indulo = Allomas(indulo);}
  void setVeg(const char* veg) { this->veg = Allomas(veg);}
  void setKocsidb(int kocsidb ) { this->kocsidb = kocsidb; }
  void setIndulas(const char* ido) { this->indulas = Ido(ido); }
  void setErkezes(const char* ido) { this->erkezes = Ido(ido); }

  // Getterek
  int getSzam() const { return szam; }
  Allomas getIndulo() const { return indulo; }
  Allomas getVeg() const { return veg; }
  int getKocsidb() const { return kocsidb; }
  Ido getIndulas() const { return indulas; }
  Ido getErkezes() const { return erkezes; }


  void kiir() const {
    std::cout << "Vonat szama: " << szam << std::endl;
    std::cout << "Indulasi allomas: " << indulo << std::endl;
    std::cout << "Erkezesi allomas: " << veg << std::endl;
    std::cout << "Kocsi darabszam: " << kocsidb << std::endl;
    std::cout << "Indulas idopontja: " << indulas << std::endl;
    std::cout << "Erkezes idopontja: " << erkezes << std::endl;
  }



  // Tagfüggvények 
  // void addTrain();
  
}; // end of VONAt


#endif // !VONAT_H 
