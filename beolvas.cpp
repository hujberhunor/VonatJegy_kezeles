#include <iostream>
#include <fstream>

#include "./header/vonat.h"
#include "./header/allomas.h"

static const int buffSize = 15;

struct Seged {
  char szam[buffSize];
  char indulo[buffSize];
  char veg[buffSize];
  char kocsidb[buffSize];
};

/* VONATOK FILE BEOLVASÁSA */
// Beolvaásás a file-ból 
// @param int& currPos a kurzor éppenleges helyzete a fileban. 
Vonat beolvas(int& currPos, Vonat& v){
    const char* vonatok = "./input/vonatok.txt";    // const mert megadtam, hogy hol van és ehhez nem nyúlsz hozzá
    std::ifstream file (vonatok);                   // Megynitom a file-t
    // Vonat v;

    if (file.is_open() ){ 
      // Fájl beolvasása egy segéd struktúrába 
      Seged seged;
      file >> seged.szam >> seged.indulo >> seged.veg >> seged.kocsidb;
     
      // Setterek, mert a konstruktor nem akarja megenni
      v.setSzam(atoi(seged.szam));
      v.setIndulo(seged.indulo);
      v.setVeg(seged.veg);
      v.setKocsidb(atoi(seged.kocsidb));

    } // end of if

  file.close();
  return v; 
} // end of beolvas

int main(){
  // Itt tárolon hol vagyok a file-ban
  // Mind a beolvasás mind pedig az íráshoz KELL!
  int currPos = 0;
  Vonat v;

  beolvas(currPos, v);

  std::cout << v.getSzam() << std::endl ;
  std::cout << v.getIndulo() << std::endl ;
  std::cout << v.getVeg() << std::endl ;
  std::cout << v.getKocsidb() << std::endl ;

  return 0;
}
