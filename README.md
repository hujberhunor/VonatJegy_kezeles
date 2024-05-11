Todo
- [] Beolvas buffer overload kezelés
    - MaxMéret, ha tulnő megkétszerezem?
- [] HIBAKEZELÉS, kivétekek dobálása
Vonat->Ido aggregációban. Ido megszűnik ha vonat megszűnik.
Same goes with Allomas és String

- Jegy és leszármazottjai template class?
- Allomasok lehetnek heterogé kollekciók?
- std::string / String osztály használata Allomas classban
- Allomas class hogyan kell megírnom a konstruktort, meghívja az allomas class deklaráláskor, vagy meg kell hívnom a konstruktortban. 



## Jegyzetek 

### Beolvasás B opció
```cpp
  /* TALÁN MÉG MŰKÖDHET CÍMŰ TÖRTÉNET  
    Vonat v;
    int szam, kocsidb;
    char indulo[15];
    char veg[15];

    while(file >> szam >> indulo >> veg >> kocsidb){
      v = Vonat(szam, indulo, veg, kocsidb);
    }
    // std::cout << szam << '\n';
    std::cout << indulo;
  */

```
