#include "./ido.h"

std::ostream& operator<<(std::ostream& os, const Ido& ido){
  os << std::setw(2) << std::setfill('0') << ido.getOra();
  os << std::setw(2) << std::setfill('0') << ido.getPerc();
  return os;
} // operator<<()
