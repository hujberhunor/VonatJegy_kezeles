#ifndef MAV_H
#define MAV_H

#include <iostream>

// #include "./vonat.h"
#include "./allomas.h"
#include "./ido.h"
/* ### TODO ### 
  * Túlidenxelés kezelés
  * Ha a file nem létezik ne dobjon seg faultot
*/
  
class Mav {
  // HELYET KELL FOGLALNI NEKI!!
  Vonat* vonatok; // Vonatok kollekció
  size_t size;    // Vonatok kollekció mérete db számban
  
public:
  // Konstruktor
  Mav(size_t size = 0) : vonatok(nullptr), size(size) {} 
 
  void add(Vonat& vonat){
    Vonat* temp = new Vonat[size + 1];  // Lefoglalok helyet 
    for (size_t i = 0; i < size; ++i) { // Átmásolom a tömb elemeit
      temp[i] = vonatok[i];
    }
    temp[size++] = vonat;
    delete[] vonatok;
    vonatok = temp;
  } // End of feltolt

  // Vonatok tömb kiírása
  void kiir() {
    for (size_t i = 0; i < size; ++i) {
        vonatok[i].kiir();
        std::cout << std::endl;
    }
  } // end of kiir
 
  // i.edik elem kiírása
  void kiirAt(int i){
    std::cout << i <<". vonat" << std::endl;
    vonatok[i].kiir();
  } // end of kiirAt


  Vonat operator[](int idx){ return vonatok[idx]; }

}; // END OF MAv




#endif // !MAV_H

