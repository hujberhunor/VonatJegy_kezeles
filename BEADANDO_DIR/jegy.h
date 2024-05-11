#ifndef JEGY_H
#define JEGY_H

#include <iostream>

/* BASICALLY EGY STRUCT */
class Jegy : private Vonat {
  int ar;
  int szazalek;

public:
  virtual int ar(){
    return ar * szazalek;
  }

  virtual void printJegy(Vonat v) const{
    v.kiir(); 
    std::cout << "Ár "<< ar;
    std::cout << "Százalék " << szazalek;
  }

  virtual int getAr();
}; // END OF JEGY class





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
