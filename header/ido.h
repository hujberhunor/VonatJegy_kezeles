#ifndef IDO_H
#define IDO_H

#include <iostream>
#include <iomanip>


class Ido{
  int ora;
  int perc;
public:
  // Ido(int ora = 0, int perc = 0) : ora(ora), perc(perc) {}
  Ido(const char* ido) {
    ora = (ido[0] - '0') * 10 + (ido[1] - '0');
    perc = (ido[2] - '0') * 10 + (ido[3] - '0');
  }

  Ido(int ora, int perc) : ora(ora), perc(perc) {}

  // Setter
  // void setIdo(char* ido){
  //   ora = (ido[0] - '0') * 10 + (ido[1] - '0');
  //   perc = (ido[2] - '0') * 10 + (ido[3] - '0');
  // }

  // Gettere
  int getOra() const { return ora; };
  int getPerc() const {return perc; };



}; // END OF IDO

std::ostream& operator<<(std::ostream& os, const Ido& ido){
  os << std::setw(2) << std::setfill('0') << ido.getOra();
  os << std::setw(2) << std::setfill('0') << ido.getPerc();
  return os;
} // operator<<()


#endif // !IDO_H
