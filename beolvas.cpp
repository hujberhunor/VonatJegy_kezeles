#include <iostream>
#include <fstream>

#include "./header/vonat.h"
#include "./header/allomas.h"

static const int buffSize = 15;
// Nagyon fontos!!!
// Itt tárolon hol vagyok a file-ban
// Mind a beolvasás mind pedig az íráshoz KELL!
// // int currPos = 0;

struct Seged {
  char szam[15];
  char indulo[15];
  char veg[15];
  char kocsidb[15];
};

/* VONATOK FILE BEOLVASÁSA */
// Beolvaásás a file-ból 
// @param int& currPos a kurzor éppenleges helyzete a fileban. 
void beolvas(int& currPos, Vonat& v){
    const char* vonatok = "./input/vonatok.txt";    // const mert megadtam, hogy hol van és ehhez nem nyúlsz hozzá
    std::ifstream file (vonatok);                   // Megynitom a file-t
    char buffer[15];                                // Székesfehérvár a leghosszabb magyar városnél 14 karakterrel

    if (file.is_open()){ 

      Seged adatok;
      file >> adatok.szam >> adatok.indulo >> adatok.veg >> adatok.kocsidb;
      // v.setSzam(std::atoi(adatok.szam));
      // v.setIndulo(adatok.indulo);
      // v.setVeg(adatok.veg);
      // v.setKocsidb(std::atoi(adatok.kocsidb));
      Vonat(std::atoi(adatok.szam), adatok.indulo, adatok.veg, std::atoi(adatok.kocsidb));


      // // Ahol az előző befejezte onnan folytatja az olvasást. 
      // file.seekg(currPos);
      // 
      // file >> buffer;
      // v.setSzam(std::atoi(buffer));
      // 
      // file >> buffer;
      // v.setIndulo(buffer);
      //
      // file >> buffer;
      // v.setVeg(buffer);
      //
      // file >> buffer;
      // v.setKocsidb(std::atoi(buffer));
    //
    //   // std::cout << buffer << ' ' << currPos  << '\n'; // DEBUG print??
    //
    //   // Egy vonat objektum egy vonatot tartalmazhaz csak. 
    //   // Minden új sor kezdeténél meg kell álnom és el kell tárolnom
    //   // az éppenleges kurzor helyzetet, hogy a következő objektumba  
    //   // olvasás tudja hol kell folytatni. 
    //   char nextChar = file.peek(); 
    //   if (nextChar == '\n') { 
    //    currPos = file.tellg(); // Kurzor helyzete. 
    //     std::cout << "Végére értem\n"; 
    //   }
    } // end of if
  file.close();
} // end of beolvas

int main(){
  int currPos = 0;

  Vonat a;
  beolvas(currPos, a);
  // Ellenőrzés
  std::cout << "Szam: " << a.getSzam() << std::endl;
  std::cout << "Indulo: " << a.getIndulo() << std::endl;
  std::cout << "Veg: " << a.getVeg() << std::endl;
  std::cout << "Kocsidb: " << a.getKocsidb() << std::endl;

  return 0;
}
