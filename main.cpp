#include <iostream>

#include "./mav.h"
// #include "./vonat.h"
// #include "./allomas.h"
#include "./jegy.h" 
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
  // mav.kiirAt(1);

   mav.getVonatAt(3);

  /* JEGY */
  // Diak d1(1000, 0.7, "Diak");
  Diak d1;
  d1.nyomtat(mav.getVonatAt(1));

  Teljes t1;
  t1.nyomtat(mav.getVonatAt(3));

  Kutya k1;
  k1.nyomtat(mav.getVonatAt(1));

  /* KIOSK TEST */
  // Kiosk k;
  // k.init();
  //
  // switch (k.userInput()) {
  //   case 1: std::cout << "Vonat hozzáadása: "; break;
  //   case 2: std::cout << "2"; break;
  //   default: std::cout << "Default";
  // } // end of switch


  
  return 0;
}
