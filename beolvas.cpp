#include <iostream>
#include <fstream>

#include "./header/vonat.h"

// Nagyon fontos!!!
// Itt tárolon hol vagyok a file-ban
// Mind a beolvasás mind pedig az íráshoz KELL!
// int currPos = 0;


/* VONATOK FILE BEOLVASÁSA */
// Beolvaásás a file-ból 
// @param int& currPos a kurzor éppenleges helyzete a fileban. 
void beolvas(int& currPos){
    // Input file-om
    // const mert megadtam, hogy hol van és ehhez nem nyúlsz hozzá
    const char* vonatok = "./input/vonatok.txt";

    std::ifstream file (vonatok);
    int counter = 0;
    char buffer[15]; // Székesfehérvár a leghosszabb magyar városnél 14 karakterrel

    if (file.is_open()){ 
      // Ahol az előző befejezte onnan folytatja az olvasást. 
      file.seekg(currPos);

      while(file >> buffer){ // Ameddig nyitva a file és értelmes adatot olvasok
        
        std::cout << buffer << ' ' << currPos  << '\n';
      

        // Egy vonat objektum egy vonatot tartalmazhaz csak. 
        // Minden új sor kezdeténél meg kell álnom és el kell tárolnom
        // az éppenleges kurzor helyzetet, hogy a következő objektumba olvasás 
        // tudja hol kell folytatni. 
        char nextChar = file.peek(); 
        if (nextChar == '\n') { 
          currPos = file.tellg(); // Kurzor helyzete. 
          break; 
        }
      } // end of while
      file.close();
    } // end of if
} // end of beolvas

int main(){
  int currPos = 0;
  Vonat v(000, "Budapest", "Debrecen", 5);

  beolvas(currPos);
  std::cout << "---\n";
  beolvas(currPos);
}
