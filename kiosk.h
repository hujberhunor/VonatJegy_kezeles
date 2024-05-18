#ifndef KIOSK_H
#define KIOSK_H

/* 
* FILE KIOSK_H
*/

#include <iostream>

#include "mav.h"
#include "jegy.h"
#include <fstream>


enum menuItem{
  add,
  list,
  nyomtat,
  kilep
};

class Kiosk {
public:

  void init();
  menuItem userInput();

  void listaz(Mav& mav);
  void vonatHozza(Mav& mav, std::streampos currPos);
  void jegyValt(Mav& mav);

}; // end of Kiosk






#endif // !KIOSK_H
