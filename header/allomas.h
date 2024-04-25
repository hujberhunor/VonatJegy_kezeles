#ifndef ALLOMASH_H
#define ALLOMASH_H

/* file ALLOMASH_H */

#include <iostream>
#include "./string5.h"
#include "./ido.h"

// class Allomas {
// private:
//   const char* allomasNev; // STRING type adás neki?? 
// public:
//   Allomas() : allomasNev(nullptr) {}
//   Allomas(const char* allomas) : allomasNev(allomas) {} 
//
//   // Getterek
//   const char* getAllomas() const { return allomasNev; }
//
// }; // End of ALLOMAS
// // Allomas op<< overload
// std::ostream& operator<<(std::ostream& os, const Allomas& allomas) { return os << allomas.getAllomas(); }
//
// --- // 

/* STRINGGEL ÚJRAÍRVA */
class Allomas{
private:
  String allomasNev;  
public:    
  Allomas(const char* allomas) : allomasNev(allomas) {}
  Allomas(const String& allomas) : allomasNev(allomas) {}
  
  // Getterek
  String getAllomas() const { return allomasNev; }

}; // End of ALLOMAS
// Allomas op<< overload
std::ostream& operator<<(std::ostream& os, const Allomas& allomas) { return os << allomas.getAllomas(); } 

#endif // !ALLOMASH_H
