#include "./test.h"

#include "./mav.h"
#include "./vonat.h"
#include "./allomas.h"
#include "./jegy.h" 
#include "./kiosk.h"

#include <iostream>

int main(){
  // Itt tárolon hol vagyok a file-ban
  // Mind a beolvasás mind pedig az íráshoz KELL!
  std::streampos currPos;
  Mav mav;
  mav.beolvas();

  Kiosk k; // kiosk inicalizálása
  k.init(); // Kiírja a lehetőségeket
  
  int choice = 0;
  while (choice != 4) {
    choice = k.userInput(); 
    switch (choice) {

      // Vonat hozzáadása
      case 1: {
        std::cout << "Beolvas: " << std::endl;
        std::cout << "Szám Indulo Vég kocsidb Indulás erkezes" << std::endl;
        k.vonatHozza(mav, currPos);
        // system("clear"); // Tábla törlés, nem ette meg a JPORTA 
        std::cout << "\n" << "Vonat hozzáadva\n\n";
        mav.beolvas();
        k.init(); // Kiírja a lehetőségeket
        break;
      }

      // Vonatok listázása
      case 2: { 
        std::cout << std::endl;
        mav.beolvas();
        k.listaz(mav);
        std::cout << std::endl;
        k.init(); // Kiírja a lehetőségeket
        break;
      }

      // Jegy vásárlás
      case 3: {
        std::cout << std::endl; 
        k.jegyValt(mav);
        std::cout << std::endl;
        k.init(); // Kiírja a lehetőségeket
        break;
      }

      // Kilépés
      case 4: {
        std::cout << "Kilépés" << std::endl;
        break;
      }

      // TEST case
      case 5:{
        std::cout << "Teszt futtatása" << std::endl;
        mav_test();
        vonat_test();
        k.init();
      }

      default: {
        // std::cout << "Érvénytelen lehetőség" << std::endl;
        // Hibakezelés
        if(!(k.inputCheck())) { std::cout << std::endl; k.init(); }
      }

    } // end of switch
  } // end of while

  
  return 0;
} // end of main
