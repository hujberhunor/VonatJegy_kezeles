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
