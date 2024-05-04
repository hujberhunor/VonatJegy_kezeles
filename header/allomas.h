#ifndef ALLOMASH_H
#define ALLOMASH_H

/* file ALLOMASH_H */

// STD::STRING-GEL MEGY A CUCCOKS

#include <iostream>
#include "./ido.h"

/* STRINGGEL ÚJRAÍRVA */
class Allomas{
private:
  std::string allomasNev;  
public:    
  Allomas(const char* allomas) : allomasNev(allomas) {}
  Allomas(char* allomas) : allomasNev(allomas) {}
  // Allomas(const std::string& allomas) : allomasNev(allomas) {}
  
  // Getterek
  std::string getAllomas() const { return allomasNev; }

}; // End of ALLOMAS
// Allomas op<< overload
std::ostream& operator<<(std::ostream& os, const Allomas& allomas) { return os << allomas.getAllomas(); } 

#endif // !ALLOMASH_H
