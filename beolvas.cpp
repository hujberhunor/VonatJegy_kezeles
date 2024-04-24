#include <iostream>
#include <fstream>

#include "./header/vonat.h"
#include "./header/allomas.h"
#include "./header/string5.h"

static const int buffSize = 15;
// Nagyon fontos!!!
// Itt tárolon hol vagyok a file-ban
// Mind a beolvasás mind pedig az íráshoz KELL!
// // int currPos = 0;

struct Seged {
  char szam[buffSize];
  char indulo[buffSize];
  char veg[buffSize];
  char kocsidb[buffSize];
};

/* VONATOK FILE BEOLVASÁSA */
// Beolvaásás a file-ból 
// @param int& currPos a kurzor éppenleges helyzete a fileban. 
void beolvas(int& currPos, Vonat& v){
    const char* vonatok = "./input/vonatok.txt";    // const mert megadtam, hogy hol van és ehhez nem nyúlsz hozzá
    std::ifstream file (vonatok);                   // Megynitom a file-t

    if (file.is_open()){ 
      Seged adatok;
      
      file >> adatok.szam >> adatok.indulo >> adatok.veg >> adatok.kocsidb;
      // v.setSzam(std::atoi(adatok.szam));
      // v.setIndulo(adatok.indulo);
      // v.setVeg(adatok.veg);
      // v.setKocsidb(std::atoi(adatok.kocsidb));
    
      String s1(adatok.indulo, buffSize); 
        std::cout << "String " << s1 << '\n';
      String s2(adatok.veg, buffSize);
        std::cout << "String " << s2 << '\n';
      
      Allomas a1(s1);
        std::cout << "Allomas "<< a1 << '\n';
      Allomas a2(s2);


      Vonat v(std::atoi(adatok.szam), a1, a2, std::atoi(adatok.kocsidb));
        std::cout << "GECI "<< v.getIndulo() << '\n';

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

  Vonat v;
  beolvas(currPos, v);

  


  return 0;
}
