#ifndef STRING_H
#define STRING_H

#define ELKESZULT 10


#include <iostream>
#include <cstring>

// #ifndef MEMTRACE
// #error "definialja projekt szinten a MEMTARCE makrot!"
// #endif // MEMTRACE

class String {
    char *pData;        ///< pointer az adatra
    size_t len;         ///< hossz lezáró nulla nélkül
public:
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << '|' << std::endl;
    }

    /// Paraméter nélküli konstruktor:
    String() :len(0) {
      pData=new char[1];
      pData[0]='\0';
    }

    /// Sztring hosszát adja vissza.
    /// @return sztring tényleges hossza (lezáró nulla nélkül).
    size_t size() const { return len; }

    /// C-sztringet ad vissza
    /// @return pointer a tárolt, vagy azzal azonos tartalmú nullával lezárt sztring-re.
    const char* c_str() const { return pData;}

    // Konstruktorok
    String(char c);
    String(const char* str);
    String(const String& s0);
    // Konstruktort BUFFERBŐL
    String(char indulo[], int buffSize) {
        len = strnlen(indulo, buffSize); 
        pData = new char[len + 1]; 
        strncpy(pData, indulo, len);
        pData[len] = '\0'; 
    }

    // Operatorok
    String& operator=(const String &s0);
    String operator+ (const String &s0)const;
    String operator+ (char c)const;
    char& operator[] (size_t n)const;

    ~String();

}; /// Itt az osztály deklarációjának vége

/// Globális  
String operator+ (char c, String s0);
std::ostream& operator<< (std::ostream& os, String const s0);

#endif
