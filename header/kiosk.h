#ifndef KIOSK_H
#define KIOSK_H

#include <iostream>

enum menuItem{
  add,
  list,
  nyomtat,
  kilep
};

class Kiosk {
public:
  void setup() {
    std::cout << "Dönts:" << std::endl;
    std::cout << "1. Vonat hozzáadása "     << std::endl;
    std::cout << "2. Vonatok listázása "    << std::endl;
    std::cout << "3. Jegy nyomtatása"       << std::endl;
    std::cout << "4. Kilépés"               << std::endl;
  }

 menuItem userInput() {
     int valasz;
     std::cout << "Választott lehetőség: ";
     std::cin >> valasz;
     return choice - 1;
 }

}; // end of Kiosk

int main() {
    Menu menu;
    MenuItem choice = add; // inicializalom

    while (choice != kilep) {
        menu.display();
        choice = menu.getUserChoice();

        switch (choice) {
            case ITEM_1:
                std::cout << "Add meg az adatokat: " << std::endl;
                break;
            case ITEM_2:
                std::cout << "Vonatok listázása" << std::endl;
                break;
            case ITEM_3:
                std::cout << "Nyomtassunk!" << std::endl;
                break;
            case EXIT:
                std::cout << "Kilépés a programból." << std::endl;
                break;
            default:
                std::cout << "Érvénytelen választás!" << std::endl;
                break;
        }
    }

    return 0;
}
}// end of main





















#endif // !KIOSK_H
