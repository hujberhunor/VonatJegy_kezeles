#ifndef IDO_H
#define IDO_H

/*
* FILE IDO_H
*/

#include <iostream>
#include <iomanip>


class Ido{
  int ora;
  int perc;
public:
  /**
  * Konstruktor
  * @param ido mivel beolvasáskor char* típusokba olvasok bele
  * char*-ot kap paraméterként és azt kezeli megfelelően konvertálva.
  */
  Ido(const char* ido) {
    ora = (ido[0] - '0') * 10 + (ido[1] - '0');
    perc = (ido[2] - '0') * 10 + (ido[3] - '0');
  }

  /**
  * Ido Konstruktor
  * @param ora (int)
  * @param perc (int)
  * Főképp tesztekhez volt használva. 
  */
  Ido(int ora, int perc) : ora(ora), perc(perc) {}

  // Getterek
  int getOra() const { return ora; };
  int getPerc() const {return perc; };

}; // END OF IDO

/// Ido class op<<() overwrireja, a fájlba beíráskor hívódik meg. (addTrain)
std::ostream& operator<<(std::ostream& os, const Ido& ido);



#endif // !IDO_H
