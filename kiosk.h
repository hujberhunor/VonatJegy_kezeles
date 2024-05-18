#ifndef KIOSK_H
#define KIOSK_H

/* 
* FILE KIOSK_H
*/

#include <iostream>

#include "mav.h"
#include "jegy.h"
#include <fstream>

/// Segéd "class" 
/// A menü kezelését könnyíti meg. 
enum menuItem{
  add,
  list,
  nyomtat,
  kilep
};

class Kiosk {
public:
  
  /// Hibakezelés. Érvényes input esetén @return true, különben @return false
  bool inputCheck();
  /// Inicializálja a menüt, ergo kiírja a lehetőségeket
  void init();
  /// Felhasználótól bemenetet kér. 
  /// @return menuItem fent említett enum class elemt ad vissza
  menuItem userInput();

  /// Liszázza a vonatokat amiket beolvasott a fájlból
  void listaz(Mav& mav);
  /// Hozzá ad a user vonatokat a fájlhoz
  void vonatHozza(Mav& mav, std::streampos currPos);
  /// jegyet vált a kiválasztott vonatra
  void jegyValt(Mav& mav);

}; // end of Kiosk






#endif // !KIOSK_H
