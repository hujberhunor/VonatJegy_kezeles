/*
*
* TEST FILE
*
* */

#include "./header/gtest_lite.h"
#include "./header/vonat.h"
#include <sstream>

void test(){

  /// Vonat getterek, minden típusból egy db
  TEST(Vonat, getSzam){}ENDM
  TEST(Vonat, getIndulo){}ENDM
  TEST(Vonat, getIndulas){}ENDM
 
  // Vonat setter
  TEST(Vonat, setSzam){}ENDM
  TEST(Vonat, setSzam){}ENDM
  
  // MÉG NEM ÉRTETTEM MEG, HOGYAN MŰKÖDTEK A TESTFILEOK LABORON
  // ÍGY NEM LÁTTAM ÉRTELMÉT OLYAN KÓDOT BEMÁSOLNI AMIT NEM IS ÉRTEK
  // EZRÉT CSAK ILYEN TRIVIALITÁSOKAT TESZTELTEM.


} // end of test
//
int main() {
  test();
  return 0;
}
