#ifndef ALLOMASH_H
#define ALLOMASH_H

/* file ALLOMASH_H */

// STD::STRING-GEL MEGY A CUCCOKS

#include <iostream>
#include "./ido.h"

/** STRINGGEL ÚJRAÍRVA */
class Allomas{
private:
  std::string allomasNev; /// Allomas nevét tartalmazo string 
public:   
  /**
  * Allomas konstrukor
  * @param allomas itt egy char* egyértelműen. 
  * a másik verzióban const, hogy fel lehessen közvetlen tölteni
  * értsd: "Álloms_neve" mint paraméter.
  */
  Allomas(const char* allomas) : allomasNev(allomas) {}
  Allomas(char* allomas) : allomasNev(allomas) {}
  // Allomas(const std::string& allomas) : allomasNev(allomas) {}
  
  // Getterek
  std::string getAllomas() const { return allomasNev; }

}; // End of ALLOMAS
/// Allomas op<< overload
std::ostream& operator<<(std::ostream& os, const Allomas& allomas);

#endif // !ALLOMASH_H
