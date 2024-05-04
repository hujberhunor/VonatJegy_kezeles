#ifndef JEGY_H
#define JEGY_H

#include <iostream>

/* BASICALLY EGY STRUCT */
class Jegy : private Vonat {
public:
  int ar;
  int szazalek;

  virtual int ar();
  virtual void printJegy() const;
  virtual int getAr();
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
