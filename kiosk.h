#ifndef KIOSK_H
#define KIOSK_H

/* 
* FILE KIOSK_H
*/


#include <iostream>

enum menuItem{
  add,
  list,
  nyomtat,
  kilep
};

class Kiosk {
public:
  void init() {
    std::cout << "Dönts:" << std::endl;
    std::cout << "1. Vonat hozzáadása "     << std::endl;
    std::cout << "2. Vonatok listázása "    << std::endl;
    std::cout << "3. Jegy nyomtatása"       << std::endl;
    std::cout << "4. Kilépés"               << std::endl;
  }

  // User input az input streamről enum-má konvertálva
  menuItem userInput() {
     int valasz;
     std::cout << "Választott lehetőség: ";
     std::cin >> valasz;
     return static_cast<menuItem>(valasz);
  }

  // vonatHozzaad(Mav& mav){
  //   std::string input;
  //   std::cin >> input;
  //   mav.addTrain();
  //
  // }

}; // end of Kiosk






#endif // !KIOSK_H
