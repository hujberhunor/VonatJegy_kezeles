#ifndef MAV_H
#define MAV_H

/*
 * FILE MAV_H
 */

#include <iostream>
#include <fstream>

#include "./vonat.h"
#include "./allomas.h"
#include "./ido.h"

  
class Mav {
  Vonat* vonatok; // Vonatok kollekció
  size_t si;      // Vonatok kollekció mérete db számban
  
public:
  // Konstruktor
  Mav(size_t si = 0) : vonatok(nullptr), si(si) {} 
 
  /**
   * Elem hozzáfűzése Vonatok kollekcióhoz
   * @param vonat vonat referencia amit hozzáad
   */
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
      std::cout << "--- " << i+1 << ".vonat ---" << std::endl;
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

  Vonat& getVonatAt(int i){ return vonatok[i-1]; }
  size_t getSize() { return static_cast<int>(si); }


  /**
 * Beolvaásás a file-ból egy segéd strukturába, onnan pedig egy Vonat objektum feltöltés 
 * @param Mav& mav class feltöltéséhez szükséges 
 */ 
  void beolvas();

  /**
 * Mav beolvas overwrite 
 * Csak a teszt miatt kell, meg kell tudnom neki adni egy 
 * teszt vonatok.txt-t 
 * @param file file path (const char*)
 */
  void beolvas(const char* file);

/*
 * Vonatok hozzáadása
 * @param currPos a streamben elfoglalt helyem
 * @param minden-más a vonat class feltöltéséhez szükséges adatok
*/
  void addTrain(std::streampos& currPos, int szam, Allomas indulo,
                Allomas veg, int kocsidb, Ido indulas, Ido erkezes);


  /**
* addTrain() teszt miatti overwriteja
* Csak abban különbözik, hogy a fájl amit megnyit nem a hard coded
* hanem a test file
  */
  void addTrain(std::streampos& currPos, const char* test, int szam, Allomas indulo, 
                     Allomas veg, int kocsidb, Ido indulas, Ido erkezes);

  /// op[] overload
  Vonat& operator[](int idx){ return vonatok[idx]; }
  
  /// Destruktor
  ~Mav(){
    delete[] vonatok;
  }

}; // END OF MAV




#endif // !MAV_H

