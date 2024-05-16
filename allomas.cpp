#include "./allomas.h"

// Másképp nem ette meg a compiler. 
std::ostream& operator<<(std::ostream& os, const Allomas& allomas) { return os << allomas.getAllomas(); } 
