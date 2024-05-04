#ifndef JEGY_H
#define JEGY_H

#include <iostream>

/* BASICALLY EGY STRUCT */
class Jegy {
public:
  int vonatSzama;
  Allomas honnan;
  Allomas hova;
  Ido indul;
  Ido erkezik;
  int ar;
  int szazalek;

  virtual int ar();
  void printJegy() const;
  int getAr();
};

/* WHAT IF ÍROK EGY TEMPLATE CLASS-T A KEDVEZMÉNYESEKRE */
class Diák : public Jegy{
private:
  std::string tipus;
  int kedvezmeny; // Kedvezmény szazaleka
  
public: 
  int getKedv() { return kedvezmeny; }
  int ar(){ return ar * kedvezmeny; }
};




#endif // !JEGY_H
