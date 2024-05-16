#ifndef MAV_H
#define MAV_H

/*
 * FILE MAV_H
 */

#include <iostream>
#include <fstream>

#include "./vonat.h"
// #include "./allomas.h"
// #include "./ido.h"

/* ### TODO ### 
  * Túlidenxelés kezelés
  * Ha a file nem létezik ne dobjon seg faultot
*/
  
class Mav {
  // HELYET KELL FOGLALNI NEKI!!
  Vonat* vonatok; // Vonatok kollekció
  size_t si;      // Vonatok kollekció mérete db számban
  
public:
  // Konstruktor
  Mav(size_t si = 0) : vonatok(nullptr), si(si) {} 
  
  // Új elem hozzáadása a mav kollekcióhoz
  void add(Vonat& vonat){
    Vonat* temp = new Vonat[si + 1];  // Lefoglalok helyet 
   
    for (size_t i = 0; i < si; ++i) { // Átmásolom a tömb elemeit
      temp[i] = vonatok[i];
    }
    temp[si++] = vonat;               // Beleteszem a vonatot
   
    delete[] vonatok;                   // "Régi" tömböt törlöm
    vonatok = temp;                     //
  } // End of feltolt

  // Vonatok tömb kiírása
  void kiir() {
    for (size_t i = 0; i < si; ++i) {
      std::cout << "---" << i+1 << ". vonat---" << std::endl;
        vonatok[i].kiir();
        std::cout << std::endl;
    }
  } // end of kiir
 
  // i.edik elem kiírása
  void kiirAt(int i){
    // HIBAEKEZELÉS
    std::cout << i+1 <<".vonat" << std::endl;
    vonatok[i].kiir();
  } // end of kiirAt

  Vonat& getVonatAt(int i){ return vonatok[i]; }

  Vonat& operator[](int idx){ return vonatok[idx]; }
 
  void beolvas();
  void addTrain(std::streampos& currPos, int szam, Allomas indulo,
                Allomas veg, int kocsidb, Ido indulas, Ido erkezes);

  // Destruktor
  ~Mav(){
    delete[] vonatok;
  }


}; // END OF MAV




#endif // !MAV_H

