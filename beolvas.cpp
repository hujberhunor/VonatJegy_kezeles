#include <iostream>
#include <fstream>

#include "./header/mav.h"
#include "./header/vonat.h"
#include "./header/allomas.h"
#include "./header/jegy.h"


/* 
 * FILE BEOLVAS.CPP
 */


// Magyarország leghosszabb településneve 15 karakter
// 25 karakterbe bele kell férnia
// Biztosítani lehetne, egy gyors checkel 
// és egy buffSize növeléssel, de nem láttam értelmét. 
static const int buffSize = 25;
struct Seged {
  char szam[buffSize];
  char indulo[buffSize];
  char veg[buffSize];
  char kocsidb[buffSize];
  char indulas[buffSize];
  char erkezes[buffSize];
};


/* VONATOK FILE BEOLVASÁSA */
// Beolvaásás a file-ból egy segéd strukturába, onnan pedig egy Vonat objektum feltöltés 
// @param Mav& mav class feltöltéséhez szükséges 
void beolvas(Mav& mav) {
  // Inicalizálás
  const char* vonatok_file = "./input/vonatok.txt";    
  std::ifstream file(vonatok_file);
  Vonat v;
  Seged seged;

  // HIBAKEZELÉS IDE
 
  while (file >> seged.szam >> seged.indulo >> seged.veg >> seged.kocsidb >> seged.indulas >> seged.erkezes) {
      v.setSzam(std::atoi(seged.szam));
      v.setIndulo(seged.indulo);
      v.setVeg(seged.veg);
      v.setKocsidb(std::atoi(seged.kocsidb));
      v.setIndulas(seged.indulas);
      v.setErkezes(seged.erkezes);
      
      // feltöltöm a MAV "mgmt" class Vonat* tömbjét 
      mav.add(v); 
  }

  file.close();
} // END OF BEOLVAS


// Vonatok hozzáadása
// @param currPos a streamben elfoglalt helyem
// @param minden-más a vonat class feltöltéséhez szükséges adatok
void addTrain(std::streampos& currPos, int szam, Allomas indulo,
            Allomas veg, int kocsidb, Ido indulas, Ido erkezes){
  // Inicalizálás
  const char* vonatok = "./input/vonatok.txt";    
  std::ofstream file (vonatok, std::ios::app); 
 
  // HIBAKEZELÉS IDE

  if(file.is_open()){
    file.seekp(currPos); // Megfelelő helyre ugrok
    
    file << szam << " " << indulo << " " << veg << " " << kocsidb << " "
         << indulas << " " << erkezes << std::endl;
  }
  file.close();
} // END OF addTrain


int main(){
  // Itt tárolon hol vagyok a file-ban
  // Mind a beolvasás mind pedig az íráshoz KELL!
  std::streampos currPos;
  Mav mav;
 
  // addTrain(currPos, 69, "Ecséd", "Bivalybaszod", 5, "0440", "0630");
  //   addTrain(currPos, 80, "Geci", "Nem-geci", 5, "0440", "0630");
  beolvas(mav);

  mav.kiir();
  mav.kiirAt(3);

  // Jegy j1(100, 400);
  // j1.nyomtat(v);
  
  
  return 0;
}
