#include "gtest_lite.h"
#include "mav.h"
#include "vonat.h"
#include "allomas.h"
#include "ido.h"
#include "seged.h"

#include <sstream>
#include <fstream>
#include <string>

#include "test.h"
Mav mav;
/**
* TEST FILE
*/

/**
* MAV TEST
*/
void mav_test(){
  /// Mav def ctor test
  TEST(Mav, default ctor){
    Mav mav;
    // EXPECT_EQ(0, mav.getSize());
  } ENDM;
  
  /// Mav ctor test
  TEST(Mav, ctor){
    Mav mav(10);
    EXPECT_EQ(int(10), int(mav.getSize()));
  } ENDM; 
  
  /// Mav add() test default ctor
  TEST(Mav, default add()){
    Mav mav;
    Vonat v; // default ctor
    
    mav.add(v);
    EXPECT_EQ(size_t(1) , mav.getSize()); // növelte a méretét
    EXPECT_EQ(mav.getVonatAt(1).getSzam(), 0); // 1 mivel a getvonat i-1 el számol
  } ENDM;

  // Mav add test parraméteres ctor
  TEST(Mav, add()){
    Mav mav;
    Vonat vonat1(1, "Budapest", "Szeged", 10, Ido(8, 0), Ido(10, 0));
    Vonat vonat2(2, "Szeged", "Debrecen", 8, Ido(12, 0), Ido(14, 0));
    mav.add(vonat1);
    mav.add(vonat2);

    // EXPECT_EQ(mav.getSize(), 2);
    EXPECT_EQ(mav.getVonatAt(1).getSzam(), 1);
    EXPECT_EQ(mav.getVonatAt(2).getSzam(), 2);
  } ENDM; 

  // Nagyon sok helyről összeollózott teszt.
  /// addTrain metódust tesztel a mav classnak
  TEST(Mav, AddTrain()) {
    // Csinálok egy test file-t
    const char* testFile = "./test_vonatok.txt";
    std::ofstream file(testFile);
    file.close();
    
    // Inicializálás
    Mav mav;
    std::streampos currPos = 0; // Nullátol olvasson be. 
    Allomas indulo("Szeged");
    Allomas veg("Debrecen");
    Ido indulas(12, 0);
    Ido erkezes(14, 0);
    
    // Tényleges fv meghívása
    mav.addTrain(currPos, testFile, 2, indulo, veg, 8, indulas, erkezes);
 
    std::ifstream beolvasott("./test_vonatok.txt");
    std::stringstream buffer;
    buffer << beolvasott.rdbuf(); // ???, de működik
    beolvasott.close();
  
    std::string elvart = "2 Szeged Debrecen 8 1200 1400\n";
    EXPECT_EQ(buffer.str(),elvart);  

    // Megnyilkolom a teszt file-t
    std::remove("./test_vonatok.txt");
  } ENDM;

  /// Beolvas() teszt 
  /// Mav class beolvas() metódust tesztel
  TEST(Mav, Beolvas()) {
    // Mindenhonnan összeollózott, nincs konkrét forrás
    const char* test = "./test_vonatok.txt";
    std::ofstream file(test);
    file << "1 Budapest Szeged 10 0800 1000\n"
         << "2 Szeged Debrecen 8 1200 1400\n";
    file.close();

    Mav mav;
    mav.beolvas(test);
    EXPECT_EQ(mav.getSize(),size_t(2));
    EXPECT_EQ(mav.getVonatAt(1).getSzam(), 1);
    EXPECT_EQ(mav.getVonatAt(2).getSzam(), 2);

    std::remove("./test_vonatok.txt");
  } ENDM;

} // end of mav test


void vonat_test(){

  /// Vonat def ctor test
  TEST(Vonat, default ctor){
    Vonat v;
   
    EXPECT_EQ(0, v.getSzam());
    // EXPECT_EQ("", std::string(v.getIndulo().getAllomas()));
      
    

  } ENDM;

  /// Vonat ctor test
  TEST(Vonat, ctor){
    Vonat v(1, "Budapest", "Szeged", 10, Ido(8, 0), Ido(10, 0));
   
    EXPECT_EQ(1, v.getSzam());
    EXPECT_EQ(10, v.getKocsidb());
    EXPECT_EQ("Budapest", std::string(v.getIndulo().getAllomas()));

  } ENDM;

} // end of vonat test
