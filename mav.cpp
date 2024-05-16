#include "./mav.h"
#include "./seged.h"

// Magyarország leghosszabb településneve 15 karakter
// 25 karakterbe bele kell férnia
// Biztosítani lehetne, egy gyors checkel 
// és egy buffSize növeléssel, de nem láttam értelmét. 




/* VONATOK FILE BEOLVASÁSA */
// Beolvaásás a file-ból egy segéd strukturába, onnan pedig egy Vonat objektum feltöltés 
// @param Mav& mav class feltöltéséhez szükséges 
void Mav::beolvas() {
  // Inicalizálás
  const char* vonatok_file = "./vonatok.txt";    
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
      this->add(v); 
  }

  file.close();
} // END OF BEOLVAS


// Vonatok hozzáadása
// @param currPos a streamben elfoglalt helyem
// @param minden-más a vonat class feltöltéséhez szükséges adatok
void addTrain(std::streampos& currPos, int szam, Allomas indulo,
            Allomas veg, int kocsidb, Ido indulas, Ido erkezes){
  // Inicalizálás
  const char* vonatok = "./vonatok.txt";    
  std::ofstream file (vonatok, std::ios::app); 
 
  // HIBAKEZELÉS IDE

  if(file.is_open()){
    file.seekp(currPos); // Megfelelő helyre ugrok
    
    file << szam << " " << indulo << " " << veg << " " << kocsidb << " "
         << indulas << " " << erkezes << std::endl;
  }
  file.close();
} // END OF addTrain


