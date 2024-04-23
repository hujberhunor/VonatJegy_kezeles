#include <iostream>
#include <fstream>
#include <cstring> // strcpy() miatt
#include <cstdlib> // atoi() miatt 

#include "vonatd.h"

// CURSOR POSITION
int currPos;

int beir(int szam, int kocsi){
  /* VONATOK FILEBA ÍRÁSA */
  std::ofstream file("vonatok.txt", std::ios::app); // Nem értem mi, de működik. 
  file.seekp(currPos); // Seekelek oda ahol a beolvasás befejeződött
  
  file << szam << ' ' << kocsi << '\n';
  currPos = file.tellp(); // A seekelés helyét állítom. Lehet hogy nem is szükséges.

  file.close();
  return 0;
}

int beolvas(){
    /* VONATOK FILE BEOLVASÁSA */
    std::ifstream file ("vonatok.txt");
    char buffer[10];
    int counter = 0; 
    Vonat v; // Paraméterként kellene megadni

    if (file.is_open()){
        while(file >> buffer){
            int tmp = std::atoi(buffer);
            if(counter % 3 == 0) v.szam = tmp;
            if(counter % 3 == 1) v.kocsi = tmp;
            if(counter % 3 == 2) v.ules = tmp; 
            counter++;
            currPos = file.tellg();
        }
      
     // std::cout << v.szam;  // DEBUG CUCOS
      file.close();
    }
  return 0;

}


int main(){
  beolvas();
  beir(123, 22);
}






 
