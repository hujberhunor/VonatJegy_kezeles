#ifndef SEGED_H
#define SEGED_H

#include <iostream>
#include <fstream>

#include "./allomas.h"
#include "./ido.h"
#include "./jegy.h"
#include "./kiosk.h"
#include "./mav.h"
#include "./seged.h"
#include "./vonat.h"


struct Seged {
   static const int buffSize = 25;
   char szam[buffSize];
   char indulo[buffSize];
   char veg[buffSize];
   char kocsidb[buffSize];
   char indulas[buffSize];
   char erkezes[buffSize];
};



#endif // !SEGED_H

