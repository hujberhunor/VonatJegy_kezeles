#include <iostream>

#include "./mav.h"
// #include "./vonat.h"
// #include "./allomas.h"
// #include "./jegy.h"# 
#include "kiosk.h"

int main(){
  // Itt tárolon hol vagyok a file-ban
  // Mind a beolvasás mind pedig az íráshoz KELL!
 
  /* FÁJL BEOLVASÁS */
  std::streampos currPos;
  Mav mav;
  // addTrain(currPos, 80, "Faszomból", "Geci", 5, "0440", "0630");
  mav.beolvas();
  // mav.kiir(); //Összes vonat listázása indexekkel!
  mav.kiirAt(3);



  /* JEGY */
  // Jegy j1(100, 400);
  // j1.nyomtat(v);



  /* KIOSK TEST */
  Kiosk k;
  k.init();

  switch (k.userInput()) {
    case 1: std::cout << "Vonat hozzáadása: "; break;
    case 2: std::cout << "2"; break;
    default: std::cout << "Default";
  } // end of switch

  
  
  return 0;
}
