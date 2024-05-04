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
  char indulas[buffSize];
  char erkezes[buffSize];
};

/* VONATOK FILE BEOLVASÁSA */
// Beolvaásás a file-ból 
// @param int& currPos a kurzor éppenleges helyzete a fileban. 
Vonat beolvas(int& currPos, Vonat& v){
    const char* vonatok = "./input/vonatok.txt";    // const mert megadtam, hogy hol van és ehhez nem nyúlsz hozzá
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




void addTrain(int& currPos){
    const char* vonatok = "./input/vonatok.txt";    
    std::ofstream file (vonatok, std::ios::app); 
  
    if(file.is_open()){
      file.seekp(currPos); // Megfelelő helyre ugrok
        
      file << "123 betu betu 1 0000 1111";
      std::cout << "Write into the file" << std::endl;

      currPos = file.tellp();
      std::cout << currPos;
    }

    file.close();
}




int main(){
  // Itt tárolon hol vagyok a file-ban
  // Mind a beolvasás mind pedig az íráshoz KELL!
  int currPos = 0;
  Vonat v, v1, v2, v3;

  beolvas(currPos, v); v.kiir();
  beolvas(currPos, v1); v1.kiir();
  beolvas(currPos, v2); v2.kiir();
  addTrain(currPos);
  beolvas(currPos, v3); v3.kiir();
  addTrain(currPos);

  return 0;
}
