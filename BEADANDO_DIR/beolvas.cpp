#include <iostream>
#include <fstream>

#include "vonat.h"
#include "allomas.h"

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
Vonat beolvas(std::streampos& currPos, Vonat& v){
    const char* vonatok = "vonatok.txt";    // const mert megadtam, hogy hol van és ehhez nem nyúlsz hozzá
    std::ifstream file (vonatok);                   // Megynitom a file-t
    // Vonat v;

    if (file.is_open() ){ 
      // A currpos poziciora ugrom
      file.seekg(currPos);
      // Fájl beolvasása egy segéd struktúrába 
      Seged seged;
      file >> seged.szam >> seged.indulo >> seged.veg >> seged.kocsidb >> seged.indulas >> seged.erkezes;
     
      // Setterek, mert a konstruktor nem akarja megenni
      v.setSzam(atoi(seged.szam));
      v.setIndulo(seged.indulo);
      v.setVeg(seged.veg);
      v.setKocsidb(atoi(seged.kocsidb));
      v.setIndulas(seged.indulas);
      v.setErkezes(seged.erkezes);

      // Minden új sor kezdeténél meg kell álnom és el kell tárolnom
      // az éppenleges kurzor helyzetet, hogy a következő objektumba  
      // olvasás tudja hol kell folytatni. 
      char nextChar = file.peek(); 
      if (nextChar == '\n') { 
       currPos = file.tellg(); // Kurzor helyzete. 
      } // end of peek
    } // end of if

  file.close();
  return v; 
} // end of beolvas




void addTrain(std::streampos& currPos, int szam, Allomas indulo, Allomas veg, int kocsidb, Ido indulas, Ido erkezes){
    const char* vonatok = "./input/vonatok.txt";    
    std::ofstream file (vonatok, std::ios::app); 
  
    if(file.is_open()){
      file.seekp(currPos); // Megfelelő helyre ugrok
    //
      file << szam << " " << indulo << " " << veg << " " << kocsidb << " "
           << indulas << " " << erkezes << std::endl;

      std::cout << "Written into the file" << std::endl;

      
      currPos = file.tellp(); // A továbbiakban innen akarom folytatni. 
    }

    file.close();
}




int main(){
  // Itt tárolon hol vagyok a file-ban
  // Mind a beolvasás mind pedig az íráshoz KELL!
  // int currPos = 0;
  std::streampos currPos;
  Vonat v, v1, v2, v3;

  beolvas(currPos, v); v.kiir();
  beolvas(currPos, v1); v1.kiir();
  beolvas(currPos, v2); v2.kiir();
  addTrain(currPos, 69, "Ecséd", "Bivalybaszod", 5, "0440", "0630");
  beolvas(currPos, v3); v3.kiir();
  addTrain(currPos, 70, "Ecséd", "Bivalybaszod", 5, "0440", "0630");

  return 0;
}
