
#include "kiosk.h"
#include "jegy.h"
#include "./seged.h"

#include "./mav.h"
#include "./vonat.h"
#include "allomas.h"
#include "ido.h"

#include <fstream>
#include <limits>

/// Hibakezelés. Érvényes input esetén @return true, különben @return false
bool Kiosk::inputCheck(){
  // Kb innen lopva https://stackoverflow.com/questions/12721911/c-how-to-verify-if-the-data-input-is-of-the-correct-datatype
  if (std::cin.fail()) {
        std::cout << "Nem sikerült érvényes inputot megadni... PRÓBÁLD ÚJRA" << std::endl;
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
  }
  else return true;
}

/// Inicializálja a menüt, ergo kiírja a lehetőségeket
void Kiosk::init() {
  std::cout << "### Dönts ###" << std::endl;
  std::cout << "1. Vonat hozzáadása "     << std::endl;
  std::cout << "2. Vonatok listázása "    << std::endl;
  std::cout << "3. Jegy nyomtatása"       << std::endl;
  std::cout << "4. Kilépés"               << std::endl;
  std::cout << "5. Teszt"                 << std::endl;
}

/// Felhasználótól bemenetet kér. 
/// @return menuItem fent említett enum class elemt ad vissza
// User input az input streamről enum-má konvertálva
menuItem Kiosk::userInput() {
   int valasz;
   std::cout << "Választott lehetőség: ";
   std::cin >> valasz;
   return static_cast<menuItem>(valasz);
}

/// Liszázza az összes vonatot
void Kiosk::listaz(Mav& mav){
  mav.kiir(); 
}

/**
* User hozzáadhat vonatot a file-hoz
* @param mav a mav osztályra refereancia, ezt töltöm fel (Mav)
* @param currpos a kurzor éppenleges helye, ahova írni kell, hogy 
* ne legyen felülírás (streampos)
*/
void Kiosk::vonatHozza(Mav& mav, std::streampos currPos){
  Seged s;

  std::cin >> s.szam; 
  // if(*(s.szam) == '\n') std::cout << "FASZ";
  std::cin >> s.indulo; 
  std::cin >> s.veg; 
  std::cin >> s.kocsidb; 
  std::cin >> s.indulas; 
  std::cin >> s.erkezes; 
    
  mav.addTrain(currPos, atoi(s.szam), Allomas(s.indulo), Allomas(s.veg),
                    atoi(s.kocsidb), Ido(s.indulas), Ido(s.erkezes));
} // End of vonatHozza

/** 
* Jegy vásárlás, nyomtatás
* @param mav mav refereancia, ez az osztály tartalmazza a vonatok* tömböt
*/
void Kiosk::jegyValt(Mav& mav){
  int idx, buf;
  listaz(mav);
  std::cout << "Valasz vonatot: ";
  std::cin >> idx;
  // Hibakezelés
  if(size_t(idx) > mav.getSize()){ std::cout << "Túlindexelés\n"; return; }
  
  if(!(Kiosk::inputCheck())) return; // Érvényes inputot szűrök. 
  
  std::cout << std::endl; // szép kíírás miatt. 
  // end if Hibakezelés  


  std::cout << "1.Teljes, 2.Diak, 3.Kutya\n ";
  std::cin >> buf;
  // Hibakezelés
  if(buf > 3){ std::cout << "Túlindexelés"; return; }

  if(!(Kiosk::inputCheck())) return; 
 
  std::cout << std::endl;
  // end of Hibakezelés

  switch (buf) {
    case 1: {
      Teljes t;
      t.nyomtat(mav.getVonatAt(idx));
      break;
    }

    case 2: {
      Diak d;
      d.nyomtat(mav.getVonatAt(idx));
      break;
    }

    case 3: {
      Kutya k;
      k.nyomtat(mav.getVonatAt(idx));
      break;
    }
      
  } // end of switch

} // end of jegyValt







