#include <iostream>
#include <fstream>

#include "./header/vonat.h"
#include "./header/allomas.h"
#include "./header/jegy.h"
#include "./header/mav.h"


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
// @param int& currPos a kurzor éppenleges helyzete a fileban. 
// @param Mav& mav class feltöltéséhez szükséges 
// @return visszaad egy feltöltött Vonat objektumot
Vonat beolvas(std::streampos& currPos, Mav& mav){
    const char* vonatok = "./input/vonatok.txt";    // const mert megadtam, hogy hol van és ehhez nem nyúlsz hozzá
    std::ifstream file (vonatok);                   // Megynitom a file-t
    Vonat von;

    if (file.is_open() ){ 
      file.seekg(currPos); // A currpos poziciora ugrom
      Seged seged;         // Fájl beolvasása egy segéd struktúrába 
      file >> seged.szam >> seged.indulo >> seged.veg >> seged.kocsidb >> seged.indulas >> seged.erkezes;
     
      // Setterek, mert a konstruktor nem akarta megenni
      von.setSzam(atoi(seged.szam));
      von.setIndulo(seged.indulo);
      von.setVeg(seged.veg);
      von.setKocsidb(atoi(seged.kocsidb));
      von.setIndulas(seged.indulas);
      von.setErkezes(seged.erkezes);

      // Mav classban helyet foglaló Vonatok* tömb 
      // feltöltése
      mav.feltolt(von);

      // Minden új sor kezdeténél meg kell álnom és el kell tárolnom
      // az éppenleges kurzor helyzetet, hogy a következő objektumba  
      // olvasás tudja hol kell folytatni. 
      char nextChar = file.peek(); 
      if (nextChar == '\n') { 
       currPos = file.tellg(); // Kurzor helyzete. 
      } // end of peek
    } // end of if

  file.close();
  return von; 
} // end of beolvas


// Vonatok hozzáadása
// @param currPos a streamben elfoglalt helyem
// @param minden-más a vonat class feltöltéséhez szükséges adatok
void addTrain(std::streampos& currPos, int szam, Allomas indulo, Allomas veg, int kocsidb, Ido indulas, Ido erkezes){
    const char* vonatok = "./input/vonatok.txt";    
    std::ofstream file (vonatok, std::ios::app); 
 
    // HIBAKEZELÉS IDE

    if(file.is_open()){
      file.seekp(currPos); // Megfelelő helyre ugrok
      
      file << szam << " " << indulo << " " << veg << " " << kocsidb << " "
           << indulas << " " << erkezes << std::endl;
    }
    file.close();
} // addTrain



int main(){
  // Itt tárolon hol vagyok a file-ban
  // Mind a beolvasás mind pedig az íráshoz KELL!
  std::streampos currPos;
  Mav mav;

  beolvas(currPos, mav);
  beolvas(currPos, mav);
  beolvas(currPos, mav);
  beolvas(currPos, mav);
    addTrain(currPos, 69, "Ecséd", "Bivalybaszod", 5, "0440", "0630");
    addTrain(currPos, 80, "Geci", "Nem-geci", 5, "0440", "0630");
  beolvas(currPos, mav);
  Vonat v = beolvas(currPos, mav);


  mav.kiir();
  mav.kiirAt(7);
  // Jegy j1(100, 400);
  // j1.nyomtat(v);
  



  
  return 0;
}
