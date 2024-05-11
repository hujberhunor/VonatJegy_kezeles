#include <iostream>
#include <fstream>

#include "./header/vonat.h"
#include "./header/allomas.h"

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
// Beolvaásás a file-ból 
// @param int& currPos a kurzor éppenleges helyzete a fileban. 
Vonat beolvas(std::streampos& currPos){
    const char* vonatok = "./input/vonatok.txt";    // const mert megadtam, hogy hol van és ehhez nem nyúlsz hozzá
    std::ifstream file (vonatok);                   // Megynitom a file-t
    Vonat von;

    if (file.is_open() ){ 
      // A currpos poziciora ugrom
      file.seekg(currPos);
      // Fájl beolvasása egy segéd struktúrába 
      Seged seged;
      file >> seged.szam >> seged.indulo >> seged.veg >> seged.kocsidb >> seged.indulas >> seged.erkezes;
     
      // Setterek, mert a konstruktor nem akarja megenni
      von.setSzam(atoi(seged.szam));
      von.setIndulo(seged.indulo);
      von.setVeg(seged.veg);
      von.setKocsidb(atoi(seged.kocsidb));
      von.setIndulas(seged.indulas);
      von.setErkezes(seged.erkezes);

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


void addTrain(std::streampos& currPos, int szam, Allomas indulo, Allomas veg, int kocsidb, Ido indulas, Ido erkezes){
    const char* vonatok = "./input/vonatok.txt";    
    std::ofstream file (vonatok, std::ios::app); 
  
    if(file.is_open()){
      file.seekp(currPos); // Megfelelő helyre ugrok
      
      file << szam << " " << indulo << " " << veg << " " << kocsidb << " "
           << indulas << " " << erkezes << std::endl;
      
      // currPos = file.tellp(); // A továbbiakban innen akarom folytatni. 
    }
    file.close();
} // addTrain



int main(){
  // Itt tárolon hol vagyok a file-ban
  // Mind a beolvasás mind pedig az íráshoz KELL!
  std::streampos currPos;

  beolvas(currPos).kiir(); std::cout << "---\n";
  beolvas(currPos).kiir(); std::cout << "---\n";
  beolvas(currPos).kiir(); std::cout << "---\n";
  beolvas(currPos).kiir(); std::cout << "---\n";
  addTrain(currPos, 69, "Ecséd", "Bivalybaszod", 5, "0440", "0630");
  beolvas(currPos).kiir(); std::cout << "---\n";
  
  return 0;
}
