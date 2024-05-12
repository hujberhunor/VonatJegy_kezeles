## Todo
- [] Beolvas buffer overload kezelés
    - MaxMéret, ha tulnő megkétszerezem?
- [] HIBAKEZELÉS, kivétekek dobálása
- [] HETEROGÉN KOLLEKCIÓ KELL!!!!
- [] Hogyan fog a user jegyet venni?




## Jegyzetek 
- Jegy és leszármazottjai template class?
- Allomasok lehetnek heterogé kollekciók?

```cpp

// Listaz minden vonatot
void listaz() {
  const char* vonatok = "./input/vonatok.txt";    
  std::ifstream file(vonatok);

  if (file.is_open()) {
    Seged seged;
    Vonat von;
    while (file >> seged.szam >> seged.indulo >> seged.veg >> seged.kocsidb >> seged.indulas >> seged.erkezes) {
        von.setSzam(atoi(seged.szam));
        von.setIndulo(seged.indulo);
        von.setVeg(seged.veg);
        von.setKocsidb(atoi(seged.kocsidb));
        von.setIndulas(seged.indulas);
        von.setErkezes(seged.erkezes);

        von.kiir();
        std::cout << "---\n";
    }
    file.close();
  } // end of if
} // end of liszaz


```
```cpp
/* VONATOK FILE BEOLVASÁSA */
// Beolvaásás a file-ból egy segéd strukturába, onnan pedig egy Vonat objektum feltöltés 
// @param int& currPos a kurzor éppenleges helyzete a fileban. 
// @param Mav& mav class feltöltéséhez szükséges 
// @return visszaad egy feltöltött Vonat objektumot
// Vonat beolvas(std::streampos& currPos, Mav& mav){
//     const char* vonatok = "./input/vonatok.txt";    // const mert megadtam, hogy hol van és ehhez nem nyúlsz hozzá
//     std::ifstream file (vonatok);                   // Megynitom a file-t
//     Vonat von;
//
//     if (file.is_open() ){ 
//       file.seekg(currPos); // A currpos poziciora ugrom
//       Seged seged;         // Fájl beolvasása egy segéd struktúrába 
//       file >> seged.szam >> seged.indulo >> seged.veg >> seged.kocsidb >> seged.indulas >> seged.erkezes;
//      
//       // Setterek, mert a konstruktor nem akarta megenni
//       von.setSzam(atoi(seged.szam));
//       von.setIndulo(seged.indulo);
//       von.setVeg(seged.veg);
//       von.setKocsidb(atoi(seged.kocsidb));
//       von.setIndulas(seged.indulas);
//       von.setErkezes(seged.erkezes);
//
//       // Mav classban helyet foglaló Vonatok* tömb 
//       // feltöltése
//       mav.feltolt(von);
//
//       // Minden új sor kezdeténél meg kell álnom és el kell tárolnom
//       // az éppenleges kurzor helyzetet, hogy a következő objektumba  
//       // olvasás tudja hol kell folytatni. 
//       char nextChar = file.peek(); 
//       if (nextChar == '\n') { 
//        currPos = file.tellg(); // Kurzor helyzete. 
//       } // end of peek
//     } // end of if
//
//   file.close();
//   return von; 
// } // end of beolvas
```
